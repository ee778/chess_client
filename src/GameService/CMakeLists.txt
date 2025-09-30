cmake_minimum_required(VERSION 3.16)

project(GameService LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_library(GameService SHARED
  GameService_global.h
  gameservice.cpp
  gameservice.h
  Board.h Board.cpp
  Stone.h Stone.cpp
  IGoRules.h
  GameStatus.h GameStatus.cpp
  gorulesbychinese.h gorulesbychinese.cpp
)

target_link_libraries(GameService PRIVATE Qt${QT_VERSION_MAJOR}::Core)

target_compile_definitions(GameService PRIVATE GAMESERVICE_LIBRARY)
