cmake_minimum_required(VERSION 3.16)

project(
  common
  DESCRIPTION "shared coordinates types and utilities"
  LANGUAGES CXX)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME} PRIVATE util.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${NCUBE_INCLUDE_DIR})
