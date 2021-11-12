cmake_minimum_required(VERSION 3.0)

project(a.out)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(a.out_bin a.out)
set(src_dir ./../c++/src)
set(include_dir include)

set(a.out_src
        ${src_dir}/main.cpp

        ${src_dir}/../lib/Parsing/Parsing.cpp

        ${src_dir}/Core/Core.cpp

        ${src_dir}/Engine/Engine.cpp

        ${src_dir}/Object/Object.cpp
        ${src_dir}/Object/Blender/Blender.cpp)
        # ${src_dir}/Object/Cube/Cube.cpp)

include_directories(${include_dir})
add_executable(${a.out_bin} ${a.out_src})
add_compile_options(-Wall -Wextra -Werror -g3)

target_link_libraries(${a.out_bin} -fPIC -ldl)
