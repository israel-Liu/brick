// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_PENDING_TASK_H_
#define BRICK_PENDING_TASK_H_

#include <array>

#include "brick/base_export.h"
#include "brick/callback.h"
#include "brick/containers/queue.h"
#include "brick/location.h"
#include "brick/time/time.h"

namespace base {

enum class Nestable {
  kNonNestable,
  kNestable,
};

// Contains data about a pending task. Stored in TaskQueue and DelayedTaskQueue
// for use by classes that queue and execute tasks.
struct BRICK_EXPORT PendingTask {
  PendingTask(const Location& posted_from,
              OnceClosure task,
              TimeTicks delayed_run_time = TimeTicks(),
              Nestable nestable = Nestable::kNestable);
  PendingTask(PendingTask&& other);
  ~PendingTask();

  PendingTask& operator=(PendingTask&& other);

  // Used to support sorting.
  bool operator<(const PendingTask& other) const;

  // The task to run.
  OnceClosure task;

  // The site this PendingTask was posted from.
  Location posted_from;

  // The time when the task should be run.
  base::TimeTicks delayed_run_time;

  // Task backtrace. mutable so it can be set while annotating const PendingTask
  // objects from TaskAnnotator::DidQueueTask().
  mutable std::array<const void*, 4> task_backtrace = {};

  // Secondary sort key for run time.
  int sequence_num = 0;

  // OK to dispatch from a nested loop.
  Nestable nestable;

  // Needs high resolution timers.
  bool is_high_res = false;
};

using TaskQueue = base::queue<PendingTask>;

// PendingTasks are sorted by their |delayed_run_time| property.
using DelayedTaskQueue = std::priority_queue<base::PendingTask>;

}  // namespace base

#endif  // BRICK_PENDING_TASK_H_
