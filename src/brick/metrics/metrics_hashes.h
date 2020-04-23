// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_METRICS_METRICS_HASHES_H_
#define BRICK_METRICS_METRICS_HASHES_H_

#include <stdint.h>

#include "brick/base_export.h"
#include "brick/strings/string_piece.h"

namespace base {

// Computes a uint64_t hash of a given string based on its MD5 hash. Suitable
// for metric names.
BRICK_EXPORT uint64_t HashMetricName(base::StringPiece name);

}  // namespace metrics

#endif  // BRICK_METRICS_METRICS_HASHES_H_
