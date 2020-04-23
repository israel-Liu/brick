// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_WIN_COM_INIT_UTIL_H_
#define BRICK_WIN_COM_INIT_UTIL_H_

#include "brick/base_export.h"
#include "brick/logging.h"

namespace base {
namespace win {

enum class ComApartmentType {
  // Uninitialized or has an unrecognized apartment type.
  NONE,
  // Single-threaded Apartment.
  STA,
  // Multi-threaded Apartment.
  MTA,
};

#if DCHECK_IS_ON()

// DCHECKs if COM is not initialized on this thread as an STA or MTA.
// |message| is optional and is used for the DCHECK if specified.
BRICK_EXPORT void AssertComInitialized(const char* message = nullptr);

// DCHECKs if |apartment_type| is not the same as the current thread's apartment
// type.
BRICK_EXPORT void AssertComApartmentType(ComApartmentType apartment_type);

#else   // DCHECK_IS_ON()
inline void AssertComInitialized() {}
inline void AssertComApartmentType(ComApartmentType apartment_type) {}
#endif  // DCHECK_IS_ON()

}  // namespace win
}  // namespace base

#endif  // BRICK_WIN_COM_INIT_UTIL_H_
