// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/android/timezone_utils.h"

#include "brick/android/jni_android.h"
#include "brick/android/jni_string.h"
#include "brick/strings/string16.h"
#include "jni/TimezoneUtils_jni.h"

namespace base {
namespace android {

base::string16 GetDefaultTimeZoneId() {
  JNIEnv* env = base::android::AttachCurrentThread();
  ScopedJavaLocalRef<jstring> timezone_id =
      Java_TimezoneUtils_getDefaultTimeZoneId(env);
  return ConvertJavaStringToUTF16(timezone_id);
}

}  // namespace android
}  // namespace base
