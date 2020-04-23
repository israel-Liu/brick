// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/test/power_monitor_test_base.h"

#include "brick/message_loop/message_loop.h"
#include "brick/message_loop/message_loop_current.h"
#include "brick/power_monitor/power_monitor.h"
#include "brick/power_monitor/power_monitor_source.h"
#include "brick/run_loop.h"

namespace base {

PowerMonitorTestSource::PowerMonitorTestSource()
    : test_on_battery_power_(false) {
  DCHECK(MessageLoopCurrent::Get())
      << "PowerMonitorTestSource requires a MessageLoop.";
}

PowerMonitorTestSource::~PowerMonitorTestSource() = default;

void PowerMonitorTestSource::GeneratePowerStateEvent(bool on_battery_power) {
  test_on_battery_power_ = on_battery_power;
  ProcessPowerEvent(POWER_STATE_EVENT);
  RunLoop().RunUntilIdle();
}

void PowerMonitorTestSource::GenerateSuspendEvent() {
  ProcessPowerEvent(SUSPEND_EVENT);
  RunLoop().RunUntilIdle();
}

void PowerMonitorTestSource::GenerateResumeEvent() {
  ProcessPowerEvent(RESUME_EVENT);
  RunLoop().RunUntilIdle();
}

bool PowerMonitorTestSource::IsOnBatteryPowerImpl() {
  return test_on_battery_power_;
};

PowerMonitorTestObserver::PowerMonitorTestObserver()
    : last_power_state_(false),
      power_state_changes_(0),
      suspends_(0),
      resumes_(0) {
}

PowerMonitorTestObserver::~PowerMonitorTestObserver() = default;

// PowerObserver callbacks.
void PowerMonitorTestObserver::OnPowerStateChange(bool on_battery_power) {
  last_power_state_ = on_battery_power;
  power_state_changes_++;
}

void PowerMonitorTestObserver::OnSuspend() {
  suspends_++;
}

void PowerMonitorTestObserver::OnResume() {
  resumes_++;
}

}  // namespace base
