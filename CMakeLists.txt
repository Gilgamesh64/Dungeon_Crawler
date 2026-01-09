cmake_minimum_required(VERSION 3.16)

project(DC C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB SOURCES "src/*.c")

add_executable(DC ${SOURCES})

target_include_directories(DC PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/external/dirent
)