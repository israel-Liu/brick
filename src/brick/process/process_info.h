// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_PROCESS_PROCESS_INFO_H_
#define BRICK_PROCESS_PROCESS_INFO_H_

#include "brick/base_export.h"
#include "build/build_config.h"

namespace base {

class Time;

// Vends information about the current process.
class BRICK_EXPORT CurrentProcessInfo {
 public:
  // Returns the time at which the process was launched. May be empty if an
  // error occurred retrieving the information.
  static const Time CreationTime();
};

#if defined(OS_WIN)
enum IntegrityLevel {
  INTEGRITY_UNKNOWN,
  LOW_INTEGRITY,
  MEDIUM_INTEGRITY,
  HIGH_INTEGRITY,
};

// Returns the integrity level of the process. Returns INTEGRITY_UNKNOWN in the
// case of an underlying system failure.
BRICK_EXPORT IntegrityLevel GetCurrentProcessIntegrityLevel();

// Determines whether the current process is elevated.
BRICK_EXPORT bool IsCurrentProcessElevated();

#endif  // defined(OS_WIN)

}  // namespace base

#endif  // BRICK_PROCESS_PROCESS_INFO_H_
