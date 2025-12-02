cmake_minimum_required(VERSION 3.10)
project(aoc2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTEST REQUIRED gtest)
if(NOT GTEST_FOUND)
  message(FATAL_ERROR "failed to find gtest on system ")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)

enable_testing()

file(GLOB UTILS_SRC "utils/*.cpp")
add_library(utils STATIC ${UTILS_SRC})


file(GLOB DAY1_SRC "day1/*.cpp")
list(APPEND TEST_SRC ${DAY1_SRC})
list(APPEND D1P1_SRC ${DAY1_SRC})
list(APPEND D1P2_SRC ${DAY1_SRC})

list(FILTER D1P1_SRC EXCLUDE REGEX "(test|part2).cpp")
list(FILTER D1P2_SRC EXCLUDE REGEX "(test|part1).cpp")

add_executable(day1-part1 ${D1P1_SRC})
target_link_libraries(day1-part1 PRIVATE utils)

add_executable(day1-part2 ${D1P2_SRC})
target_link_libraries(day1-part2 PRIVATE utils)

list(FILTER TEST_SRC EXCLUDE REGEX "part[12].cpp")
list(APPEND TEST_SRC "tests/main.cpp")

add_executable(day1-tests)
target_sources(day1-tests PRIVATE ${TEST_SRC})

target_link_libraries(day1-tests PRIVATE ${GTEST_LDFLAGS})
target_compile_options(day1-tests PRIVATE ${GTEST_CFLAGS})

add_test(day1-test-suite day1-tests)

