// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_TIMEZONE_UTILS_H_
#define BRICK_ANDROID_TIMEZONE_UTILS_H_

#include <jni.h>

#include "brick/base_export.h"
#include "brick/strings/string16.h"

namespace base {
namespace android {

// Return an ICU timezone created from the host timezone.
BRICK_EXPORT base::string16 GetDefaultTimeZoneId();

}  // namespace android
}  // namespace base

#endif  // BRICK_ANDROID_TIMEZONE_UTILS_H_
