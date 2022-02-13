cmake_minimum_required(VERSION 3.20.00)
project(ModernCpp)

add_definitions("-std=c++11")

#include(${CMAKE_SOURCE_DIR}/conanbuildinfo.cmake)
#conan_basic_setup()

include_directories(${CMAKE_SOURCE_DIR}/inc)
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/Cpp11/*.cpp)
message(STATUS " Source files: ${CMAKE_SOURCE_DIR}")

add_executable(cpp11-tests ${SRC_FILES})
#target_link_libraries(cpp11-tests ${CONAN_LIBS})