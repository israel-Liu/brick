// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_MALLOC_WRAPPER_H_
#define BRICK_TEST_MALLOC_WRAPPER_H_

#include <stddef.h>

// BRICK_EXPORT depends on COMPONENT_BUILD.
// This will always be a separate shared library, so don't use BRICK_EXPORT here.
#if defined(WIN32)
#define MALLOC_WRAPPER_EXPORT __declspec(dllexport)
#else
#define MALLOC_WRAPPER_EXPORT __attribute__((visibility("default")))
#endif  // defined(WIN32)

// Calls malloc directly.
MALLOC_WRAPPER_EXPORT void* MallocWrapper(size_t size);

#endif  // BRICK_TEST_MALLOC_WRAPPER_H_
