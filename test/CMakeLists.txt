cmake_minimum_required(VERSION 2.8)

project("nano_magnetic_tests" CXX)

if(!NANO_ROOT_DIR)
  message(FATAL_ERROR "NANO_ROOT_DIR is undefined")
endif()

if(!NANO_SHARED_LIBRARY)
  message(FATAL_ERROR "NANO_SHARED_LIBRARY is undefined")
endif()

file(GLOB SOURCES "*.cpp")

# Google C++ Testing Framework
include_directories("${NANO_ROOT_DIR}/thirdparty/gtest/googletest/include")
#add_subdirectory("${NANO_ROOT_DIR}/thirdparty/gtest/googletest" "thirdparty/gtest/googletest")

# Google C++ Mocking Framework
include_directories("${NANO_ROOT_DIR}/thirdparty/gtest/googlemock/include")
add_subdirectory("${NANO_ROOT_DIR}/thirdparty/gtest/googlemock" "thirdparty/gtest/googlemock")

add_executable(${PROJECT_NAME} ${SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
target_link_libraries(${PROJECT_NAME} ${NANO_SHARED_LIBRARY} gmock gmock_main )

