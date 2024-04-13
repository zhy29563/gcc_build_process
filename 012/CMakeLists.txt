CMAKE_MINIMUM_REQUIRED(VERSION 3.10)
PROJECT(cmake_examples)

SET(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(my_math)

add_executable(my_math_static_test my_math_test.c) 
target_link_libraries(my_math_static_test PRIVATE my_math_static)

add_executable(my_math_shared_test my_math_test.c)
target_link_libraries(my_math_shared_test PRIVATE my_math_shared)