cmake_minimum_required(VERSION 3.16)

project(HttpClient LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Network)

find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Core)

add_library(HttpClient STATIC
  httpclient.cpp
  include/httpclient.h
  include/httpservice.h
  httpservice.cpp
  include/IHttpClient.h
  include/mockhttpclient.h mockhttpclient.cpp
  include/messagebuilder.h messagebuilder.cpp
  include/messageparser.h messageparser.cpp
)

#message("cmake-current-soure-dir:" ${CMAKE_CURRENT_SOURCE_DIR}/../Utils)

# 暴露接口
target_include_directories(HttpClient PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(HttpClient PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Network)

# 连接公共库
target_link_libraries(HttpClient PUBLIC
  Utils
)
target_compile_definitions(HttpClient PRIVATE HTTPCLIENT_LIBRARY)
