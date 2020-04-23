// Copyright 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_IOS_IOS_UTIL_H_
#define BRICK_IOS_IOS_UTIL_H_

#include <stdint.h>

#include "brick/base_export.h"
#include "brick/files/file_path.h"

namespace base {
namespace ios {

// Returns whether the operating system is iOS 10 or later.
BRICK_EXPORT bool IsRunningOnIOS10OrLater();

// Returns whether the operating system is iOS 11 or later.
BRICK_EXPORT bool IsRunningOnIOS11OrLater();

// Returns whether the operating system is at the given version or later.
BRICK_EXPORT bool IsRunningOnOrLater(int32_t major,
                                    int32_t minor,
                                    int32_t bug_fix);

// Returns whether iOS is signalling that an RTL text direction should be used
// regardless of the current locale. This should not return true if the current
// language is a "real" RTL language such as Arabic or Urdu; it should only
// return true in cases where the RTL text direction has been forced (for
// example by using the "RTL Psuedolanguage" option when launching from XCode).
BRICK_EXPORT bool IsInForcedRTL();

// Stores the |path| of the ICU dat file in a global to be referenced later by
// FilePathOfICUFile().  This should only be called once.
BRICK_EXPORT void OverridePathOfEmbeddedICU(const char* path);

// Returns the overriden path set by OverridePathOfEmbeddedICU(), otherwise
// returns invalid FilePath.
BRICK_EXPORT FilePath FilePathOfEmbeddedICU();

}  // namespace ios
}  // namespace base

#endif  // BRICK_IOS_IOS_UTIL_H_
