// Copyright 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_MESSAGE_LOOP_MESSAGE_PUMP_IO_IOS_H_
#define BRICK_MESSAGE_LOOP_MESSAGE_PUMP_IO_IOS_H_

#include "brick/base_export.h"
#include "brick/mac/scoped_cffiledescriptorref.h"
#include "brick/mac/scoped_cftyperef.h"
#include "brick/macros.h"
#include "brick/memory/ref_counted.h"
#include "brick/memory/weak_ptr.h"
#include "brick/message_loop/message_pump_mac.h"
#include "brick/message_loop/watchable_io_message_pump_posix.h"
#include "brick/threading/thread_checker.h"

namespace base {

// This file introduces a class to monitor sockets and issue callbacks when
// sockets are ready for I/O on iOS.
class BRICK_EXPORT MessagePumpIOSForIO : public MessagePumpNSRunLoop,
                                        public WatchableIOMessagePumpPosix {
 public:
  class FdWatchController : public FdWatchControllerInterface {
   public:
    explicit FdWatchController(const Location& from_here);

    // Implicitly calls StopWatchingFileDescriptor.
    ~FdWatchController() override;

    // FdWatchControllerInterface:
    bool StopWatchingFileDescriptor() override;

   private:
    friend class MessagePumpIOSForIO;
    friend class MessagePumpIOSForIOTest;

    // Called by MessagePumpIOSForIO, ownership of |fdref| and |fd_source|
    // is transferred to this object.
    void Init(CFFileDescriptorRef fdref,
              CFOptionFlags callback_types,
              CFRunLoopSourceRef fd_source,
              bool is_persistent);

    void set_pump(base::WeakPtr<MessagePumpIOSForIO> pump) { pump_ = pump; }
    const base::WeakPtr<MessagePumpIOSForIO>& pump() const { return pump_; }

    void set_watcher(FdWatcher* watcher) { watcher_ = watcher; }

    void OnFileCanReadWithoutBlocking(int fd, MessagePumpIOSForIO* pump);
    void OnFileCanWriteWithoutBlocking(int fd, MessagePumpIOSForIO* pump);

    bool is_persistent_ = false;  // false if this event is one-shot.
    base::mac::ScopedCFFileDescriptorRef fdref_;
    CFOptionFlags callback_types_ = 0;
    base::ScopedCFTypeRef<CFRunLoopSourceRef> fd_source_;
    base::WeakPtr<MessagePumpIOSForIO> pump_;
    FdWatcher* watcher_ = nullptr;

    DISALLOW_COPY_AND_ASSIGN(FdWatchController);
  };

  MessagePumpIOSForIO();
  ~MessagePumpIOSForIO() override;

  bool WatchFileDescriptor(int fd,
                           bool persistent,
                           int mode,
                           FdWatchController* controller,
                           FdWatcher* delegate);

  void RemoveRunLoopSource(CFRunLoopSourceRef source);

 private:
  friend class MessagePumpIOSForIOTest;

  static void HandleFdIOEvent(CFFileDescriptorRef fdref,
                              CFOptionFlags callback_types,
                              void* context);

  ThreadChecker watch_file_descriptor_caller_checker_;

  base::WeakPtrFactory<MessagePumpIOSForIO> weak_factory_;

  DISALLOW_COPY_AND_ASSIGN(MessagePumpIOSForIO);
};

}  // namespace base

#endif  // BRICK_MESSAGE_LOOP_MESSAGE_PUMP_IO_IOS_H_
