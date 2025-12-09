cmake_minimum_required(VERSION 3.10)
project(aoc2025 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON) 

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTEST REQUIRED gtest)
if(NOT GTEST_FOUND)
  message(FATAL_ERROR "failed to find gtest on system")
endif()

pkg_check_modules(CHROMA REQUIRED chroma)
if(NOT CHROMA_FOUND)
  message(FATAL_ERROR "failed to find chroma on system")
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/utils)

enable_testing()

file(GLOB UTILS_SRC "utils/*.cpp")
list(FILTER UTILS_SRC EXCLUDE REGEX "test.cpp")
add_library(utils STATIC ${UTILS_SRC})

add_executable(utils-tests)
target_compile_features(utils-tests PRIVATE cxx_std_23) 
target_sources(utils-tests PRIVATE ${UTILS_SRC} utils/test.cpp tests/main.cpp)

target_link_libraries(utils-tests PRIVATE ${GTEST_LDFLAGS})
target_compile_options(utils-tests PRIVATE ${GTEST_CFLAGS})

add_test(utils-tests utils-tests)

set(FOLDERS day1 day2)

foreach(FOLDER IN ITEMS ${FOLDERS})
  string(REGEX REPLACE "ay" "" DAY_PREFIX ${FOLDER})

  file(GLOB ${DAY_PREFIX}_SRC "${FOLDER}/*.cpp")
  list(APPEND ${DAY_PREFIX}_TEST_SRC ${${DAY_PREFIX}_SRC})
  list(APPEND ${DAY_PREFIX}P1_SRC ${${DAY_PREFIX}_SRC})
  list(APPEND ${DAY_PREFIX}P2_SRC ${${DAY_PREFIX}_SRC})

  list(FILTER ${DAY_PREFIX}P1_SRC EXCLUDE REGEX "(test|part2).cpp")
  list(FILTER ${DAY_PREFIX}P2_SRC EXCLUDE REGEX "(test|part1).cpp")

  add_executable(${DAY_PREFIX}p1 ${${DAY_PREFIX}P1_SRC})
  target_link_libraries(${DAY_PREFIX}p1 PRIVATE utils)
  target_compile_features(${DAY_PREFIX}p1 PRIVATE cxx_std_23) 
  target_link_libraries(${DAY_PREFIX}p1 PRIVATE ${CHROMA_LDFLAGS})
  target_compile_options(${DAY_PREFIX}p1 PRIVATE ${CHROMA_CFLAGS})

  add_executable(${DAY_PREFIX}p2 ${${DAY_PREFIX}P2_SRC})
  target_link_libraries(${DAY_PREFIX}p2 PRIVATE utils)
  target_compile_features(${DAY_PREFIX}p2 PRIVATE cxx_std_23) 
  target_link_libraries(${DAY_PREFIX}p2 PRIVATE ${CHROMA_LDFLAGS})
  target_compile_options(${DAY_PREFIX}p2 PRIVATE ${CHROMA_CFLAGS})

  list(FILTER ${DAY_PREFIX}_TEST_SRC EXCLUDE REGEX "part[12].cpp")
  list(APPEND ${DAY_PREFIX}_TEST_SRC "tests/main.cpp")

  add_executable(${FOLDER}-tests)
  target_compile_features(${FOLDER}-tests PRIVATE cxx_std_23) 
  target_sources(${FOLDER}-tests PRIVATE ${${DAY_PREFIX}_TEST_SRC})

  target_link_libraries(${FOLDER}-tests PRIVATE ${GTEST_LDFLAGS})
  target_compile_options(${FOLDER}-tests PRIVATE ${GTEST_CFLAGS})
  target_link_libraries(${FOLDER}-tests PRIVATE ${CHROMA_LDFLAGS})
  target_compile_options(${FOLDER}-tests PRIVATE ${CHROMA_CFLAGS})

  add_test(${FOLDER}-tests ${FOLDER}-tests)
endforeach()
