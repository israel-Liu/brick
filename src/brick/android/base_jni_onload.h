// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_BRICK_JNI_ONLOAD_H_
#define BRICK_ANDROID_BRICK_JNI_ONLOAD_H_

#include <jni.h>
#include <vector>

#include "brick/base_export.h"
#include "brick/callback.h"

namespace base {
namespace android {

// Returns whether initialization succeeded.
BRICK_EXPORT bool OnJNIOnLoadInit();

}  // namespace android
}  // namespace base

#endif  // BRICK_ANDROID_BRICK_JNI_ONLOAD_H_
