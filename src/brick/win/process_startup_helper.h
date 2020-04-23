// Copyright (c) 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_WIN_PROCESS_STARTUP_HELPER_H_
#define BRICK_WIN_PROCESS_STARTUP_HELPER_H_

#include "brick/base_export.h"

namespace base {

class CommandLine;

namespace win {

// Register the invalid param handler and pure call handler to be able to
// notify breakpad when it happens.
BRICK_EXPORT void RegisterInvalidParamHandler();

// Sets up the CRT's debugging macros to output to stdout.
BRICK_EXPORT void SetupCRT(const CommandLine& command_line);

}  // namespace win
}  // namespace base

#endif  // BRICK_WIN_PROCESS_STARTUP_HELPER_H_
