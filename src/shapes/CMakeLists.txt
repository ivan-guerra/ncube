cmake_minimum_required(VERSION 3.16)

project(
  shapes
  DESCRIPTION "shape definitions"
  LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE cube.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${NSHAPES_INCLUDE_DIR})
