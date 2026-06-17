cmake_minimum_required(VERSION 3.16)
project(MyLeetcode C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ---------- 默认构建类型 ----------
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type" FORCE)
endif()

# ---------- 编译选项（开启警告） ----------
if(CMAKE_C_COMPILER_ID MATCHES "GNU|Clang|MinGW")
    add_compile_options(-Wall -Wextra -Wpedantic)
    if(CMAKE_BUILD_TYPE STREQUAL "Release")
        add_compile_options(-O3)
    else()
        add_compile_options(-O0 -g)
    endif()
endif()

# ---------- 自动收集所有 LC_* 目录 ----------
file(GLOB LC_DIRS LIST_DIRECTORIES true ${PROJECT_SOURCE_DIR}/LC_*)

set(ALL_SRC "")       # 所有源文件
set(ALL_INC "")       # 所有头文件搜索路径

# 加入项目根目录（支持 #include "public.h" 这种写法）
list(APPEND ALL_INC ${PROJECT_SOURCE_DIR})

# 遍历每个 LC_* 目录
foreach(dir ${LC_DIRS})
    if(IS_DIRECTORY ${dir})
        list(APPEND ALL_INC ${dir})               # 添加头文件路径
        aux_source_directory(${dir} DIR_SRC)      # 收集 .c 源文件
        list(APPEND ALL_SRC ${DIR_SRC})
    endif()
endforeach()

# ---------- 设置头文件搜索路径 ----------
include_directories(${ALL_INC})

# ---------- 生成可执行文件 ----------
add_executable(MyLeetcode main.c ${ALL_SRC})