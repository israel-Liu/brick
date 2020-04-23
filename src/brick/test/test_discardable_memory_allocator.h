// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_TEST_DISCARDABLE_MEMORY_ALLOCATOR_H_
#define BRICK_TEST_TEST_DISCARDABLE_MEMORY_ALLOCATOR_H_

#include <stddef.h>

#include "brick/macros.h"
#include "brick/memory/discardable_memory_allocator.h"

namespace base {

// TestDiscardableMemoryAllocator is a simple DiscardableMemoryAllocator
// implementation that can be used for testing. It allocates one-shot
// DiscardableMemory instances backed by heap memory.
class TestDiscardableMemoryAllocator : public DiscardableMemoryAllocator {
 public:
  constexpr TestDiscardableMemoryAllocator() = default;

  // Overridden from DiscardableMemoryAllocator:
  std::unique_ptr<DiscardableMemory> AllocateLockedDiscardableMemory(
      size_t size) override;

 private:
  DISALLOW_COPY_AND_ASSIGN(TestDiscardableMemoryAllocator);
};

}  // namespace base

#endif  // BRICK_TEST_TEST_DISCARDABLE_MEMORY_ALLOCATOR_H_
