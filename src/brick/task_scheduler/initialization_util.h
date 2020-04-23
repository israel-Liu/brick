// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TASK_SCHEDULER_INITIALIZATION_UTIL_H_
#define BRICK_TASK_SCHEDULER_INITIALIZATION_UTIL_H_

#include "brick/base_export.h"

namespace base {

// Computes a value that may be used as the maximum number of threads in a
// TaskScheduler pool. Developers may use other methods to choose this maximum.
BRICK_EXPORT int RecommendedMaxNumberOfThreadsInPool(int min,
                                                    int max,
                                                    double cores_multiplier,
                                                    int offset);

}  // namespace base

#endif  // BRICK_TASK_SCHEDULER_INITIALIZATION_UTIL_H_
