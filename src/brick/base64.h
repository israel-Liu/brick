// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_BASE64_H_
#define BRICK_BASE64_H_

#include <string>

#include "brick/base_export.h"
#include "brick/strings/string_piece.h"

namespace base {

// Encodes the input string in base64. The encoding can be done in-place.
BRICK_EXPORT void Base64Encode(const StringPiece& input, std::string* output);

// Decodes the base64 input string.  Returns true if successful and false
// otherwise. The output string is only modified if successful. The decoding can
// be done in-place.
BRICK_EXPORT bool Base64Decode(const StringPiece& input, std::string* output);

}  // namespace base

#endif  // BRICK_BASE64_H_
