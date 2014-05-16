cmake_minimum_required(VERSION 2.8)

set(projname common)

project(${projname})

file (GLOB_RECURSE headers
	src/*.h
)

file (GLOB_RECURSE sources
	src/*.cpp
)

set (directories
    src/common
    src/common/image
)

INCLUDE_DIRECTORIES(src)

foreach(directory ${directories})
	file(GLOB dir_headers "${directory}/*.h")
	file(GLOB dir_sources "${directory}/*.cpp")
	string(REGEX REPLACE "/" "\\\\\\\\" convdir ${directory})
	source_group(${convdir} FILES ${dir_headers} ${dir_sources})
endforeach()


#make sure to used shared in in the jni library, as this will be loaded by
#java
add_library(${projname} ${headers} ${sources})