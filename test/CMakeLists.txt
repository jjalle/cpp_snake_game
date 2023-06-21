cmake_minimum_required(VERSION 3.1)
project(Game.Test)

# Google test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    ${PATH_TEST}/test_map.cpp
    ${PATH_TEST}/test_event.cpp
    ${PATH_TEST}/test_snake.cpp
    ${PATH_TEST}/main.cpp
)

add_dependencies(${PROJECT_NAME} Game)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Game
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})


