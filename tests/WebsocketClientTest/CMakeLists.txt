cmake_minimum_required(VERSION 3.16)

project(WebsocketClientTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test WebSockets Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test WebSockets Network)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(WebsocketClientTest tst_websocketclienttest.cpp)
add_test(NAME WebsocketClientTest COMMAND WebsocketClientTest)
target_include_directories(WebsocketClientTest PRIVATE ../../src/WebsocketClient)

target_link_libraries(WebsocketClientTest PRIVATE
    Qt${QT_VERSION_MAJOR}::Test
    WebsocketClient
    Qt${QT_VERSION_MAJOR}::WebSockets
    Qt${QT_VERSION_MAJOR}::Network)

