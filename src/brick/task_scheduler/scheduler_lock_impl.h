// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TASK_SCHEDULER_SCHEDULER_LOCK_IMPL_H
#define BRICK_TASK_SCHEDULER_SCHEDULER_LOCK_IMPL_H

#include <memory>

#include "brick/base_export.h"
#include "brick/macros.h"
#include "brick/synchronization/lock.h"

namespace base {

class ConditionVariable;

namespace internal {

// A regular lock with simple deadlock correctness checking.
// This lock tracks all of the available locks to make sure that any locks are
// acquired in an expected order.
// See scheduler_lock.h for details.
class BRICK_EXPORT SchedulerLockImpl {
 public:
  SchedulerLockImpl();
  explicit SchedulerLockImpl(const SchedulerLockImpl* predecessor);
  ~SchedulerLockImpl();

  void Acquire();
  void Release();

  void AssertAcquired() const;

  std::unique_ptr<ConditionVariable> CreateConditionVariable();

 private:
  Lock lock_;

  DISALLOW_COPY_AND_ASSIGN(SchedulerLockImpl);
};

}  // namespace internal
}  // namespace base

#endif  // BRICK_TASK_SCHEDULER_SCHEDULER_LOCK_IMPL_H
