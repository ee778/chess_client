cmake_minimum_required(VERSION 3.16)

project(DbServer LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(DbServer STATIC
  dbserver.cpp
  dbserver.h
)

target_link_libraries(DbServer PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(DbServer PRIVATE DBSERVER_LIBRARY)
