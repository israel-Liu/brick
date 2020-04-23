// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/bind.h"
#include "brick/test/launcher/unit_test_launcher.h"
#include "brick/test/test_suite.h"
#include "build/build_config.h"

int main(int argc, char** argv) {
  base::TestSuite test_suite(argc, argv);
  return base::LaunchUnitTests(
      argc, argv,
      base::BindOnce(&base::TestSuite::Run, base::Unretained(&test_suite)));
}
