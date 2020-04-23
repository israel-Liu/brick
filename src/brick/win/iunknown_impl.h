// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_WIN_IUNKNOWN_IMPL_H_
#define BRICK_WIN_IUNKNOWN_IMPL_H_

#include <unknwn.h>

#include "brick/atomic_ref_count.h"
#include "brick/base_export.h"
#include "brick/compiler_specific.h"

namespace base {
namespace win {

// IUnknown implementation for other classes to derive from.
class BRICK_EXPORT IUnknownImpl : public IUnknown {
 public:
  IUnknownImpl();

  ULONG STDMETHODCALLTYPE AddRef() override;
  ULONG STDMETHODCALLTYPE Release() override;

  // Subclasses should extend this to return any interfaces they provide.
  STDMETHODIMP QueryInterface(REFIID riid, void** ppv) override;

 protected:
  virtual ~IUnknownImpl();

 private:
  AtomicRefCount ref_count_;
};

}  // namespace win
}  // namespace base

#endif  // BRICK_WIN_IUNKNOWN_IMPL_H_
