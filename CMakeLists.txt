cmake_minimum_required(VERSION 3.0)

project("nano_magnetic" CXX)

if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(FATAL_ERROR "Please select another Build Directory!")
endif()

# The version number.
set(NANO_VERSION_MAJOR 0)
set(NANO_VERSION_MINOR 1)
set(NANO_VERSION "${NANO_VERSION_MAJOR}.${NANO_VERSION_MINOR}")

# Compiler settings
if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -std=c++11 -fPIC")
elseif(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -std=c++11")
endif()


set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# Eigen3: A C++ template library for linear algebra: vectors, matrices, and related algorithms.
set(EIGEN3_MINIMUM_VERSION 3.1.2)
find_package(Eigen3 ${EIGEN3_MINIMUM_VERSION})
if (EIGEN3_FOUND)
    include_directories("${EIGEN3_INCLUDE_DIR}")
else()
    message(SEND_ERROR "Failed to find Eigen ${EIGEN3_MINIMUM_VERSION}")
    return()
endif()

# configure a header file to pass some of the CMake settings to the source code
configure_file (
    "${PROJECT_SOURCE_DIR}/config/nano_config.h.in"
    "${PROJECT_BINARY_DIR}/${PROJECT_NAME}/nano_config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/*.h")
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/src/${PROJECT_NAME}/*.cc")

include_directories("${PROJECT_SOURCE_DIR}/src/")

# Bin
set(NANO_BIN "${PROJECT_NAME}-bin")
add_executable(${NANO_BIN} ${SOURCES} ${HEADERS})
set_property(TARGET ${NANO_BIN} PROPERTY CXX_STANDARD 11)
set_target_properties(${NANO_BIN} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")

# Tests
if(ENABLE_TESTS STREQUAL "ON")
    enable_testing()

    find_package(GTest REQUIRED)
    if(GTEST_FOUND)
        include_directories("${GTEST_INCLUDE_DIR}")
    else()
        message(SEND_ERROR "Failed to find GTest")
    endif()

    file(GLOB TEST_SOURCES "${PROJECT_SOURCE_DIR}/src/test/*.cc")

    set(NANO_TEST "${PROJECT_NAME}_test")
    add_executable(${NANO_TEST} ${TEST_SOURCES})
    set_property(TARGET ${NANO_TEST} PROPERTY CXX_STANDARD 11)
    target_link_libraries(${NANO_TEST} ${GTEST_BOTH_LIBRARIES})

    add_test(AllTests ${NANO_TEST})

endif(ENABLE_TESTS STREQUAL "ON")

