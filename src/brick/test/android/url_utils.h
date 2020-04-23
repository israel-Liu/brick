// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_ANDROID_URL_UTILS_H_
#define BRICK_TEST_ANDROID_URL_UTILS_H_

#include <jni.h>

#include "brick/base_export.h"
#include "brick/files/file_path.h"

namespace base {
namespace android {

// Returns the root of the test data directory. This function will call into
// Java class UrlUtils through JNI bridge.
BRICK_EXPORT FilePath GetIsolatedTestRoot();

}  // namespace android
}  // namespace base

#endif  // BRICK_TEST_ANDROID_URL_UTILS_H_
