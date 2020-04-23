// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_SYS_UTILS_H_
#define BRICK_ANDROID_SYS_UTILS_H_

#include "brick/android/jni_android.h"

namespace base {
namespace android {

class BRICK_EXPORT SysUtils {
 public:
  // Returns true iff this is a low-end device.
  static bool IsLowEndDeviceFromJni();
  // Returns true if system has low available memory.
  static bool IsCurrentlyLowMemory();
};

}  // namespace android
}  // namespace base

#endif  // BRICK_ANDROID_SYS_UTILS_H_
