// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Forward declaration of StringPiece types from brick/strings/string_piece.h

#ifndef BRICK_STRINGS_STRING_PIECE_FORWARD_H_
#define BRICK_STRINGS_STRING_PIECE_FORWARD_H_

#include <string>

namespace base {

template <typename STRING_TYPE>
class BasicStringPiece;
typedef BasicStringPiece<std::string> StringPiece;
typedef BasicStringPiece<std::wstring> WStringPiece;

}  // namespace base

#endif  // BRICK_STRINGS_STRING_PIECE_FORWARD_H_
