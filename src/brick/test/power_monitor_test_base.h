// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_POWER_MONITOR_TEST_BRICK_H_
#define BRICK_TEST_POWER_MONITOR_TEST_BRICK_H_

#include "brick/power_monitor/power_monitor.h"
#include "brick/power_monitor/power_monitor_source.h"

namespace base {

class PowerMonitorTestSource : public PowerMonitorSource {
 public:
  PowerMonitorTestSource();
  ~PowerMonitorTestSource() override;

  void GeneratePowerStateEvent(bool on_battery_power);
  void GenerateSuspendEvent();
  void GenerateResumeEvent();

 protected:
  bool IsOnBatteryPowerImpl() override;

  bool test_on_battery_power_;
};

class PowerMonitorTestObserver : public PowerObserver {
 public:
  PowerMonitorTestObserver();
  ~PowerMonitorTestObserver() override;

  // PowerObserver callbacks.
  void OnPowerStateChange(bool on_battery_power) override;
  void OnSuspend() override;
  void OnResume() override;

  // Test status counts.
  bool last_power_state() { return last_power_state_; }
  int power_state_changes() { return power_state_changes_; }
  int suspends() { return suspends_; }
  int resumes() { return resumes_; }

 private:
  bool last_power_state_; // Last power state we were notified of.
  int power_state_changes_;  // Count of OnPowerStateChange notifications.
  int suspends_;  // Count of OnSuspend notifications.
  int resumes_;  // Count of OnResume notifications.
};

}  // namespace base

#endif  // BRICK_TEST_POWER_MONITOR_TEST_BRICK_H_
