cmake_minimum_required(VERSION 3.0)

project(3Dlib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(3Dlib_bin 3Dlib)
set(src_dir src)
set(include_dir include)

set(3Dlib_src
        ${src_dir}/main.cpp

        ${src_dir}/../lib/Parsing/Parsing.cpp

        ${src_dir}/Core/Core.cpp

        ${src_dir}/Engine/Engine.cpp

        ${src_dir}/Object/Object.cpp
        ${src_dir}/Object/Blender/Blender.cpp
        ${src_dir}/Object/Cube/Cube.cpp)

include_directories(${include_dir})
add_executable(${3Dlib_bin} ${3Dlib_src})
add_compile_options(-Wall -Wextra -Werror -g3)

target_link_libraries(${3Dlib_bin} -fPIC -ldl)
