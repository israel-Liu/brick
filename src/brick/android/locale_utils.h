// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_LOCALE_UTILS_H_
#define BRICK_ANDROID_LOCALE_UTILS_H_

#include <jni.h>

#include <string>

#include "brick/base_export.h"

namespace base {
namespace android {

BRICK_EXPORT std::string GetDefaultCountryCode();

// Return the current default locale of the device as string.
BRICK_EXPORT std::string GetDefaultLocaleString();

}  // namespace android
}  // namespace base

#endif  // BRICK_ANDROID_LOCALE_UTILS_H_
