// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_THREADING_THREAD_CHECKER_IMPL_H_
#define BRICK_THREADING_THREAD_CHECKER_IMPL_H_

#include "brick/base_export.h"
#include "brick/compiler_specific.h"
#include "brick/sequence_token.h"
#include "brick/synchronization/lock.h"
#include "brick/threading/platform_thread.h"

namespace base {

// Real implementation of ThreadChecker, for use in debug mode, or for temporary
// use in release mode (e.g. to CHECK on a threading issue seen only in the
// wild).
//
// Note: You should almost always use the ThreadChecker class to get the right
// version for your build configuration.
class BRICK_EXPORT ThreadCheckerImpl {
 public:
  ThreadCheckerImpl();
  ~ThreadCheckerImpl();

  bool CalledOnValidThread() const WARN_UNUSED_RESULT;

  // Changes the thread that is checked for in CalledOnValidThread.  This may
  // be useful when an object may be created on one thread and then used
  // exclusively on another thread.
  void DetachFromThread();

 private:
  void EnsureAssigned() const;

  // Members are mutable so that CalledOnValidThread() can set them.

  // Synchronizes access to all members.
  mutable base::Lock lock_;

  // Thread on which CalledOnValidThread() may return true.
  mutable PlatformThreadRef thread_id_;

  // TaskToken for which CalledOnValidThread() always returns true. This allows
  // CalledOnValidThread() to return true when called multiple times from the
  // same task, even if it's not running in a single-threaded context itself
  // (allowing usage of ThreadChecker objects on the stack in the scope of one-
  // off tasks). Note: CalledOnValidThread() may return true even if the current
  // TaskToken is not equal to this.
  mutable TaskToken task_token_;

  // SequenceToken for which CalledOnValidThread() may return true. Used to
  // ensure that CalledOnValidThread() doesn't return true for TaskScheduler
  // tasks that happen to run on the same thread but weren't posted to the same
  // SingleThreadTaskRunner.
  mutable SequenceToken sequence_token_;
};

}  // namespace base

#endif  // BRICK_THREADING_THREAD_CHECKER_IMPL_H_
