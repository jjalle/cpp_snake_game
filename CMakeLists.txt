cmake_minimum_required(VERSION 3.13)
project(Game)
include("config.cmake")

add_subdirectory(game)
add_subdirectory(game.exe)
add_subdirectory(test)
add_subdirectory(third_party/SDL)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Game.Exe)
