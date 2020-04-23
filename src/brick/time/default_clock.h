// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TIME_DEFAULT_CLOCK_H_
#define BRICK_TIME_DEFAULT_CLOCK_H_

#include "brick/base_export.h"
#include "brick/compiler_specific.h"
#include "brick/time/clock.h"

namespace base {

// DefaultClock is a Clock implementation that uses Time::Now().
class BRICK_EXPORT DefaultClock : public Clock {
 public:
  ~DefaultClock() override;

  // Simply returns Time::Now().
  Time Now() const override;

  // Returns a shared instance of DefaultClock. This is thread-safe.
  static DefaultClock* GetInstance();
};

}  // namespace base

#endif  // BRICK_TIME_DEFAULT_CLOCK_H_
