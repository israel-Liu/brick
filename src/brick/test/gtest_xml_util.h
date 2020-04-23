// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_GTEST_XML_UTIL_H_
#define BRICK_TEST_GTEST_XML_UTIL_H_

#include <vector>

#include "brick/compiler_specific.h"

namespace base {

class FilePath;
struct TestResult;

// Produces a vector of test results based on GTest output file.
// Returns true iff the output file exists and has been successfully parsed.
// On successful return |crashed| is set to true if the test results
// are valid but incomplete.
bool ProcessGTestOutput(const base::FilePath& output_file,
                        std::vector<TestResult>* results,
                        bool* crashed) WARN_UNUSED_RESULT;

}  // namespace base

#endif  // BRICK_TEST_GTEST_XML_UTIL_H_
