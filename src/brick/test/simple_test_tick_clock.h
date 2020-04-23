// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_SIMPLE_TEST_TICK_CLOCK_H_
#define BRICK_TEST_SIMPLE_TEST_TICK_CLOCK_H_

#include "brick/compiler_specific.h"
#include "brick/synchronization/lock.h"
#include "brick/time/tick_clock.h"
#include "brick/time/time.h"

namespace base {

// SimpleTestTickClock is a TickClock implementation that gives
// control over the returned TimeTicks objects.  All methods may be
// called from any thread.
class SimpleTestTickClock : public TickClock {
 public:
  // Starts off with a clock set to TimeTicks().
  SimpleTestTickClock();
  ~SimpleTestTickClock() override;

  TimeTicks NowTicks() const override;

  // Advances the clock by |delta|, which must not be negative.
  void Advance(TimeDelta delta);

  // Sets the clock to the given time.
  void SetNowTicks(TimeTicks ticks);

 private:
  // Protects |now_ticks_|.
  mutable Lock lock_;

  TimeTicks now_ticks_;
};

}  // namespace base

#endif  // BRICK_TEST_SIMPLE_TEST_TICK_CLOCK_H_
