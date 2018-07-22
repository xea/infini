cmake_minimum_required(VERSION 3.8)

project("xa-exp05")

file(GLOB_RECURSE source "src/*.cpp" "include/*.h")

add_executable(xa-exp05 ${source})
find_library(GLFW_LIB glfw)
find_library(GLEW_LIB glew)
#add_library(glfw SHARED IMPORTED)
#add_library(glew SHARED IMPORTED)
link_directories(../../lib/glfw-3.2.1/lib/OSX)
include_directories(./include)
include_directories(../../lib/glew-2.0.0/include)
include_directories(../../lib/glfw-3.2.1/include)
include_directories(../../lib/glm-0.9.8.4)
include_directories(../../lib/neither/neither/include)
target_compile_features(xa-exp05 PRIVATE cxx_std_17)
target_link_libraries(xa-exp05 "${GLFW_LIB}" "${GLEW_LIB}")

if (APPLE)
    target_link_libraries(xa-exp05 "-framework OpenGL")
endif()
