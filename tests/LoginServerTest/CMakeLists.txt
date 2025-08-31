cmake_minimum_required(VERSION 3.16)

project(tst_LoginServer LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Network Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Network Core)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(tst_LoginServer tst_tst_loginserver.cpp)

add_test(NAME tst_LoginServer COMMAND tst_LoginServer)


target_link_libraries(tst_LoginServer PRIVATE
    Qt${QT_VERSION_MAJOR}::Test
    Qt${QT_VERSION_MAJOR}::Core
    LoginServer
    Qt${QT_VERSION_MAJOR}::Network)

