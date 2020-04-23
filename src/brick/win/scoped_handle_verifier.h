// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_WIN_SCOPED_HANDLE_VERIFIER_H_
#define BRICK_WIN_SCOPED_HANDLE_VERIFIER_H_

#include "brick/win/windows_types.h"

#include <unordered_map>

#include "brick/base_export.h"
#include "brick/debug/stack_trace.h"
#include "brick/hash.h"
#include "brick/synchronization/lock_impl.h"
#include "brick/threading/thread_local.h"

namespace base {
namespace win {
namespace internal {

struct HandleHash {
  size_t operator()(const HANDLE& handle) const {
    char buffer[sizeof(handle)];
    memcpy(buffer, &handle, sizeof(handle));
    return base::Hash(buffer, sizeof(buffer));
  }
};

struct ScopedHandleVerifierInfo {
  const void* owner;
  const void* pc1;
  const void* pc2;
  base::debug::StackTrace stack;
  DWORD thread_id;
};

// Implements the actual object that is verifying handles for this process.
// The active instance is shared across the module boundary but there is no
// way to delete this object from the wrong side of it (or any side, actually).
// We need [[clang::lto_visibility_public]] because instances of this class are
// passed across module boundaries. This means different modules must have
// compatible definitions of the class even when whole program optimization is
// enabled - which is what this attribute accomplishes. The pragma stops MSVC
// from emitting an unrecognized attribute warning.
#pragma warning(push)
#pragma warning(disable : 5030)
class [[clang::lto_visibility_public]] ScopedHandleVerifier {
#pragma warning(pop)
 public:
  explicit ScopedHandleVerifier(bool enabled);

  // Retrieves the current verifier.
  static ScopedHandleVerifier* Get();

  // The methods required by HandleTraits. They are virtual because we need to
  // forward the call execution to another module, instead of letting the
  // compiler call the version that is linked in the current module.
  virtual bool CloseHandle(HANDLE handle);
  virtual void StartTracking(HANDLE handle, const void* owner, const void* pc1,
                             const void* pc2);
  virtual void StopTracking(HANDLE handle, const void* owner, const void* pc1,
                            const void* pc2);
  virtual void Disable();
  virtual void OnHandleBeingClosed(HANDLE handle);
  virtual HMODULE GetModule() const;

 private:
  ~ScopedHandleVerifier();  // Not implemented.

  static base::internal::LockImpl* GetLock();
  static void InstallVerifier();

  base::debug::StackTrace creation_stack_;
  bool enabled_;
  base::ThreadLocalBoolean closing_;
  base::internal::LockImpl* lock_;
  std::unordered_map<HANDLE, ScopedHandleVerifierInfo, HandleHash> map_;
  DISALLOW_COPY_AND_ASSIGN(ScopedHandleVerifier);
};

// This testing function returns the module that the ActiveVerifier concrete
// implementation was instantiated in.
BRICK_EXPORT HMODULE GetHandleVerifierModuleForTesting();

}  // namespace internal
}  // namespace win
}  // namespace base

#endif  // BRICK_WIN_SCOPED_HANDLE_VERIFIER_H_
