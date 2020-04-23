// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_WIN_CORE_WINRT_UTIL_H_
#define BRICK_WIN_CORE_WINRT_UTIL_H_

#include <hstring.h>
#include <inspectable.h>
#include <roapi.h>
#include <windef.h>

#include "brick/base_export.h"
#include "brick/strings/string16.h"
#include "brick/win/scoped_hstring.h"

namespace base {
namespace win {

// Provides access to Core WinRT functions which may not be available on
// Windows 7. Loads functions dynamically at runtime to prevent library
// dependencies.

BRICK_EXPORT bool ResolveCoreWinRTDelayload();

// The following stubs are provided for when component build is enabled, in
// order to avoid the propagation of delay-loading CoreWinRT to other modules.

BRICK_EXPORT HRESULT RoInitialize(RO_INIT_TYPE init_type);

BRICK_EXPORT void RoUninitialize();

BRICK_EXPORT HRESULT RoGetActivationFactory(HSTRING class_id,
                                           const IID& iid,
                                           void** out_factory);

BRICK_EXPORT HRESULT RoActivateInstance(HSTRING class_id,
                                       IInspectable** instance);

// Retrieves an activation factory for the type specified.
template <typename InterfaceType, char16 const* runtime_class_id>
HRESULT GetActivationFactory(InterfaceType** factory) {
  ScopedHString class_id_hstring = ScopedHString::Create(runtime_class_id);
  if (!class_id_hstring.is_valid())
    return E_FAIL;

  return base::win::RoGetActivationFactory(class_id_hstring.get(),
                                           IID_PPV_ARGS(factory));
}

}  // namespace win
}  // namespace base

#endif  // BRICK_WIN_CORE_WINRT_UTIL_H_
