cmake_minimum_required(VERSION 3.20)
project(physengine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package (Eigen3 REQUIRED NO_MODULE)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

add_executable(main main.cpp)

add_executable(test_rectangle test_rectangle.cpp)
target_include_directories(test_rectangle PUBLIC src)
target_link_libraries (test_rectangle Eigen3::Eigen ${SDL2_LIBRARIES})

add_executable(test_rendering_engine test_rendering_engine.cpp)
target_include_directories(test_rendering_engine PUBLIC src)
target_link_libraries (test_rendering_engine Eigen3::Eigen ${SDL2_LIBRARIES})
