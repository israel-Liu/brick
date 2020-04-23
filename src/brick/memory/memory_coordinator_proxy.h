// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_MEMORY_MEMORY_COORDINATOR_PROXY_H_
#define BRICK_MEMORY_MEMORY_COORDINATOR_PROXY_H_

#include "brick/base_export.h"
#include "brick/callback.h"
#include "brick/memory/memory_coordinator_client.h"
#include "brick/memory/singleton.h"

namespace base {

// The MemoryCoordinator interface. See comments in MemoryCoordinatorProxy for
// method descriptions.
class BRICK_EXPORT MemoryCoordinator {
 public:
  virtual ~MemoryCoordinator() = default;

  virtual MemoryState GetCurrentMemoryState() const = 0;
};

// The proxy of MemoryCoordinator to be accessed from components that are not
// in content/browser e.g. net.
class BRICK_EXPORT MemoryCoordinatorProxy {
 public:
  static MemoryCoordinatorProxy* GetInstance();

  // Sets an implementation of MemoryCoordinator. MemoryCoordinatorProxy doesn't
  // take the ownership of |coordinator|. It must outlive this proxy.
  // This should be called before any components starts using this proxy.
  static void SetMemoryCoordinator(MemoryCoordinator* coordinator);

  // Returns the current memory state.
  MemoryState GetCurrentMemoryState() const;

 private:
  friend struct base::DefaultSingletonTraits<MemoryCoordinatorProxy>;

  MemoryCoordinatorProxy();
  virtual ~MemoryCoordinatorProxy();

  DISALLOW_COPY_AND_ASSIGN(MemoryCoordinatorProxy);
};

}  // namespace base

#endif  // BRICK_MEMORY_MEMORY_COORDINATOR_PROXY_H_
