// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_WIN_STARTUP_INFORMATION_H_
#define BRICK_WIN_STARTUP_INFORMATION_H_

#include <windows.h>
#include <stddef.h>

#include "brick/base_export.h"
#include "brick/macros.h"

namespace base {
namespace win {

// Manages the lifetime of additional attributes in STARTUPINFOEX.
class BRICK_EXPORT StartupInformation {
 public:
  StartupInformation();

  ~StartupInformation();

  // Initialize the attribute list for the specified number of entries.
  bool InitializeProcThreadAttributeList(DWORD attribute_count);

  // Sets one entry in the initialized attribute list.
  // |value| needs to live at least as long as the StartupInformation object
  // this is called on.
  bool UpdateProcThreadAttribute(DWORD_PTR attribute,
                                 void* value,
                                 size_t size);

  LPSTARTUPINFOW startup_info() { return &startup_info_.StartupInfo; }
  LPSTARTUPINFOW startup_info() const {
    return const_cast<const LPSTARTUPINFOW>(&startup_info_.StartupInfo);
  }

  bool has_extended_startup_info() const {
    return !!startup_info_.lpAttributeList;
  }

 private:
  STARTUPINFOEXW startup_info_;
  DISALLOW_COPY_AND_ASSIGN(StartupInformation);
};

}  // namespace win
}  // namespace base

#endif  // BRICK_WIN_STARTUP_INFORMATION_H_
