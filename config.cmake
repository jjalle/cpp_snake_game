cmake_minimum_required(VERSION 3.1)

#--- Compiler Dependent Flags ---#
if(MSVC)
    # Hello mother - I am empty!

elseif(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    # Hello mother - I am empty!
else()
    Message(WARNING "unsupported compiler: ${CMAKE_CXX_COMPILER_ID}")
endif()

#--- Compiler Independent Flags ---#
if(WIN32)
    add_compile_definitions(_CRT_SECURE_NO_WARNINGS)
    add_compile_options(
        "$<$<CONFIG:Debug>:/MDd>"
        "$<$<CONFIG:RelWithDebInfo>:/MD>"
        "$<$<CONFIG:Release>:/MD>"
        "$<$<CONFIG:MinSizeRel>:/MD>"
    )
endif()

#---------------------#
#--- CPP Settings ---#
#-------------------#

# cpp17 is minimal requirement
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#--- Paths ---#
set(PATH_ROOT "${CMAKE_CURRENT_LIST_DIR}")
set(PATH_TEST "${PATH_ROOT}/test")
set(PATH_LIB_SRC "${PATH_ROOT}/game/src")
set(PATH_LIB_INCLUDE "${PATH_ROOT}/game/include")
set(PATH_EXE_SRC "${PATH_ROOT}/game.exe/src")
set(PATH_SDL_ROOT "${PATH_ROOT}/third_party/SDL")
set(PATH_SDL_INCLUDE "${PATH_SDL_ROOT}/include")
set(PATH_SDL_LIB "${PATH_SDL_ROOT}/lib/x64")

#--- CMake Settings ---#
# OUTPUT DIRECTORIES
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# minimize generated junk projects
set(CMAKE_SUPPRESS_REGENERATION true)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
