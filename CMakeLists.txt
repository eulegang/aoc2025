cmake_minimum_required(VERSION 3.10)
project(aoc2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)


file(GLOB UTILS_SRC "utils/*.cpp")
add_library(utils STATIC ${UTILS_SRC})

file(GLOB DAY1_SRC "day1/*.cpp")
add_executable(d1 ${DAY1_SRC})
target_link_libraries(d1 PRIVATE utils)

