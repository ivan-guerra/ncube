cmake_minimum_required(VERSION 3.16)

add_executable(${CMAKE_PROJECT_NAME})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE nshapes.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE common graphics shapes)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${NSHAPES_BIN_DIR}")
