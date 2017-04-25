cmake_minimum_required(VERSION 3.8)

project("xa-exp03")

file(GLOB_RECURSE source "xa-exp03.cpp" "xa-exp03.h" "engine/*.h" "engine/*.cpp" "model/*.cpp" "model/*.h")

add_executable(xa-exp03 ${source})
find_library(GLFW_LIB glfw)
find_library(GLEW_LIB glew)
#add_library(glfw SHARED IMPORTED)
#add_library(glew SHARED IMPORTED)
link_directories(../../lib/glfw-3.2.1/lib/OSX)
include_directories(.)
include_directories(../../lib/glew-2.0.0/include)
include_directories(../../lib/glfw-3.2.1/include)
target_compile_features(xa-exp03 PRIVATE cxx_std_17)
target_link_libraries(xa-exp03 "${GLFW_LIB}" "${GLEW_LIB}")

if (APPLE)
    target_link_libraries(xa-exp03 "-framework OpenGL")
endif()
