cmake_minimum_required(VERSION 3.0.0)
project(Opdracht3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(Opdracht3 main.c)

target_link_libraries(Opdracht3 paho-mqtt3c)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
