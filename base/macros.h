#ifndef BRICK_BASE_MACROS_H_
#define BRICK_BASE_MACROS_H_

#define DISALLOW_COPY_AND_ASSIGN(class_name)              \
    class_name(const class_name&) = delete;               \
    class_name& operator=(class_name&) = delete;          \
    class_name& operator=(const class_name&) = delete;

#define DISALLOW_MOVE_AND_ASSIGN(class_name)              \
    class_name(const class_name&&) = delete;              \
    class_name& operator=(class_name&&) = delete;         \

#endif // !BRICK_BASE_MACROS_H_
