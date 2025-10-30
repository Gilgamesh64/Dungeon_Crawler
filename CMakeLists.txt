cmake_minimum_required(VERSION 3.16)  # Minimum CMake version
project(DUNGEON_CRAWLER C)                  # Project name and language

# Set the C standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories (so compiler knows where to find .h files)
include_directories(include)

# Gather all source files automatically
file(GLOB SOURCES "src/*.c")

# Define the executable
add_executable(DUNGEON_CRAWLER ${SOURCES})
