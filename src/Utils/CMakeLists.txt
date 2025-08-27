cmake_minimum_required(VERSION 3.16)

project(Utils LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(Utils STATIC
  utils.cpp
  utils.h
  cconfig.h cconfig.cpp
)

get_target_property(utils_qt_version Utils QT_MAJOR_VERSION)
message("Utils QT version: ${utils_qt_version}")

target_link_libraries(Utils PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Utils PRIVATE Qt6::Core)

target_compile_definitions(Utils PRIVATE UTILS_LIBRARY)
