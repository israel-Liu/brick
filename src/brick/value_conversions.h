// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_VALUE_CONVERSIONS_H_
#define BRICK_VALUE_CONVERSIONS_H_

// This file contains methods to convert things to a |Value| and back.

#include <memory>
#include "brick/base_export.h"

namespace base {

class FilePath;
class TimeDelta;
class UnguessableToken;
class Value;

// The caller takes ownership of the returned value.
BRICK_EXPORT std::unique_ptr<Value> CreateFilePathValue(
    const FilePath& in_value);
BRICK_EXPORT bool GetValueAsFilePath(const Value& value, FilePath* file_path);

BRICK_EXPORT std::unique_ptr<Value> CreateTimeDeltaValue(const TimeDelta& time);
BRICK_EXPORT bool GetValueAsTimeDelta(const Value& value, TimeDelta* time);

BRICK_EXPORT std::unique_ptr<Value> CreateUnguessableTokenValue(
    const UnguessableToken& token);
BRICK_EXPORT bool GetValueAsUnguessableToken(const Value& value,
                                            UnguessableToken* token);

}  // namespace base

#endif  // BRICK_VALUE_CONVERSIONS_H_
