// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_TRACE_EVENT_TRACE_EVENT_ARGUMENT_H_
#define BRICK_TRACE_EVENT_TRACE_EVENT_ARGUMENT_H_

#include <stddef.h>

#include <memory>
#include <string>
#include <vector>

#include "brick/macros.h"
#include "brick/pickle.h"
#include "brick/strings/string_piece.h"
#include "brick/trace_event/trace_event_impl.h"

namespace base {

class Value;

namespace trace_event {

class BRICK_EXPORT TracedValue : public ConvertableToTraceFormat {
 public:
  TracedValue();
  explicit TracedValue(size_t capacity);
  ~TracedValue() override;

  void EndDictionary();
  void EndArray();

  // These methods assume that |name| is a long lived "quoted" string.
  void SetInteger(const char* name, int value);
  void SetDouble(const char* name, double value);
  void SetBoolean(const char* name, bool value);
  void SetString(const char* name, base::StringPiece value);
  void SetValue(const char* name, const TracedValue& value);
  void BeginDictionary(const char* name);
  void BeginArray(const char* name);

  // These, instead, can be safely passed a temporary string.
  void SetIntegerWithCopiedName(base::StringPiece name, int value);
  void SetDoubleWithCopiedName(base::StringPiece name, double value);
  void SetBooleanWithCopiedName(base::StringPiece name, bool value);
  void SetStringWithCopiedName(base::StringPiece name,
                               base::StringPiece value);
  void SetValueWithCopiedName(base::StringPiece name,
                              const TracedValue& value);
  void BeginDictionaryWithCopiedName(base::StringPiece name);
  void BeginArrayWithCopiedName(base::StringPiece name);

  void AppendInteger(int);
  void AppendDouble(double);
  void AppendBoolean(bool);
  void AppendString(base::StringPiece);
  void BeginArray();
  void BeginDictionary();

  // ConvertableToTraceFormat implementation.
  void AppendAsTraceFormat(std::string* out) const override;

  void EstimateTraceMemoryOverhead(TraceEventMemoryOverhead* overhead) override;

  // DEPRECATED: do not use, here only for legacy reasons. These methods causes
  // a copy-and-translation of the base::Value into the equivalent TracedValue.
  // TODO(primiano): migrate the (three) existing clients to the cheaper
  // SetValue(TracedValue) API. crbug.com/495628.
  void SetValue(const char* name, std::unique_ptr<base::Value> value);
  void SetBaseValueWithCopiedName(base::StringPiece name,
                                  const base::Value& value);
  void AppendBaseValue(const base::Value& value);

  // Public for tests only.
  std::unique_ptr<base::Value> ToBaseValue() const;

 private:
  Pickle pickle_;

#ifndef NDEBUG
  // In debug builds checks the pairings of {Start,End}{Dictionary,Array}
  std::vector<bool> nesting_stack_;
#endif

  DISALLOW_COPY_AND_ASSIGN(TracedValue);
};

}  // namespace trace_event
}  // namespace base

#endif  // BRICK_TRACE_EVENT_TRACE_EVENT_ARGUMENT_H_
