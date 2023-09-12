cmake_minimum_required(VERSION 3.0)

project(a.out)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(a.out_bin a.out)

set(src_dir ./../c++/src)

set(src_hpp
        ${src_dir}/Graph/Graph.hpp
        ${src_dir}/Graph/Sfml/Sfml.hpp
        ${src_dir}/vector/vector.hpp
        ${src_dir}/Game/Instance/Base/Base.hpp
        ${src_dir}/Game/Instance/Visual/Visual.hpp
        ${src_dir}/Game/Instance/Entity/Entity.hpp
        ${src_dir}/MyGame/Instance/Visual/Visual.hpp
)

set(src_cpp
        ${src_dir}/main.cpp
        ${src_dir}/Graph/Sfml/Sfml.cpp
        ${src_dir}/Game/Instance/Base/Base.cpp
        ${src_dir}/Game/Instance/Visual/Visual.cpp
        ${src_dir}/Game/Instance/Entity/Entity.cpp
        ${src_dir}/MyGame/Instance/Visual/Visual.cpp
)

add_executable(${a.out_bin} ${src_cpp} ${src_hpp})
add_compile_options(-Wall -Wextra -Werror -g3)

target_link_libraries(${a.out_bin} -fPIC -ldl -lsfml-graphics -lsfml-window -lsfml-system)
