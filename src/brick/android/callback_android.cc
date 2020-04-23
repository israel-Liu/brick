// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/android/callback_android.h"

#include "brick/android/jni_array.h"
#include "brick/android/jni_string.h"
#include "brick/android/scoped_java_ref.h"
#include "jni/Callback_jni.h"

namespace base {
namespace android {

void RunCallbackAndroid(const JavaRef<jobject>& callback,
                        const JavaRef<jobject>& arg) {
  Java_Helper_onObjectResultFromNative(AttachCurrentThread(), callback, arg);
}

void RunCallbackAndroid(const JavaRef<jobject>& callback, bool arg) {
  Java_Helper_onBooleanResultFromNative(AttachCurrentThread(), callback,
                                        static_cast<jboolean>(arg));
}

void RunCallbackAndroid(const JavaRef<jobject>& callback, int arg) {
  Java_Helper_onIntResultFromNative(AttachCurrentThread(), callback, arg);
}

void RunStringCallbackAndroid(const JavaRef<jobject>& callback,
                              const std::string& arg) {
  JNIEnv* env = AttachCurrentThread();
  ScopedJavaLocalRef<jstring> java_string = ConvertUTF8ToJavaString(env, arg);
  Java_Helper_onObjectResultFromNative(env, callback, java_string);
}

void RunCallbackAndroid(const JavaRef<jobject>& callback,
                        const std::vector<uint8_t>& arg) {
  JNIEnv* env = AttachCurrentThread();
  ScopedJavaLocalRef<jbyteArray> j_bytes = ToJavaByteArray(env, arg);
  Java_Helper_onObjectResultFromNative(env, callback, j_bytes);
}

}  // namespace android
}  // namespace base
