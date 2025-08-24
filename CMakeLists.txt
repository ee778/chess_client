cmake_minimum_required(VERSION 3.14)
project(chess_client VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(WITH_TESTS "Build with tests" ON)

# 添加主代码目录
add_subdirectory(src)

if (WITH_TESTS)
    # 添加测试目录
    message(STATUS "Building with tests enabled")
    enable_testing()
    add_subdirectory(tests)
else() 
    message(STATUS "Building without tests")
endif()

