cmake_minimum_required(VERSION 2.8)

set(projname common)

project(${projname})

#file (GLOB_RECURSE headers
#	src/*.h
#)
#
#file (GLOB_RECURSE sources
#	src/*.cpp
#)

set (headers 
    src/common/image/Color.h
    src/common/image/Image.h
    src/common/image/ImageConverter.h

    src/common/CommonDefinitions.h
    src/common/Rectangle.h
    src/common/Line.h
    src/common/Point.h
    src/common/Matrix.h

    src/common/exceptions/NprsException.h
    src/common/exceptions/ArgumentException.h
)

set (sources
    src/common/image/Image.cpp
    src/common/image/ImageConverter.cpp

    src/common/exceptions/NprsException.cpp
    src/common/exceptions/ArgumentException.cpp
)

set (directories
    src/common
    src/common/image
    src/common/exceptions
)

set (source_files ${sources} ${headers})

foreach(file ${source_files})
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/${file} "\n")
    endif()
endforeach()

include_directories(src)

foreach(directory ${directories})
	file(GLOB dir_headers "${directory}/*.h")
	file(GLOB dir_sources "${directory}/*.cpp")
	string(REGEX REPLACE "/" "\\\\\\\\" convdir ${directory})
	source_group(${convdir} FILES ${dir_headers} ${dir_sources})
endforeach()

add_library(${projname} ${headers} ${sources})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)