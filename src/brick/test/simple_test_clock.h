// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_SIMPLE_TEST_CLOCK_H_
#define BRICK_TEST_SIMPLE_TEST_CLOCK_H_

#include "brick/compiler_specific.h"
#include "brick/synchronization/lock.h"
#include "brick/time/clock.h"
#include "brick/time/time.h"

namespace base {

// SimpleTestClock is a Clock implementation that gives control over
// the returned Time objects.  All methods may be called from any
// thread.
class SimpleTestClock : public Clock {
 public:
  // Starts off with a clock set to Time().
  SimpleTestClock();
  ~SimpleTestClock() override;

  Time Now() const override;

  // Advances the clock by |delta|.
  void Advance(TimeDelta delta);

  // Sets the clock to the given time.
  void SetNow(Time now);

 private:
  // Protects |now_|.
  mutable Lock lock_;

  Time now_;
};

}  // namespace base

#endif  // BRICK_TEST_SIMPLE_TEST_CLOCK_H_
