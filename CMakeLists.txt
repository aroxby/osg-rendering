cmake_minimum_required(VERSION 2.6)

set(PROJECT_NAME osg-rendering)

project(${PROJECT_NAME})

find_package(OpenSceneGraph REQUIRED osgViewer)

file(GLOB SRCS *.cpp)

include_directories(${OPENSCENEGRAPH_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${SRCS})

target_link_libraries(${PROJECT_NAME} ${OPENSCENEGRAPH_LIBRARIES})