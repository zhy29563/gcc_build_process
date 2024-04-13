add_library(my_math_static STATIC "")
target_sources(my_math_static
               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/my_math.c
               PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/my_math.h)

add_library(my_math_shared SHARED "")
target_sources(my_math_shared
               PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/my_math.c
               PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/my_math.h)

# PRIVATE : 源文件只是在构建库文件是使用
# PUBLIC  : 头文件在构建和编译时都会使用，则在使用该库是不需要显式包含my_math.h所在的文件夹