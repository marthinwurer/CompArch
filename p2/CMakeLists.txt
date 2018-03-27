cmake_minimum_required(VERSION 3.5)
project(p1)

set(CMAKE_CXX_STANDARD 98)

include_directories(${CMAKE_SOURCE_DIR}/archlib)
link_directories(${CMAKE_SOURCE_DIR}/archlib)

add_executable(pdp11 pdp11.cpp globals.cpp globals.h addressing.cpp addressing.h setup.cpp setup.h decode.cpp decode.h)
target_link_libraries(pdp11 arch2-5a)