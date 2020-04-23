// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BRICK_MESSAGE_LOOP_MESSAGE_PUMP_FOR_IO_H_
#define BRICK_MESSAGE_LOOP_MESSAGE_PUMP_FOR_IO_H_

// This header is a forwarding header to coalesce the various platform specific
// types representing MessagePumpForIO.

#include "build/build_config.h"

#if defined(OS_WIN)
#include "brick/message_loop/message_pump_win.h"
#elif defined(OS_IOS)
#include "brick/message_loop/message_pump_io_ios.h"
#elif defined(OS_NACL_SFI)
#include "brick/message_loop/message_pump_default.h"
#elif defined(OS_FUCHSIA)
#include "brick/message_loop/message_pump_fuchsia.h"
#elif defined(OS_POSIX)
#include "brick/message_loop/message_pump_libevent.h"
#endif

namespace base {

#if defined(OS_WIN)
// Windows defines it as-is.
using MessagePumpForIO = MessagePumpForIO;
#elif defined(OS_IOS)
using MessagePumpForIO = MessagePumpIOSForIO;
#elif defined(OS_NACL_SFI)
using MessagePumpForIO = MessagePumpDefault;
#elif defined(OS_FUCHSIA)
using MessagePumpForIO = MessagePumpFuchsia;
#elif defined(OS_POSIX)
using MessagePumpForIO = MessagePumpLibevent;
#else
#error Platform does not define MessagePumpForIO
#endif

}  // namespace base

#endif  // BRICK_MESSAGE_LOOP_MESSAGE_PUMP_FOR_IO_H_
