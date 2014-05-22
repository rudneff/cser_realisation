cmake_minimum_required(VERSION 2.8)

project(nprs)

set(CMAKE_BUILD_TYPE Debug)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message("using clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    message("using gcc")
    ADD_DEFINITIONS( -std=c++11 )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
    message("using intel")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
    message("using msvc")
    set(MSVC true)
endif()

add_subdirectory(common)
add_subdirectory(recognition_system)
add_subdirectory(console_tests)

if (JAVA)
add_subdirectory(nprs_java_api)
endif()

find_package(OpenCV)
if (OpenCV_FOUND)
    add_subdirectory(ocv_textdetection_sample)
endif()