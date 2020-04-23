// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_STRINGS_STRINGPRINTF_H_
#define BRICK_STRINGS_STRINGPRINTF_H_

#include <stdarg.h>   // va_list

#include <string>

#include "brick/base_export.h"
#include "brick/compiler_specific.h"
#include "build/build_config.h"

namespace base {

// Return a C++ string given printf-like input.
BRICK_EXPORT std::string StringPrintf(_Printf_format_string_ const char* format,
                                     ...)
    PRINTF_FORMAT(1, 2) WARN_UNUSED_RESULT;
#if defined(OS_WIN)
BRICK_EXPORT std::wstring StringPrintf(
    _Printf_format_string_ const wchar_t* format,
    ...) WPRINTF_FORMAT(1, 2) WARN_UNUSED_RESULT;
#endif

// Return a C++ string given vprintf-like input.
BRICK_EXPORT std::string StringPrintV(const char* format, va_list ap)
    PRINTF_FORMAT(1, 0) WARN_UNUSED_RESULT;

// Store result into a supplied string and return it.
BRICK_EXPORT const std::string& SStringPrintf(
    std::string* dst,
    _Printf_format_string_ const char* format,
    ...) PRINTF_FORMAT(2, 3);
#if defined(OS_WIN)
BRICK_EXPORT const std::wstring& SStringPrintf(
    std::wstring* dst,
    _Printf_format_string_ const wchar_t* format,
    ...) WPRINTF_FORMAT(2, 3);
#endif

// Append result to a supplied string.
BRICK_EXPORT void StringAppendF(std::string* dst,
                               _Printf_format_string_ const char* format,
                               ...) PRINTF_FORMAT(2, 3);
#if defined(OS_WIN)
BRICK_EXPORT void StringAppendF(std::wstring* dst,
                               _Printf_format_string_ const wchar_t* format,
                               ...) WPRINTF_FORMAT(2, 3);
#endif

// Lower-level routine that takes a va_list and appends to a specified
// string.  All other routines are just convenience wrappers around it.
BRICK_EXPORT void StringAppendV(std::string* dst, const char* format, va_list ap)
    PRINTF_FORMAT(2, 0);
#if defined(OS_WIN)
BRICK_EXPORT void StringAppendV(std::wstring* dst,
                               const wchar_t* format, va_list ap)
    WPRINTF_FORMAT(2, 0);
#endif

}  // namespace base

#endif  // BRICK_STRINGS_STRINGPRINTF_H_
