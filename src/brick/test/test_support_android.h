// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_TEST_SUPPORT_ANDROID_H_
#define BRICK_TEST_TEST_SUPPORT_ANDROID_H_

#include "brick/base_export.h"

namespace base {

class FilePath;

// Init logging for tests on Android. Logs will be output into Android's logcat.
BRICK_EXPORT void InitAndroidTestLogging();

// Init path providers for tests on Android.
BRICK_EXPORT void InitAndroidTestPaths(const FilePath& test_data_dir);

// Init the message loop for tests on Android.
BRICK_EXPORT void InitAndroidTestMessageLoop();

}  // namespace base

#endif  // BRICK_TEST_TEST_SUPPORT_ANDROID_H_
