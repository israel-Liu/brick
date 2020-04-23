// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_MESSAGE_LOOP_MESSAGE_LOOP_TASK_RUNNER_H_
#define BRICK_MESSAGE_LOOP_MESSAGE_LOOP_TASK_RUNNER_H_

#include "brick/base_export.h"
#include "brick/callback.h"
#include "brick/macros.h"
#include "brick/memory/ref_counted.h"
#include "brick/pending_task.h"
#include "brick/single_thread_task_runner.h"
#include "brick/synchronization/lock.h"
#include "brick/threading/platform_thread.h"

namespace base {
namespace internal {

class IncomingTaskQueue;

// A stock implementation of SingleThreadTaskRunner that is created and managed
// by a MessageLoop. For now a MessageLoopTaskRunner can only be created as
// part of a MessageLoop.
class BRICK_EXPORT MessageLoopTaskRunner : public SingleThreadTaskRunner {
 public:
  explicit MessageLoopTaskRunner(
      scoped_refptr<IncomingTaskQueue> incoming_queue);

  // Initialize this message loop task runner on the current thread.
  void BindToCurrentThread();

  // SingleThreadTaskRunner implementation
  bool PostDelayedTask(const Location& from_here,
                       OnceClosure task,
                       TimeDelta delay) override;
  bool PostNonNestableDelayedTask(const Location& from_here,
                                  OnceClosure task,
                                  TimeDelta delay) override;
  bool RunsTasksInCurrentSequence() const override;

 private:
  friend class RefCountedThreadSafe<MessageLoopTaskRunner>;
  ~MessageLoopTaskRunner() override;

  // The incoming queue receiving all posted tasks.
  scoped_refptr<IncomingTaskQueue> incoming_queue_;

  // ID of the thread |this| was created on.  Could be accessed on multiple
  // threads, protected by |valid_thread_id_lock_|.
  PlatformThreadId valid_thread_id_;
  mutable Lock valid_thread_id_lock_;

  DISALLOW_COPY_AND_ASSIGN(MessageLoopTaskRunner);
};

}  // namespace internal
}  // namespace base

#endif  // BRICK_MESSAGE_LOOP_MESSAGE_LOOP_TASK_RUNNER_H_
