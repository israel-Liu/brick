// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_EVENT_LOG_H_
#define BRICK_ANDROID_EVENT_LOG_H_

#include <jni.h>

#include "brick/base_export.h"

namespace base {
namespace android {

void BRICK_EXPORT EventLogWriteInt(int tag, int value);

}  // namespace android
}  // namespace base

#endif  // BRICK_ANDROID_EVENT_LOG_H_
