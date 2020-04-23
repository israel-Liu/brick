// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "brick/nix/mime_util_xdg.h"

#include "brick/files/file_path.h"
#include "brick/lazy_instance.h"
#include "brick/synchronization/lock.h"
#include "brick/third_party/xdg_mime/xdgmime.h"
#include "brick/threading/thread_restrictions.h"

namespace base {
namespace nix {

namespace {

// None of the XDG stuff is thread-safe, so serialize all access under
// this lock.
LazyInstance<Lock>::Leaky g_mime_util_xdg_lock = LAZY_INSTANCE_INITIALIZER;

}  // namespace

std::string GetFileMimeType(const FilePath& filepath) {
  if (filepath.empty())
    return std::string();
  AssertBlockingAllowed();
  AutoLock scoped_lock(g_mime_util_xdg_lock.Get());
  return xdg_mime_get_mime_type_from_file_name(filepath.value().c_str());
}

}  // namespace nix
}  // namespace base
