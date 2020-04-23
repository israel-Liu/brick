// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_I18N_BRICK_I18N_SWITCHES_H_
#define BRICK_I18N_BRICK_I18N_SWITCHES_H_

#include "brick/i18n/base_i18n_export.h"

namespace switches {

BRICK_I18N_EXPORT extern const char kForceUIDirection[];
BRICK_I18N_EXPORT extern const char kForceTextDirection[];

// kForce*Direction choices for the switches above.
BRICK_I18N_EXPORT extern const char kForceDirectionLTR[];
BRICK_I18N_EXPORT extern const char kForceDirectionRTL[];

}  // namespace switches

#endif  // BRICK_I18N_BRICK_I18N_SWITCHES_H_
