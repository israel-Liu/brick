// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_MOCK_DEVICES_CHANGED_OBSERVER_H_
#define BRICK_TEST_MOCK_DEVICES_CHANGED_OBSERVER_H_

#include <string>

#include "brick/macros.h"
#include "brick/system_monitor/system_monitor.h"
#include "testing/gmock/include/gmock/gmock.h"

namespace base {

class MockDevicesChangedObserver
    : public base::SystemMonitor::DevicesChangedObserver {
 public:
  MockDevicesChangedObserver();
  ~MockDevicesChangedObserver() override;

  MOCK_METHOD1(OnDevicesChanged,
               void(base::SystemMonitor::DeviceType device_type));

 private:
  DISALLOW_COPY_AND_ASSIGN(MockDevicesChangedObserver);
};

}  // namespace base

#endif  // BRICK_TEST_MOCK_DEVICES_CHANGED_OBSERVER_H_
