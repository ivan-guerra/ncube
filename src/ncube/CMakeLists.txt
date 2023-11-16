cmake_minimum_required(VERSION 3.16)

add_executable(${CMAKE_PROJECT_NAME})

target_sources(${CMAKE_PROJECT_NAME} PRIVATE ncube.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE common graphics cube)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION "${NCUBE_BIN_DIR}")
