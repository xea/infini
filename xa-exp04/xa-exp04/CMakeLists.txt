cmake_minimum_required(VERSION 3.8)

project("xa-exp04")

file(GLOB_RECURSE source "src/*.cpp" "src/*.h")

add_executable(xa-exp04 ${source})
find_library(GLFW_LIB glfw)
find_library(GLEW_LIB glew)
#add_library(glfw SHARED IMPORTED)
#add_library(glew SHARED IMPORTED)
link_directories(../../lib/glfw-3.2.1/lib/OSX)
include_directories(./src)
include_directories(../../lib/glew-2.0.0/include)
include_directories(../../lib/glfw-3.2.1/include)
include_directories(../../lib/glm-0.9.8.4)
target_compile_features(xa-exp04 PRIVATE cxx_std_17)
target_link_libraries(xa-exp04 "${GLFW_LIB}" "${GLEW_LIB}")

if (APPLE)
    target_link_libraries(xa-exp04 "-framework OpenGL")
endif()
