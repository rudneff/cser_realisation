CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname common)

PROJECT(${projname})

INCLUDE(utils)

SET (headers 
    src/common/image/Color.h
    src/common/image/Image.h
	src/common/image/Image.inl
    src/common/image/ImageConverter.h
    src/common/image/Bitmap.h

    src/common/CommonDefinitions.h
    src/common/Rectangle.h
	src/common/Rectangle.inl
    src/common/Line.h
    src/common/Point.h
	src/common/Point.inl
    src/common/Matrix.h
	src/common/Matrix.inl

    src/common/exceptions/NprsException.h
    src/common/exceptions/ArgumentException.h
    src/common/exceptions/NotSupportedException.h
)

SET (sources
    src/common/image/Image.cpp
    src/common/image/ImageConverter.cpp
    src/common/image/Color.cpp
	src/common/image/Bitmap.cpp

    src/common/exceptions/NprsException.cpp
    src/common/exceptions/ArgumentException.cpp
    src/common/exceptions/NotSupportedException.cpp
)

SET (directories
    src/common
    src/common/image
    src/common/exceptions
)

CHECK_FILES("${sources} ${headers}")
GROUP_FILES("${directories}")

INCLUDE_DIRECTORIES(src)

ADD_LIBRARY(${projname} ${headers} ${sources})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)
