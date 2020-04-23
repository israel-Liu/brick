// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TASK_SCHEDULER_SEQUENCE_SORT_KEY_H_
#define BRICK_TASK_SCHEDULER_SEQUENCE_SORT_KEY_H_

#include "brick/base_export.h"
#include "brick/task_scheduler/task_traits.h"
#include "brick/time/time.h"

namespace base {
namespace internal {

// An immutable but assignable representation of the priority of a Sequence.
class BRICK_EXPORT SequenceSortKey final {
 public:
  SequenceSortKey(TaskPriority priority, TimeTicks next_task_sequenced_time);

  TaskPriority priority() const { return priority_; }
  TimeTicks next_task_sequenced_time() const {
    return next_task_sequenced_time_;
  }

  bool operator<(const SequenceSortKey& other) const;
  bool operator>(const SequenceSortKey& other) const { return other < *this; }

  bool operator==(const SequenceSortKey& other) const {
    return priority_ == other.priority_ &&
           next_task_sequenced_time_ == other.next_task_sequenced_time_;
  }
  bool operator!=(const SequenceSortKey& other) const {
    return !(other == *this);
  };

 private:
  // The private section allows this class to keep its immutable property while
  // being copy-assignable (i.e. instead of making its members const).

  // Highest task priority in the sequence at the time this sort key was
  // created.
  TaskPriority priority_;

  // Sequenced time of the next task to run in the sequence at the time this
  // sort key was created.
  TimeTicks next_task_sequenced_time_;
};

}  // namespace internal
}  // namespace base

#endif  // BRICK_TASK_SCHEDULER_SEQUENCE_SORT_KEY_H_
