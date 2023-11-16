cmake_minimum_required(VERSION 3.16)

project(
  cube
  DESCRIPTION "representation of a 3D cube"
  LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE cube.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${NCUBE_INCLUDE_DIR})
