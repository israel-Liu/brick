// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_POWER_MONITOR_POWER_OBSERVER_H_
#define BRICK_POWER_MONITOR_POWER_OBSERVER_H_

#include "brick/base_export.h"
#include "brick/compiler_specific.h"

namespace base {

class BRICK_EXPORT PowerObserver {
 public:
  // Notification of a change in power status of the computer, such
  // as from switching between battery and A/C power.
  virtual void OnPowerStateChange(bool on_battery_power) {};

  // Notification that the system is suspending.
  virtual void OnSuspend() {}

  // Notification that the system is resuming.
  virtual void OnResume() {}

 protected:
  virtual ~PowerObserver() = default;
};

}  // namespace base

#endif  // BRICK_POWER_MONITOR_POWER_OBSERVER_H_
