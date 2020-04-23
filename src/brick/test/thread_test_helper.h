// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_THREAD_TEST_HELPER_H_
#define BRICK_TEST_THREAD_TEST_HELPER_H_

#include "brick/compiler_specific.h"
#include "brick/macros.h"
#include "brick/memory/ref_counted.h"
#include "brick/sequenced_task_runner.h"
#include "brick/synchronization/waitable_event.h"

namespace base {

// Helper class that executes code on a given target sequence/thread while
// blocking on the invoking sequence/thread. To use, derive from this class and
// overwrite RunTest. An alternative use of this class is to use it directly. It
// will then block until all pending tasks on a given sequence/thread have been
// executed.
class ThreadTestHelper : public RefCountedThreadSafe<ThreadTestHelper> {
 public:
  explicit ThreadTestHelper(scoped_refptr<SequencedTaskRunner> target_sequence);

  // True if RunTest() was successfully executed on the target sequence.
  bool Run() WARN_UNUSED_RESULT;

  virtual void RunTest();

 protected:
  friend class RefCountedThreadSafe<ThreadTestHelper>;

  virtual ~ThreadTestHelper();

  // Use this method to store the result of RunTest().
  void set_test_result(bool test_result) { test_result_ = test_result; }

 private:
  void RunOnSequence();

  bool test_result_;
  scoped_refptr<SequencedTaskRunner> target_sequence_;
  WaitableEvent done_event_;

  DISALLOW_COPY_AND_ASSIGN(ThreadTestHelper);
};

}  // namespace base

#endif  // BRICK_TEST_THREAD_TEST_HELPER_H_
