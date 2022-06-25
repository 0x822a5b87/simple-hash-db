cmake_minimum_required (VERSION 2.6)

project (simple-hash-db)

set(CMAKE_CXX_STANDARD 11)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif()



add_executable(simple-hash-db main.cpp)