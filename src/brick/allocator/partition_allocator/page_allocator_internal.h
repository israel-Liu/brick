// Copyright (c) 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ALLOCATOR_PARTITION_ALLOCATOR_PAGE_ALLOCATOR_INTERNAL_H_
#define BRICK_ALLOCATOR_PARTITION_ALLOCATOR_PAGE_ALLOCATOR_INTERNAL_H_

namespace base {

void* SystemAllocPages(void* hint,
                       size_t length,
                       PageAccessibilityConfiguration accessibility,
                       PageTag page_tag,
                       bool commit);

}  // namespace base

#endif  // BRICK_ALLOCATOR_PARTITION_ALLOCATOR_PAGE_ALLOCATOR_INTERNAL_H_
