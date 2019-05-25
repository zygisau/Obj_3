cmake_minimum_required(VERSION 3.13)
project(Duomenu_apdorojimas)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "../build")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3")
add_executable(Duomenu_apdorojimas source_vektoriai.cpp)

include_directories(src)
add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(Duomenu_apdorojimas src)