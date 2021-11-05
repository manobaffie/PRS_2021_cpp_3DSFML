cmake_minimum_required(VERSION 3.0)

project(3Dlib)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(3Dlib_bin 3Dlib)
set(src_dir src)
set(include_dir include)

set(3Dlib_src
        ${src_dir}/main.cpp

        ${src_dir}/core/core.cpp

        ${src_dir}/loadObject/loadObject.cpp

        ${src_dir}/object/object.cpp
        ${src_dir}/object/cube/cube.cpp

        ${src_dir}/render3D/render3D.cpp)

include_directories(${include_dir})
add_executable(${3Dlib_bin} ${3Dlib_src})
add_compile_options(-Wall -Wextra -Werror)

target_link_libraries(${3Dlib_bin} -fPIC -ldl)
