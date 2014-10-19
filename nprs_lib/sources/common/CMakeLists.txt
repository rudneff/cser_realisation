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

    src/common/NprsStd.h
    src/common/Rectangle.h
	src/common/Rectangle.inl
    src/common/Line.h
    src/common/Point.h
	src/common/Point.inl
    src/common/Matrix.h
	src/common/Matrix.inl
	src/common/Size.h
	src/common/Size.inl
	src/common/Quad.h

	src/common/math/Vector.h
	src/common/math/Math.h
	src/common/math/Vec.h

    src/common/exceptions/NprsException.h
    src/common/exceptions/CommonExceptions.h
    src/common/functional/ListProcessing.h
)

SET (sources
    src/common/image/Image.cpp
    src/common/image/ImageConverter.cpp
    src/common/image/Color.cpp
	src/common/image/Bitmap.cpp

	src/common/math/Math.cpp

    src/common/exceptions/NprsException.cpp
    src/common/exceptions/CommonExceptions.cpp
)

SET (directories
    src/common
    src/common/image
    src/common/exceptions
)

GROUP_FILES("${directories}")

INCLUDE_DIRECTORIES(src)

ADD_LIBRARY(${projname} ${headers} ${sources})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)
