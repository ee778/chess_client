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
find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(Utils STATIC
  utils.cpp
  include/utils.h
  include/cconfig.h
  cconfig.cpp
  include/global.h
  global.cpp
)

get_target_property(utils_qt_version Utils QT_MAJOR_VERSION)
message("Utils QT version: ${utils_qt_version}")

target_link_libraries(Utils PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(Utils PRIVATE Qt6::Core)
target_link_libraries(Utils PRIVATE Qt6::Core)

# 设置公共头文件目录（以供其他库使用）
target_include_directories(Utils PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

target_compile_definitions(Utils PRIVATE UTILS_LIBRARY)
