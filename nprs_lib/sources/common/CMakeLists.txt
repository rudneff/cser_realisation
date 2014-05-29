CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname common)

PROJECT(${projname})

SET (headers 
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
    src/common/exceptions/NotSupportedException.h
)

SET (sources
    src/common/image/Image.cpp
    src/common/image/ImageConverter.cpp

    src/common/exceptions/NprsException.cpp
    src/common/exceptions/ArgumentException.cpp
    src/common/exceptions/NotSupportedException.cpp
)

SET (directories
    src/common
    src/common/image
    src/common/exceptions
)

SET (source_files ${sources} ${headers})

FOREACH(file ${source_files})
    IF(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        FILE(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/${file} "\n")
    ENDIF()
ENDFOREACH()

INCLUDE_DIRECTORIES(src)

FOREACH(directory ${directories})
	FILE(GLOB dir_headers "${directory}/*.h")
	FILE(GLOB dir_sources "${directory}/*.cpp")
	STRING(REGEX REPLACE "/" "\\\\\\\\" convdir ${directory})
	SOURCE_GROUP(${convdir} FILES ${dir_headers} ${dir_sources})
ENDFOREACH()

ADD_LIBRARY(${projname} ${headers} ${sources})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)