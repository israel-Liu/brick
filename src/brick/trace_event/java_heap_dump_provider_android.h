// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TRACE_EVENT_JAVA_HEAP_DUMP_PROVIDER_ANDROID_H_
#define BRICK_TRACE_EVENT_JAVA_HEAP_DUMP_PROVIDER_ANDROID_H_

#include "brick/macros.h"
#include "brick/memory/singleton.h"
#include "brick/trace_event/memory_dump_provider.h"

namespace base {
namespace trace_event {

// Dump provider which collects process-wide memory stats.
class BRICK_EXPORT JavaHeapDumpProvider : public MemoryDumpProvider {
 public:
  static JavaHeapDumpProvider* GetInstance();

  // MemoryDumpProvider implementation.
  bool OnMemoryDump(const MemoryDumpArgs& args,
                    ProcessMemoryDump* pmd) override;

 private:
  friend struct DefaultSingletonTraits<JavaHeapDumpProvider>;

  JavaHeapDumpProvider();
  ~JavaHeapDumpProvider() override;

  DISALLOW_COPY_AND_ASSIGN(JavaHeapDumpProvider);
};

}  // namespace trace_event
}  // namespace base

#endif  // BRICK_TRACE_EVENT_JAVA_HEAP_DUMP_PROVIDER_ANDROID_H_
