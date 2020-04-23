// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_PERF_TEST_SUITE_H_
#define BRICK_TEST_PERF_TEST_SUITE_H_

#include "brick/test/test_suite.h"

namespace base {

class PerfTestSuite : public TestSuite {
 public:
  PerfTestSuite(int argc, char** argv);

  void Initialize() override;
  void Shutdown() override;
};

}  // namespace base

#endif  // BRICK_TEST_PERF_TEST_SUITE_H_
