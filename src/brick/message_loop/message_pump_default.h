// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_MESSAGE_LOOP_MESSAGE_PUMP_DEFAULT_H_
#define BRICK_MESSAGE_LOOP_MESSAGE_PUMP_DEFAULT_H_

#include "brick/base_export.h"
#include "brick/macros.h"
#include "brick/message_loop/message_pump.h"
#include "brick/synchronization/waitable_event.h"
#include "brick/time/time.h"
#include "build/build_config.h"

namespace base {

class BRICK_EXPORT MessagePumpDefault : public MessagePump {
 public:
  MessagePumpDefault();
  ~MessagePumpDefault() override;

  // MessagePump methods:
  void Run(Delegate* delegate) override;
  void Quit() override;
  void ScheduleWork() override;
  void ScheduleDelayedWork(const TimeTicks& delayed_work_time) override;
#if defined(OS_MACOSX)
  void SetTimerSlack(TimerSlack timer_slack) override;
#endif

 private:
  // This flag is set to false when Run should return.
  bool keep_running_;

  // Used to sleep until there is more work to do.
  WaitableEvent event_;

  // The time at which we should call DoDelayedWork.
  TimeTicks delayed_work_time_;

  DISALLOW_COPY_AND_ASSIGN(MessagePumpDefault);
};

}  // namespace base

#endif  // BRICK_MESSAGE_LOOP_MESSAGE_PUMP_DEFAULT_H_
