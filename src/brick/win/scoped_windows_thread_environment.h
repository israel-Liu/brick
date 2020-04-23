// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_WIN_SCOPED_WINDOWS_THREAD_ENVIRONMENT_H_
#define BRICK_WIN_SCOPED_WINDOWS_THREAD_ENVIRONMENT_H_

#include "brick/macros.h"

namespace base {
namespace win {

// Serves as a root class for ScopedCOMInitializer and ScopedWinrtInitializer.
class ScopedWindowsThreadEnvironment {
 public:
  ScopedWindowsThreadEnvironment() {}
  virtual ~ScopedWindowsThreadEnvironment() {}

  virtual bool Succeeded() const = 0;

 private:
  DISALLOW_COPY_AND_ASSIGN(ScopedWindowsThreadEnvironment);
};

}  // namespace win
}  // namespace base

#endif  // BRICK_WIN_SCOPED_WINDOWS_THREAD_ENVIRONMENT_H_
