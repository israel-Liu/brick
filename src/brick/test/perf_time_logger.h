// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_PERF_TIME_LOGGER_H_
#define BRICK_TEST_PERF_TIME_LOGGER_H_

#include <string>

#include "brick/macros.h"
#include "brick/timer/elapsed_timer.h"

namespace base {

// Automates calling LogPerfResult for the common case where you want
// to measure the time that something took. Call Done() when the test
// is complete if you do extra work after the test or there are stack
// objects with potentially expensive constructors. Otherwise, this
// class with automatically log on destruction.
class PerfTimeLogger {
 public:
  explicit PerfTimeLogger(const char* test_name);
  ~PerfTimeLogger();

  void Done();

 private:
  bool logged_;
  std::string test_name_;
  ElapsedTimer timer_;

  DISALLOW_COPY_AND_ASSIGN(PerfTimeLogger);
};

}  // namespace base

#endif  // BRICK_TEST_PERF_TIME_LOGGER_H_
