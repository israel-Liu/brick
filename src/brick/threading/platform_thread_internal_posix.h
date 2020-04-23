// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_THREADING_PLATFORM_THREAD_INTERNAL_POSIX_H_
#define BRICK_THREADING_PLATFORM_THREAD_INTERNAL_POSIX_H_

#include "brick/base_export.h"
#include "brick/threading/platform_thread.h"

namespace base {

namespace internal {

struct ThreadPriorityToNiceValuePair {
  ThreadPriority priority;
  int nice_value;
};
// The elements must be listed in the order of increasing priority (lowest
// priority first), that is, in the order of decreasing nice values (highest
// nice value first).
BRICK_EXPORT extern
const ThreadPriorityToNiceValuePair kThreadPriorityToNiceValueMap[4];

// Returns the nice value matching |priority| based on the platform-specific
// implementation of kThreadPriorityToNiceValueMap.
int ThreadPriorityToNiceValue(ThreadPriority priority);

// Returns the ThreadPrioirty matching |nice_value| based on the platform-
// specific implementation of kThreadPriorityToNiceValueMap.
BRICK_EXPORT ThreadPriority NiceValueToThreadPriority(int nice_value);

// Allows platform specific tweaks to the generic POSIX solution for
// SetCurrentThreadPriority. Returns true if the platform-specific
// implementation handled this |priority| change, false if the generic
// implementation should instead proceed.
bool SetCurrentThreadPriorityForPlatform(ThreadPriority priority);

// Returns true if there is a platform-specific ThreadPriority set on the
// current thread (and returns the actual ThreadPriority via |priority|).
// Returns false otherwise, leaving |priority| untouched.
bool GetCurrentThreadPriorityForPlatform(ThreadPriority* priority);

}  // namespace internal

}  // namespace base

#endif  // BRICK_THREADING_PLATFORM_THREAD_INTERNAL_POSIX_H_
