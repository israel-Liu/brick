// Copyright (c) 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TEST_TRACE_TO_FILE_H_
#define BRICK_TEST_TRACE_TO_FILE_H_

#include "brick/files/file_path.h"

namespace base {
namespace test {

class TraceToFile {
 public:
  TraceToFile();
  ~TraceToFile();

  void BeginTracingFromCommandLineOptions();
  void BeginTracing(const base::FilePath& path, const std::string& categories);
  void EndTracingIfNeeded();

 private:
  void WriteFileHeader();
  void AppendFileFooter();

  void TraceOutputCallback(const std::string& data);

  base::FilePath path_;
  bool started_;
};

}  // namespace test
}  // namespace base

#endif  // BRICK_TEST_TRACE_TO_FILE_H_
