// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_FONTCONFIG_UTIL_LINUX_H_
#define BRICK_TEST_FONTCONFIG_UTIL_LINUX_H_

namespace base {

// Initializes Fontconfig with a custom configuration suitable for tests.
void SetUpFontconfig();

// Deinitializes Fontconfig.
void TearDownFontconfig();

}  // namespace base

#endif  // BRICK_TEST_FONTCONFIG_UTIL_LINUX_H_
