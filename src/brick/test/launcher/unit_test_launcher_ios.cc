// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/test/launcher/unit_test_launcher.h"

#include "brick/command_line.h"
#include "brick/files/file_path.h"
#include "brick/files/file_util.h"
#include "brick/logging.h"
#include "brick/mac/foundation_util.h"
#include "brick/test/gtest_util.h"
#include "brick/test/test_switches.h"

namespace base {

int LaunchUnitTests(int argc,
                    char** argv,
                    RunTestSuiteCallback run_test_suite) {
  CHECK(CommandLine::InitializedForCurrentProcess() ||
        CommandLine::Init(argc, argv));
  const CommandLine* command_line = CommandLine::ForCurrentProcess();
  if (command_line->HasSwitch(switches::kTestLauncherListTests)) {
    FilePath list_path(command_line->GetSwitchValuePath(
        switches::kTestLauncherListTests));
    if (WriteCompiledInTestsToFile(list_path)) {
      return 0;
    } else {
      LOG(ERROR) << "Failed to write list of tests.";
      return 1;
    }
  } else if (command_line->HasSwitch(
                 switches::kTestLauncherPrintWritablePath)) {
    fprintf(stdout, "%s", mac::GetUserLibraryPath().value().c_str());
    fflush(stdout);
    return 0;
  }

  return std::move(run_test_suite).Run();
}

}  // namespace base
