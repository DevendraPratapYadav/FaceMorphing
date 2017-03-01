cmake_minimum_required(VERSION 2.8.12)

project(lab4)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(lab4 FaceMorph.cpp)
target_link_libraries(lab4 ${OpenCV_LIBS})
