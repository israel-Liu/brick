// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TRACE_EVENT_MEMORY_DUMP_PROVIDER_H_
#define BRICK_TRACE_EVENT_MEMORY_DUMP_PROVIDER_H_

#include "brick/base_export.h"
#include "brick/macros.h"
#include "brick/process/process_handle.h"
#include "brick/trace_event/memory_dump_request_args.h"

namespace base {
namespace trace_event {

class ProcessMemoryDump;

// The contract interface that memory dump providers must implement.
class BRICK_EXPORT MemoryDumpProvider {
 public:
  // Optional arguments for MemoryDumpManager::RegisterDumpProvider().
  struct Options {
    Options() : dumps_on_single_thread_task_runner(false) {}

    // |dumps_on_single_thread_task_runner| is true if the dump provider runs on
    // a SingleThreadTaskRunner, which is usually the case. It is faster to run
    // all providers that run on the same thread together without thread hops.
    bool dumps_on_single_thread_task_runner;
  };

  virtual ~MemoryDumpProvider() = default;

  // Called by the MemoryDumpManager when generating memory dumps.
  // The |args| specify if the embedder should generate light/heavy dumps on
  // dump requests. The embedder should return true if the |pmd| was
  // successfully populated, false if something went wrong and the dump should
  // be considered invalid.
  // (Note, the MemoryDumpManager has a fail-safe logic which will disable the
  // MemoryDumpProvider for the entire trace session if it fails consistently).
  virtual bool OnMemoryDump(const MemoryDumpArgs& args,
                            ProcessMemoryDump* pmd) = 0;

 protected:
  MemoryDumpProvider() = default;

  DISALLOW_COPY_AND_ASSIGN(MemoryDumpProvider);
};

}  // namespace trace_event
}  // namespace base

#endif  // BRICK_TRACE_EVENT_MEMORY_DUMP_PROVIDER_H_
