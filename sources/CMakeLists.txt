cmake_minimum_required(VERSION 2.8)

project(nprs)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/../bin")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    message(clang detected)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LANGUAGE_STANDARD "c++11")
    set(CMAKE_XCODE_ATTRIBUTE_CLANG_CXX_LIBRARY "libc++")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    # using GCC
    message(${CMAKE_CXX_COMPILER_ID})
    #set(CMAKE_CXX_FLAGS "-std=c++11")
    ADD_DEFINITIONS( -std=c++11 )
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
	# using Intel C++
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	# using Visual Studio C++
endif()

add_subdirectory(common)
add_subdirectory(recognition_system)
add_subdirectory(nprs_java_api)
