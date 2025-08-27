cmake_minimum_required(VERSION 3.16)

project(HttpClientTest LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Test Network)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test Network)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(HttpClientTest tst_httpclienttest.cpp)
add_test(NAME HttpClientTest COMMAND HttpClientTest)
target_include_directories(HttpClientTest PRIVATE ../../src/HttpClient)

target_link_libraries(HttpClientTest PRIVATE
    Qt${QT_VERSION_MAJOR}::Test
    HttpClient
    Qt${QT_VERSION_MAJOR}::Network)

