// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_CALLBACK_ANDROID_H_
#define BRICK_ANDROID_CALLBACK_ANDROID_H_

#include <jni.h>
#include <vector>

#include "brick/android/scoped_java_ref.h"
#include "brick/base_export.h"

// Provides helper utility methods that run the given callback with the
// specified argument.
namespace base {
namespace android {

void BRICK_EXPORT RunCallbackAndroid(const JavaRef<jobject>& callback,
                                    const JavaRef<jobject>& arg);

void BRICK_EXPORT RunCallbackAndroid(const JavaRef<jobject>& callback,
                                    bool arg);

void BRICK_EXPORT RunCallbackAndroid(const JavaRef<jobject>& callback, int arg);

void BRICK_EXPORT RunStringCallbackAndroid(const JavaRef<jobject>& callback,
                                          const std::string& arg);

void BRICK_EXPORT RunCallbackAndroid(const JavaRef<jobject>& callback,
                                    const std::vector<uint8_t>& arg);

}  // namespace android
}  // namespace base

#endif  // BRICK_ANDROID_CALLBACK_ANDROID_H_
