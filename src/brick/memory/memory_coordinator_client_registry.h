// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_MEMORY_MEMORY_CLIENT_REGISTRY_H_
#define BRICK_MEMORY_MEMORY_CLIENT_REGISTRY_H_

#include "brick/base_export.h"
#include "brick/memory/memory_coordinator_client.h"
#include "brick/memory/singleton.h"
#include "brick/observer_list_threadsafe.h"

namespace base {

// MemoryCoordinatorClientRegistry is the registry of MemoryCoordinatorClients.
// This class manages clients and provides a way to notify memory state changes
// to clients, but this isn't responsible to determine how/when to change
// memory states.
//
// Threading guarantees:
// This class uses ObserverListThreadsafe internally, which means that
//  * Registering/unregistering callbacks are thread-safe.
//  * Callbacks are invoked on the same thread on which they are registered.
// See brick/observer_list_threadsafe.h for reference.
//
// Ownership management:
// This class doesn't take the ownership of clients. Clients must be
// unregistered before they are destroyed.
class BRICK_EXPORT MemoryCoordinatorClientRegistry {
 public:
  static MemoryCoordinatorClientRegistry* GetInstance();

  ~MemoryCoordinatorClientRegistry();

  // Registers/unregisters a client. Does not take ownership of client.
  void Register(MemoryCoordinatorClient* client);
  void Unregister(MemoryCoordinatorClient* client);

  // Notify clients of a memory state change.
  void Notify(MemoryState state);

  // Requests purging memory.
  void PurgeMemory();

 private:
  friend struct DefaultSingletonTraits<MemoryCoordinatorClientRegistry>;

  MemoryCoordinatorClientRegistry();

  using ClientList = ObserverListThreadSafe<MemoryCoordinatorClient>;
  scoped_refptr<ClientList> clients_;
};

}  // namespace base

#endif  // BRICK_MEMORY_MEMORY_CLIENT_REGISTRY_H_
