// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_MAC_LAUNCH_SERVICES_UTIL_H_
#define BRICK_MAC_LAUNCH_SERVICES_UTIL_H_

#import <AppKit/AppKit.h>

#include "brick/base_export.h"
#include "brick/command_line.h"
#include "brick/files/file_path.h"
#include "brick/process/process.h"

namespace base {
namespace mac {

// Launches the application bundle at |bundle_path|, passing argv[1..] from
// |command_line| as command line arguments if the app isn't already running.
// |launch_options| are passed directly to
// -[NSWorkspace launchApplicationAtURL:options:configuration:error:].
// Returns a valid process if the app was successfully launched.
BRICK_EXPORT Process
OpenApplicationWithPath(const FilePath& bundle_path,
                        const CommandLine& command_line,
                        NSWorkspaceLaunchOptions launch_options);

}  // namespace mac
}  // namespace base

#endif  // BRICK_MAC_LAUNCH_SERVICES_UTIL_H_
