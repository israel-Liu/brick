#include "base/threads/mutex.h"

namespace brick
{
  constexpr mutex::mutex() noexcept
  { }

  mutex::~mutex()
  { }

  void mutex::lock()
  { }

  bool mutex::try_lock()
  {
    return false;
  }

  void mutex::unlock()
  { }

  // how to use using define type
  //native_handle_type mutex::native_handle()
  //{
  //  return native_handle_;
  //}
}
