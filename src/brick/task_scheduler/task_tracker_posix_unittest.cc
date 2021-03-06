// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/task_scheduler/task_tracker_posix.h"

#include <unistd.h>

#include <utility>

#include "brick/bind.h"
#include "brick/bind_helpers.h"
#include "brick/files/file_descriptor_watcher_posix.h"
#include "brick/macros.h"
#include "brick/memory/ptr_util.h"
#include "brick/memory/ref_counted.h"
#include "brick/message_loop/message_loop.h"
#include "brick/posix/eintr_wrapper.h"
#include "brick/run_loop.h"
#include "brick/sequence_token.h"
#include "brick/task_scheduler/task.h"
#include "brick/task_scheduler/task_traits.h"
#include "brick/task_scheduler/test_utils.h"
#include "brick/test/null_task_runner.h"
#include "brick/threading/thread.h"
#include "brick/time/time.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace base {
namespace internal {

namespace {

class TaskSchedulerTaskTrackerPosixTest : public testing::Test {
 public:
  TaskSchedulerTaskTrackerPosixTest() : service_thread_("ServiceThread") {
    Thread::Options service_thread_options;
    service_thread_options.message_loop_type = MessageLoop::TYPE_IO;
    service_thread_.StartWithOptions(service_thread_options);
    tracker_.set_watch_file_descriptor_message_loop(
        static_cast<MessageLoopForIO*>(service_thread_.message_loop()));
  }

 protected:
  Thread service_thread_;
  TaskTrackerPosix tracker_ = {"Test"};

 private:
  DISALLOW_COPY_AND_ASSIGN(TaskSchedulerTaskTrackerPosixTest);
};

}  // namespace

// Verify that TaskTrackerPosix runs a Task it receives.
TEST_F(TaskSchedulerTaskTrackerPosixTest, RunTask) {
  bool did_run = false;
  Task task(FROM_HERE,
            Bind([](bool* did_run) { *did_run = true; }, Unretained(&did_run)),
            TaskTraits(), TimeDelta());

  EXPECT_TRUE(tracker_.WillPostTask(task));

  auto sequence = test::CreateSequenceWithTask(std::move(task));
  EXPECT_EQ(sequence, tracker_.WillScheduleSequence(sequence, nullptr));
  // Expect RunAndPopNextTask to return nullptr since |sequence| is empty after
  // popping a task from it.
  EXPECT_FALSE(tracker_.RunAndPopNextTask(sequence, nullptr));

  EXPECT_TRUE(did_run);
}

// Verify that FileDescriptorWatcher::WatchReadable() can be called from a task
// running in TaskTrackerPosix without a crash.
TEST_F(TaskSchedulerTaskTrackerPosixTest, FileDescriptorWatcher) {
  int fds[2];
  ASSERT_EQ(0, pipe(fds));
  Task task(FROM_HERE,
            Bind(IgnoreResult(&FileDescriptorWatcher::WatchReadable), fds[0],
                 DoNothing()),
            TaskTraits(), TimeDelta());
  // FileDescriptorWatcher::WatchReadable needs a SequencedTaskRunnerHandle.
  task.sequenced_task_runner_ref = MakeRefCounted<NullTaskRunner>();

  EXPECT_TRUE(tracker_.WillPostTask(task));

  auto sequence = test::CreateSequenceWithTask(std::move(task));
  EXPECT_EQ(sequence, tracker_.WillScheduleSequence(sequence, nullptr));
  // Expect RunAndPopNextTask to return nullptr since |sequence| is empty after
  // popping a task from it.
  EXPECT_FALSE(tracker_.RunAndPopNextTask(sequence, nullptr));

  // Join the service thread to make sure that the read watch is registered and
  // unregistered before file descriptors are closed.
  service_thread_.Stop();

  EXPECT_EQ(0, IGNORE_EINTR(close(fds[0])));
  EXPECT_EQ(0, IGNORE_EINTR(close(fds[1])));
}

}  // namespace internal
}  // namespace base
