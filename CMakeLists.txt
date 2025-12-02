cmake_minimum_required(VERSION 3.10)
project(aoc2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTEST REQUIRED gtest)
if(NOT GTEST_FOUND)
  message(FATAL_ERROR "failed to find gtest on system")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)

enable_testing()

file(GLOB UTILS_SRC "utils/*.cpp")
add_library(utils STATIC ${UTILS_SRC})

set(FOLDERS day1)

foreach(FOLDER IN ITEMS ${FOLDERS})
  string(REGEX REPLACE "ay" "" PART ${FOLDER})

  file(GLOB ${PART}_SRC "${FOLDER}/*.cpp")
  list(APPEND ${PART}_TEST_SRC ${${PART}_SRC})
  list(APPEND ${PART}P1_SRC ${${PART}_SRC})
  list(APPEND ${PART}P2_SRC ${${PART}_SRC})

  list(FILTER ${PART}P1_SRC EXCLUDE REGEX "(test|part2).cpp")
  list(FILTER ${PART}P2_SRC EXCLUDE REGEX "(test|part1).cpp")

  add_executable(${PART}p1 ${${PART}P1_SRC})
  target_link_libraries(${PART}p1 PRIVATE utils)

  add_executable(${PART}p2 ${${PART}P2_SRC})
  target_link_libraries(${PART}p2 PRIVATE utils)

  list(FILTER ${PART}_TEST_SRC EXCLUDE REGEX "part[12].cpp")
  list(APPEND ${PART}_TEST_SRC "tests/main.cpp")

  add_executable(${FOLDER}-tests)
  target_sources(${FOLDER}-tests PRIVATE ${${PART}_TEST_SRC})

  target_link_libraries(${FOLDER}-tests PRIVATE ${GTEST_LDFLAGS})
  target_compile_options(${FOLDER}-tests PRIVATE ${GTEST_CFLAGS})

  add_test(${FOLDER}-tests ${FOLDER}-tests)
endforeach()
