// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_I18N_STRING_SEARCH_H_
#define BRICK_I18N_STRING_SEARCH_H_

#include <stddef.h>

#include "brick/i18n/base_i18n_export.h"
#include "brick/strings/string16.h"

struct UStringSearch;

namespace base {
namespace i18n {

// Returns true if |in_this| contains |find_this|. If |match_index| or
// |match_length| are non-NULL, they are assigned the start position and total
// length of the match.
//
// Only differences between base letters are taken into consideration. Case and
// accent differences are ignored. Please refer to 'primary level' in
// http://userguide.icu-project.org/collation/concepts for additional details.
BRICK_I18N_EXPORT
    bool StringSearchIgnoringCaseAndAccents(const string16& find_this,
                                            const string16& in_this,
                                            size_t* match_index,
                                            size_t* match_length);

// This class is for speeding up multiple StringSearchIgnoringCaseAndAccents()
// with the same |find_this| argument. |find_this| is passed as the constructor
// argument, and precomputation for searching is done only at that timing.
class BRICK_I18N_EXPORT FixedPatternStringSearchIgnoringCaseAndAccents {
 public:
  explicit FixedPatternStringSearchIgnoringCaseAndAccents(
      const string16& find_this);
  ~FixedPatternStringSearchIgnoringCaseAndAccents();

  // Returns true if |in_this| contains |find_this|. If |match_index| or
  // |match_length| are non-NULL, they are assigned the start position and total
  // length of the match.
  bool Search(const string16& in_this,
              size_t* match_index,
              size_t* match_length);

 private:
  string16 find_this_;
  UStringSearch* search_;
};

}  // namespace i18n
}  // namespace base

#endif  // BRICK_I18N_STRING_SEARCH_H_
