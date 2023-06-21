cmake_minimum_required(VERSION 3.1)
project(Game)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
    ${PATH_LIB_INCLUDE}/Config.h
    ${PATH_LIB_INCLUDE}/Event.h
    ${PATH_LIB_INCLUDE}/Food.h
    ${PATH_LIB_INCLUDE}/Game.h
    ${PATH_LIB_INCLUDE}/Input.h
    ${PATH_LIB_INCLUDE}/Map.h
    ${PATH_LIB_INCLUDE}/Snake.h
    ${PATH_LIB_INCLUDE}/World.h
    ${PATH_LIB_SRC}/Config.cpp
    ${PATH_LIB_SRC}/Event.cpp
    ${PATH_LIB_SRC}/Food.cpp
    ${PATH_LIB_SRC}/Game.cpp
    ${PATH_LIB_SRC}/Input.cpp
    ${PATH_LIB_SRC}/Map.cpp
    ${PATH_LIB_SRC}/Snake.cpp
    ${PATH_LIB_SRC}/World.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PATH_LIB_INCLUDE}
    ${PATH_SDL_INCLUDE}
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    SDL2::SDL2
)