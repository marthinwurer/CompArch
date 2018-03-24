cmake_minimum_required(VERSION 3.5)
project(p1)

set(CMAKE_CXX_STANDARD 98)

include_directories(${CMAKE_SOURCE_DIR}/archlib)
link_directories(${CMAKE_SOURCE_DIR}/archlib)

add_executable(k19 k19.cpp globals.cpp globals.h addressing.cpp addressing.h opcodes.cpp opcodes.h)
target_link_libraries(k19 arch2-5a)