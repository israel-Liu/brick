// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_BRICK_EXPORT_H_
#define BRICK_BRICK_EXPORT_H_

#if defined(COMPONENT_BUILD)
#if defined(WIN32)

#if defined(BRICK_IMPLEMENTATION)
#define BRICK_EXPORT __declspec(dllexport)
#else
#define BRICK_EXPORT __declspec(dllimport)
#endif  // defined(BRICK_IMPLEMENTATION)

#else  // defined(WIN32)
#if defined(BRICK_IMPLEMENTATION)
#define BRICK_EXPORT __attribute__((visibility("default")))
#else
#define BRICK_EXPORT
#endif  // defined(BRICK_IMPLEMENTATION)
#endif

#else  // defined(COMPONENT_BUILD)
#define BRICK_EXPORT
#endif

#endif  // BRICK_BRICK_EXPORT_H_
