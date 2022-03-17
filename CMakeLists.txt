cmake_minimum_required(VERSION 3.16)
project(iso-7816-tlv VERSION 0.1.0)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 20)
include(CPack)

add_subdirectory(src)
add_subdirectory(app)