// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/android/jni_android.h"
#include "brick/android/jni_string.h"
#include "brick/files/file_path.h"
#include "brick/path_service.h"
#include "jni/PathService_jni.h"

namespace base {
namespace android {

void JNI_PathService_Override(JNIEnv* env,
                              const JavaParamRef<jclass>& clazz,
                              jint what,
                              const JavaParamRef<jstring>& path) {
  FilePath file_path(ConvertJavaStringToUTF8(env, path));
  PathService::Override(what, file_path);
}

}  // namespace android
}  // namespace base
