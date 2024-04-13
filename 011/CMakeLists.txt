CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(cmake_examples)

# 注意：
# 	在CMake中，命令不区分大小写，参数区分大小写
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

add_library(my_math_static STATIC my_math.c)
add_library(my_math_shared SHARED my_math.c)

add_executable(my_math_static_test my_math_test.c)
target_link_libraries(my_math_static_test PRIVATE my_math_static)

add_executable(my_math_shared_test my_math_test.c)
target_link_libraries(my_math_shared_test PRIVATE my_math_shared)