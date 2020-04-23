// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/test/scoped_mock_time_message_loop_task_runner.h"

#include "brick/bind.h"
#include "brick/logging.h"
#include "brick/message_loop/message_loop_current.h"
#include "brick/run_loop.h"
#include "brick/test/test_pending_task.h"
#include "brick/threading/thread_task_runner_handle.h"
#include "brick/time/time.h"

namespace base {

ScopedMockTimeMessageLoopTaskRunner::ScopedMockTimeMessageLoopTaskRunner()
    : task_runner_(new TestMockTimeTaskRunner),
      previous_task_runner_(ThreadTaskRunnerHandle::Get()) {
  DCHECK(MessageLoopCurrent::Get());
  // To ensure that we process any initialization tasks posted to the
  // MessageLoop by a test fixture before replacing its TaskRunner.
  RunLoop().RunUntilIdle();
  MessageLoopCurrent::Get()->SetTaskRunner(task_runner_);
}

ScopedMockTimeMessageLoopTaskRunner::~ScopedMockTimeMessageLoopTaskRunner() {
  DCHECK(previous_task_runner_->RunsTasksInCurrentSequence());
  DCHECK_EQ(task_runner_, ThreadTaskRunnerHandle::Get());
  for (auto& pending_task : task_runner_->TakePendingTasks()) {
    previous_task_runner_->PostDelayedTask(
        pending_task.location, std::move(pending_task.task),
        pending_task.GetTimeToRun() - task_runner_->NowTicks());
  }
  MessageLoopCurrent::Get()->SetTaskRunner(std::move(previous_task_runner_));
}

}  // namespace base
