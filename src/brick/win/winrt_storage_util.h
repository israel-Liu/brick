// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_WIN_WINRT_STORAGE_UTIL_H_
#define BRICK_WIN_WINRT_STORAGE_UTIL_H_

#include <stdint.h>
#include <windows.storage.streams.h>
#include <wrl/client.h>

#include "brick/base_export.h"

namespace base {
namespace win {

// Gets an array of bytes in the |buffer|, |out| represents a array of
// bytes used by byte stream read and write.
BRICK_EXPORT HRESULT
GetPointerToBufferData(ABI::Windows::Storage::Streams::IBuffer* buffer,
                       uint8_t** out,
                       UINT32* length);

// Creates stream |buffer| from |data| that represents a array of bytes
// and the |length| of bytes.
BRICK_EXPORT HRESULT CreateIBufferFromData(
    const uint8_t* data,
    UINT32 length,
    Microsoft::WRL::ComPtr<ABI::Windows::Storage::Streams::IBuffer>* buffer);

}  // namespace win
}  // namespace base

#endif  // BRICK_WIN_WINRT_STORAGE_UTIL_H_
