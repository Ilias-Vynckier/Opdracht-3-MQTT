cmake_minimum_required(VERSION 3.0.0)
project(Opdracht3 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(site.cgi site.c)
include_directories(/usr/include/mariadb /usr/include/mariadb/mysql)

target_link_libraries(site.cgi mariadb)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
