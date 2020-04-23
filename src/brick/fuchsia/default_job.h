// Copyright 2017 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_FUCHSIA_DEFAULT_JOB_H_
#define BRICK_FUCHSIA_DEFAULT_JOB_H_

#include "brick/base_export.h"
#include "brick/fuchsia/scoped_zx_handle.h"

namespace base {

// Gets and sets the job object used for creating new child processes,
// and looking them up by their process IDs.
// zx_job_default() will be returned if no job is explicitly set here.
// Only valid handles may be passed to SetDefaultJob().
BRICK_EXPORT zx_handle_t GetDefaultJob();
BRICK_EXPORT void SetDefaultJob(ScopedZxHandle job);

}  // namespace base

#endif  // BRICK_FUCHSIA_DEFAULT_JOB_H_
