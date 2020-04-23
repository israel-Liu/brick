// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file ensures that these header files don't include Windows.h and can
// compile without including Windows.h. This helps to improve compile times.

#include "brick/atomicops.h"
#include "brick/files/file_util.h"
#include "brick/files/platform_file.h"
#include "brick/process/process_handle.h"
#include "brick/synchronization/condition_variable.h"
#include "brick/synchronization/lock.h"
#include "brick/threading/platform_thread.h"
#include "brick/threading/thread_local_storage.h"
#include "brick/win/registry.h"
#include "brick/win/scoped_handle.h"
#include "brick/win/win_util.h"

#ifdef _WINDOWS_
#error Windows.h was included inappropriately.
#endif

// Make sure windows.h can be included after windows_types.h
#include "brick/win/windows_types.h"

#include <windows.h>

// Check that type sizes match.
static_assert(sizeof(CHROME_CONDITION_VARIABLE) == sizeof(CONDITION_VARIABLE),
              "Definition mismatch.");
static_assert(sizeof(CHROME_SRWLOCK) == sizeof(SRWLOCK),
              "Definition mismatch.");
