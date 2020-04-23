// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/android/base_jni_onload.h"

#include "brick/android/jni_android.h"
#include "brick/android/jni_utils.h"
#include "brick/android/library_loader/library_loader_hooks.h"
#include "brick/bind.h"

namespace base {
namespace android {

bool OnJNIOnLoadInit() {
  InitAtExitManager();
  JNIEnv* env = base::android::AttachCurrentThread();
  base::android::InitReplacementClassLoader(env,
                                            base::android::GetClassLoader(env));
  return true;
}

}  // namespace android
}  // namespace base
