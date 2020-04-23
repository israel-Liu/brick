// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/test/icu_test_util.h"

#include "brick/base_switches.h"
#include "brick/command_line.h"
#include "brick/i18n/icu_util.h"
#include "brick/i18n/rtl.h"
#include "third_party/icu/source/common/unicode/uloc.h"

namespace base {
namespace test {

ScopedRestoreICUDefaultLocale::ScopedRestoreICUDefaultLocale()
    : ScopedRestoreICUDefaultLocale(std::string()) {}

ScopedRestoreICUDefaultLocale::ScopedRestoreICUDefaultLocale(
    const std::string& locale)
    : default_locale_(uloc_getDefault()) {
  if (!locale.empty())
    i18n::SetICUDefaultLocale(locale.data());
}

ScopedRestoreICUDefaultLocale::~ScopedRestoreICUDefaultLocale() {
  i18n::SetICUDefaultLocale(default_locale_.data());
}

void InitializeICUForTesting() {
  if (!CommandLine::ForCurrentProcess()->HasSwitch(
          switches::kTestDoNotInitializeIcu)) {
    i18n::AllowMultipleInitializeCallsForTesting();
    i18n::InitializeICU();
  }
}

}  // namespace test
}  // namespace base
