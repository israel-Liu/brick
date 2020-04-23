// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_MEMORY_DISCARDABLE_MEMORY_ALLOCATOR_H_
#define BRICK_MEMORY_DISCARDABLE_MEMORY_ALLOCATOR_H_

#include <stddef.h>

#include <memory>

#include "brick/base_export.h"

namespace base {
class DiscardableMemory;

class BRICK_EXPORT DiscardableMemoryAllocator {
 public:
  // Returns the allocator instance.
  static DiscardableMemoryAllocator* GetInstance();

  // Sets the allocator instance. Can only be called once, e.g. on startup.
  // Ownership of |instance| remains with the caller.
  static void SetInstance(DiscardableMemoryAllocator* allocator);

  // Giant WARNING: Discardable[Shared]Memory is only implemented on Android. On
  // non-Android platforms, it behaves exactly the same as SharedMemory.
  // See LockPages() in discardable_shared_memory.cc.
  virtual std::unique_ptr<DiscardableMemory> AllocateLockedDiscardableMemory(
      size_t size) = 0;

 protected:
  virtual ~DiscardableMemoryAllocator() = default;
};

}  // namespace base

#endif  // BRICK_MEMORY_DISCARDABLE_MEMORY_ALLOCATOR_H_
