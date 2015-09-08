cmake_minimum_required(VERSION 3.3)

project("nano_magnetic" CXX)

# The version number.
set(NANO_VERSION_MAJOR 0)
set(NANO_VERSION_MINOR 1)
set(NANO_VERSION "${OCRTOOL_VERSION_MAJOR}.${OCRTOOL_VERSION_MINOR}")

if(CMAKE_BINARY_DIR STREQUAL CMAKE_SOURCE_DIR)
    message(FATAL_ERROR "Please select another Build Directory!")
endif()

# Compiler settings
if(MSVC)
    # Force to always compile with W4
    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
elseif(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")
endif()

# Eigen3: A C++ template library for linear algebra: vectors, matrices, and related algorithms.
set(EIGEN3_MINIMUM_VERSION 3.1.2)
find_package(Eigen3 ${EIGEN3_MINIMUM_VERSION})
if (EIGEN3_FOUND)
    include_directories("${EIGEN3_INCLUDE_DIR}")
else()
    message(SEND_ERROR "Failed to find Eigen ${EIGEN3_MINIMUM_VERSION}")
    return()
endif()

# Root directory
set(NANO_ROOT_DIR ${PROJECT_SOURCE_DIR})

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
    "${NANO_ROOT_DIR}/config/NanoConfig.h.in"
    "${PROJECT_BINARY_DIR}/NanoConfig.h"
)
include_directories("${PROJECT_BINARY_DIR}")


# Resources
set(RESOURCES_TARGET "${PROJECT_NAME}_resources")
add_custom_target(
    ${RESOURCES_TARGET} ALL
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${NANO_ROOT_DIR}/share ${PROJECT_BINARY_DIR}/${CMAKE_CFG_INTDIR}/share
    SOURCES ${${RESOURCES_TARGET}}
    )

include_directories("${NANO_ROOT_DIR}/include")

file(GLOB HEADERS "include/*.h")

file(GLOB SOURCES_LIB "src/lib/*.cpp")
file(GLOB SOURCES_EXECUTABLE "src/*.cpp")

set(NANO_SHARED_LIBRARY "${PROJECT_NAME}_shared")
add_library(${NANO_SHARED_LIBRARY} ${SOURCES_LIB} ${HEADERS})
set_property(TARGET ${NANO_SHARED_LIBRARY} PROPERTY CXX_STANDARD 11)

add_executable(${PROJECT_NAME} ${SOURCES_EXECUTABLE} ${HEADERS})
add_dependencies(${PROJECT_NAME} ${NANO_SHARED_LIBRARY})
add_dependencies(${PROJECT_NAME} ${RESOURCES_TARGET})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} 
                      ${NANO_SHARED_LIBRARY}
                      )

# Unit tests by Google Testing Framework
#include_directories("${NANO_SHARED_LIBRARY}/thirdparty/gtest/include")
#add_subdirectory("${NANO_SHARED_LIBRARY}/thirdparty/gtest/src/gtest/")
#add_subdirectory("${NANO_SHARED_LIBRARY}/tests")

