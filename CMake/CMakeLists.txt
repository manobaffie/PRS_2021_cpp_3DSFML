cmake_minimum_required(VERSION 3.0)

project(a.out)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(a.out_bin a.out)

set(src_dir ./../c++/src)
set(lib_dir ./../c++/lib)

set(
        a.out_src

        ${src_dir}/main.cpp
        ${src_dir}/Core/Core.cpp
        # ${src_dir}/Map/Map/Map.cpp

        ${src_dir}/GameObject/Cube/Cube.cpp
        ${src_dir}/GameObject/Tree/Tree.cpp
        ${src_dir}/GameObject/Player/Player.cpp
        ${src_dir}/GameObject/GameObject/GameObject.cpp

        ${src_dir}/Engine/Engine/Engine.cpp

        ${lib_dir}/libGraph/sfml/sfml.cpp
        ${lib_dir}/lib3D/Object/Blender/Blender.cpp

        ${lib_dir}/Parsing/Parsing.cpp
)

add_executable(${a.out_bin} ${a.out_src})
add_compile_options(-Wall -Wextra -Werror -g3)

target_link_libraries(${a.out_bin} -fPIC -ldl -pthread -lsfml-graphics -lsfml-window -lsfml-system)
