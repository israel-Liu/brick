// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_ANDROID_CONTENT_URI_UTILS_H_
#define BRICK_ANDROID_CONTENT_URI_UTILS_H_

#include <jni.h>

#include "brick/base_export.h"
#include "brick/files/file.h"
#include "brick/files/file_path.h"

namespace base {

// Opens a content URI for read and returns the file descriptor to the caller.
// Returns -1 if the URI is invalid.
BRICK_EXPORT File OpenContentUriForRead(const FilePath& content_uri);

// Check whether a content URI exists.
BRICK_EXPORT bool ContentUriExists(const FilePath& content_uri);

// Gets MIME type from a content URI. Returns an empty string if the URI is
// invalid.
BRICK_EXPORT std::string GetContentUriMimeType(const FilePath& content_uri);

}  // namespace base

#endif  // BRICK_ANDROID_CONTENT_URI_UTILS_H_
