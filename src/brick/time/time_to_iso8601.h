// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TIME_TIME_TO_ISO8601_H_
#define BRICK_TIME_TIME_TO_ISO8601_H_

#include <string>

#include "brick/base_export.h"

namespace base {

class Time;

BRICK_EXPORT std::string TimeToISO8601(const base::Time& t);

}  // namespace base

#endif  // BRICK_TIME_TIME_TO_ISO8601_H_
