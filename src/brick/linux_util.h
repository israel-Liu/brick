// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_LINUX_UTIL_H_
#define BRICK_LINUX_UTIL_H_

#include <stdint.h>
#include <sys/types.h>

#include <string>

#include "brick/base_export.h"

namespace base {

// This is declared here so the crash reporter can access the memory directly
// in compromised context without going through the standard library.
BRICK_EXPORT extern char g_linux_distro[];

// Get the Linux Distro if we can, or return "Unknown".
BRICK_EXPORT std::string GetLinuxDistro();

// Set the Linux Distro string.
BRICK_EXPORT void SetLinuxDistro(const std::string& distro);

// For a given process |pid|, look through all its threads and find the first
// thread with /proc/[pid]/task/[thread_id]/syscall whose first N bytes matches
// |expected_data|, where N is the length of |expected_data|.
// Returns the thread id or -1 on error.  If |syscall_supported| is
// set to false the kernel does not support syscall in procfs.
BRICK_EXPORT pid_t FindThreadIDWithSyscall(pid_t pid,
                                          const std::string& expected_data,
                                          bool* syscall_supported);

// For a given process |pid|, look through all its threads and find the first
// thread with /proc/[pid]/task/[thread_id]/status where NSpid matches |ns_tid|.
// Returns the thread id or -1 on error.  If |ns_pid_supported| is
// set to false the kernel does not support NSpid in procfs.
BRICK_EXPORT pid_t FindThreadID(pid_t pid, pid_t ns_tid, bool* ns_pid_supported);

}  // namespace base

#endif  // BRICK_LINUX_UTIL_H_
