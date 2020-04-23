// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_JAVA_EXCEPTION_REPORTER_H_
#define BRICK_ANDROID_JAVA_EXCEPTION_REPORTER_H_

#include <jni.h>

#include "brick/base_export.h"

namespace base {
namespace android {

// Install the exception handler. This should only be called once per process.
BRICK_EXPORT void InitJavaExceptionReporter();

// Same as above except the handler ensures child process exists immediately
// after an unhandled exception. This is used for child processes because
// DumpWithoutCrashing does not work for child processes on Android.
BRICK_EXPORT void InitJavaExceptionReporterForChildProcess();

}  // namespace android
}  // namespace base

#endif  // BRICK_ANDROID_JAVA_EXCEPTION_REPORTER_H_
