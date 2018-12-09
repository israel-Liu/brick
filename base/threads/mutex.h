#ifndef BRICK_BASE_THREADS_MUTEX_H_
#define BRICK_BASE_THREADS_MUTEX_H_

#include "base/win/windows_types.h"

namespace brick
{
  class mutex
  {
  public:
    constexpr mutex() noexcept;
    ~mutex();

    mutex(const mutex&) = delete;
    mutex& operator=(const mutex&) = delete;

    void lock();
    bool try_lock();
    void unlock();

    using native_handle_type = BRICK_SRWLOCK;
    native_handle_type native_handle()
    {
      return native_handle_;
    }

  private:
    native_handle_type native_handle_;
  };
}

#endif // !BRICK_BASE_THREADS_MUTEX_H_
