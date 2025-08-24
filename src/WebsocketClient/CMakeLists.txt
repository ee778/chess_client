cmake_minimum_required(VERSION 3.16)

project(WebsocketClient LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core WebSockets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core WebSockets Network)

add_library(WebsocketClient STATIC
  websocketclient.cpp
  websocketclient.h
)

target_link_libraries(WebsocketClient PRIVATE Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::WebSockets
Qt${QT_VERSION_MAJOR}::Network)

target_compile_definitions(WebsocketClient PRIVATE WEBSOCKETCLIENT_LIBRARY)
