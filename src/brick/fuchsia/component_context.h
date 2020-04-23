// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_FUCHSIA_COMPONENT_CONTEXT_H_
#define BRICK_FUCHSIA_COMPONENT_CONTEXT_H_

#include "brick/base_export.h"
#include "brick/fuchsia/fidl_interface_request.h"
#include "brick/fuchsia/scoped_zx_handle.h"
#include "brick/macros.h"
#include "brick/strings/string_piece.h"

namespace fidl {

template <typename Interface>
class InterfacePtr;

template <typename Interface>
class SynchronousInterfacePtr;

}  // namespace fidl

namespace base {
namespace fuchsia {

// Provides access to the component's environment.
class BRICK_EXPORT ComponentContext {
 public:
  explicit ComponentContext(ScopedZxHandle service_root);
  ~ComponentContext();

  // Returns default ComponentContext instance for the current process. It uses
  // /srv namespace to connect to environment services.
  static ComponentContext* GetDefault();

  // Satisfies the interface |request| by binding the channel to a service.
  void ConnectToService(FidlInterfaceRequest request);

  // Same as above, but returns interface pointer instead of taking a request.
  template <typename Interface>
  fidl::InterfacePtr<Interface> ConnectToService() {
    fidl::InterfacePtr<Interface> result;
    ConnectToService(FidlInterfaceRequest(&result));
    return result;
  }

  // Connects to an environment service and returns synchronous interface
  // implementation.
  template <typename Interface>
  fidl::SynchronousInterfacePtr<Interface> ConnectToServiceSync() {
    fidl::SynchronousInterfacePtr<Interface> result;
    ConnectToService(FidlInterfaceRequest(&result));
    return result;
  }

 private:
  ScopedZxHandle service_root_;

  DISALLOW_COPY_AND_ASSIGN(ComponentContext);
};

}  // namespace fuchsia
}  // namespace base

#endif  // BRICK_FUCHSIA_COMPONENT_CONTEXT_H_