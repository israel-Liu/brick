// Copyright (c) 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_MAC_SCOPED_BLOCK_H_
#define BRICK_MAC_SCOPED_BLOCK_H_

#include <Block.h>

#include "brick/mac/scoped_typeref.h"

#if defined(__has_feature) && __has_feature(objc_arc)
#define BRICK_MAC_BRIDGE_CAST(TYPE, VALUE) (__bridge TYPE)(VALUE)
#else
#define BRICK_MAC_BRIDGE_CAST(TYPE, VALUE) VALUE
#endif

namespace base {
namespace mac {

namespace internal {

template <typename B>
struct ScopedBlockTraits {
  static B InvalidValue() { return nullptr; }
  static B Retain(B block) {
    return BRICK_MAC_BRIDGE_CAST(
        B, Block_copy(BRICK_MAC_BRIDGE_CAST(const void*, block)));
  }
  static void Release(B block) {
    Block_release(BRICK_MAC_BRIDGE_CAST(const void*, block));
  }
};

}  // namespace internal

// ScopedBlock<> is patterned after ScopedCFTypeRef<>, but uses Block_copy() and
// Block_release() instead of CFRetain() and CFRelease().
template <typename B>
class ScopedBlock : public ScopedTypeRef<B, internal::ScopedBlockTraits<B>> {
 public:
  using Traits = internal::ScopedBlockTraits<B>;

#if !defined(__has_feature) || !__has_feature(objc_arc)
  explicit ScopedBlock(
      B block = Traits::InvalidValue(),
      base::scoped_policy::OwnershipPolicy policy = base::scoped_policy::ASSUME)
      : ScopedTypeRef<B, Traits>(block, policy) {}
#else
  explicit ScopedBlock(B block = Traits::InvalidValue())
      : ScopedTypeRef<B, Traits>(block, base::scoped_policy::RETAIN) {}
#endif

#if !defined(__has_feature) || !__has_feature(objc_arc)
  void reset(B block = Traits::InvalidValue(),
             base::scoped_policy::OwnershipPolicy policy =
                 base::scoped_policy::ASSUME) {
    ScopedTypeRef<B, Traits>::reset(block, policy);
  }
#else
  void reset(B block = Traits::InvalidValue()) {
    ScopedTypeRef<B, Traits>::reset(block, base::scoped_policy::RETAIN);
  }
#endif
};

}  // namespace mac
}  // namespace base

#undef BRICK_MAC_BRIDGE_CAST

#endif  // BRICK_MAC_SCOPED_BLOCK_H_
