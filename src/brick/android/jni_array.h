// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_JNI_ARRAY_H_
#define BRICK_ANDROID_JNI_ARRAY_H_

#include <jni.h>
#include <stddef.h>
#include <stdint.h>
#include <string>
#include <vector>

#include "brick/android/scoped_java_ref.h"
#include "brick/strings/string16.h"

namespace base {
namespace android {

// Returns a new Java byte array converted from the given bytes array.
BRICK_EXPORT ScopedJavaLocalRef<jbyteArray> ToJavaByteArray(JNIEnv* env,
                                                           const uint8_t* bytes,
                                                           size_t len);

BRICK_EXPORT ScopedJavaLocalRef<jbyteArray> ToJavaByteArray(
    JNIEnv* env,
    const std::vector<uint8_t>& bytes);

// Returns a new Java boolean array converted from the given bool array.
BRICK_EXPORT ScopedJavaLocalRef<jbooleanArray>
ToJavaBooleanArray(JNIEnv* env, const bool* bools, size_t len);

// Returns a new Java int array converted from the given int array.
BRICK_EXPORT ScopedJavaLocalRef<jintArray> ToJavaIntArray(
    JNIEnv* env, const int* ints, size_t len);

BRICK_EXPORT ScopedJavaLocalRef<jintArray> ToJavaIntArray(
    JNIEnv* env, const std::vector<int>& ints);

// Returns a new Java long array converted from the given int64_t array.
BRICK_EXPORT ScopedJavaLocalRef<jlongArray> ToJavaLongArray(JNIEnv* env,
                                                           const int64_t* longs,
                                                           size_t len);

BRICK_EXPORT ScopedJavaLocalRef<jlongArray> ToJavaLongArray(
    JNIEnv* env,
    const std::vector<int64_t>& longs);

// Returns a new Java float array converted from the given C++ float array.
BRICK_EXPORT ScopedJavaLocalRef<jfloatArray> ToJavaFloatArray(
    JNIEnv* env, const float* floats, size_t len);

BRICK_EXPORT ScopedJavaLocalRef<jfloatArray> ToJavaFloatArray(
    JNIEnv* env,
    const std::vector<float>& floats);

// Returns a array of Java byte array converted from |v|.
BRICK_EXPORT ScopedJavaLocalRef<jobjectArray> ToJavaArrayOfByteArray(
    JNIEnv* env, const std::vector<std::string>& v);

BRICK_EXPORT ScopedJavaLocalRef<jobjectArray> ToJavaArrayOfStrings(
    JNIEnv* env,  const std::vector<std::string>& v);

BRICK_EXPORT ScopedJavaLocalRef<jobjectArray> ToJavaArrayOfStrings(
    JNIEnv* env,  const std::vector<string16>& v);

// Converts a Java string array to a native array.
BRICK_EXPORT void AppendJavaStringArrayToStringVector(
    JNIEnv* env,
    jobjectArray array,
    std::vector<string16>* out);

BRICK_EXPORT void AppendJavaStringArrayToStringVector(
    JNIEnv* env,
    jobjectArray array,
    std::vector<std::string>* out);

// Appends the Java bytes in |bytes_array| onto the end of |out|.
BRICK_EXPORT void AppendJavaByteArrayToByteVector(JNIEnv* env,
                                                 jbyteArray byte_array,
                                                 std::vector<uint8_t>* out);

// Replaces the content of |out| with the Java bytes in |bytes_array|.
BRICK_EXPORT void JavaByteArrayToByteVector(JNIEnv* env,
                                           jbyteArray byte_array,
                                           std::vector<uint8_t>* out);

// Replaces the content of |out| with the Java booleans in |boolean_array|.
BRICK_EXPORT void JavaBooleanArrayToBoolVector(JNIEnv* env,
                                              jbooleanArray boolean_array,
                                              std::vector<bool>* out);

// Replaces the content of |out| with the Java ints in |int_array|.
BRICK_EXPORT void JavaIntArrayToIntVector(
    JNIEnv* env,
    jintArray int_array,
    std::vector<int>* out);

// Replaces the content of |out| with the Java longs in |long_array|.
BRICK_EXPORT void JavaLongArrayToInt64Vector(JNIEnv* env,
                                            jlongArray long_array,
                                            std::vector<int64_t>* out);

// Replaces the content of |out| with the Java longs in |long_array|.
BRICK_EXPORT void JavaLongArrayToLongVector(
    JNIEnv* env,
    jlongArray long_array,
    std::vector<jlong>* out);

// Replaces the content of |out| with the Java floats in |float_array|.
BRICK_EXPORT void JavaFloatArrayToFloatVector(
    JNIEnv* env,
    jfloatArray float_array,
    std::vector<float>* out);

// Assuming |array| is an byte[][] (array of byte arrays), replaces the
// content of |out| with the corresponding vector of strings. No UTF-8
// conversion is performed.
BRICK_EXPORT void JavaArrayOfByteArrayToStringVector(
    JNIEnv* env,
    jobjectArray array,
    std::vector<std::string>* out);

// Assuming |array| is an int[][] (array of int arrays), replaces the
// contents of |out| with the corresponding vectors of ints.
BRICK_EXPORT void JavaArrayOfIntArrayToIntVector(
    JNIEnv* env,
    jobjectArray array,
    std::vector<std::vector<int>>* out);

}  // namespace android
}  // namespace base

#endif  // BRICK_ANDROID_JNI_ARRAY_H_
