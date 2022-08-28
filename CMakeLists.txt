cmake_minimum_required(VERSION 3.16)

project(smallVM)

file(GLOB Sources src/*.c)

add_executable(smallVM ${Sources})
target_include_directories(smallVM PRIVATE src/)