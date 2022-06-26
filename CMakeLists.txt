cmake_minimum_required(VERSION 3.17)

project(simple-hash-db)

set(CMAKE_CXX_STANDARD 11)

if (CMAKE_C_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -ansi -pedantic -Wall")
endif ()

include(FetchContent)
FetchContent_Declare(jsoncpp
        URL https://github.com/open-source-parsers/jsoncpp/archive/1.9.4.tar.gz)
FetchContent_MakeAvailable(jsoncpp)

add_executable(${PROJECT_NAME} main.cpp core storage)

target_link_libraries(${PROJECT_NAME} jsoncpp_lib)