// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_LIBRARY_LOADER_ANCHOR_FUNCTIONS_H_
#define BRICK_ANDROID_LIBRARY_LOADER_ANCHOR_FUNCTIONS_H_

#include <cstdint>
#include "brick/android/library_loader/anchor_functions_buildflags.h"

#include "brick/base_export.h"

#if BUILDFLAG(SUPPORTS_CODE_ORDERING)

namespace base {
namespace android {

// Start and end of .text, respectively.
BRICK_EXPORT extern const size_t kStartOfText;
BRICK_EXPORT extern const size_t kEndOfText;
// Start and end of the ordered part of .text, respectively.
BRICK_EXPORT extern const size_t kStartOfOrderedText;
BRICK_EXPORT extern const size_t kEndOfOrderedText;

// Returns true if the ordering looks sane.
BRICK_EXPORT bool IsOrderingSane();

}  // namespace android
}  // namespace base
#endif  // BUILDFLAG(SUPPORTS_CODE_ORDERING)

#endif  // BRICK_ANDROID_LIBRARY_LOADER_ANCHOR_FUNCTIONS_H_
