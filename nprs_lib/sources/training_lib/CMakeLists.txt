CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname training_lib)

PROJECT(${projname})

SET (headers
	src/training_lib/SymbolDetectorTrainer.h
	src/training_lib/SampleExtractor.h
	src/training_lib/Sample.h
	src/training_lib/Sample.inl
	src/training_lib/IClassifierTrainer.h
	src/training_lib/trainers/LightClassifierTrainer.h
)

SET (sources
	src/training_lib/SymbolDetectorTrainer.cpp
	src/training_lib/SampleExtractor.cpp
	src/training_lib/Sample.cpp
	src/training_lib/trainers/LightClassifierTrainer.cpp
)

INCLUDE_DIRECTORIES(src)

SET(directories
    src/training_lib
	src/training_lib/trainers
)

CHECK_FILES("${sources};${headers}")
GROUP_FILES("${directories}")

# dependencies
SET(dependencies
    common
    recognition_system
)

FOREACH(dep ${dependencies})
	INCLUDE_DIRECTORIES("../${dep}/src")
ENDFOREACH()
# --

# opencv
FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES("${OpenCV_DIR}/include")
# --

ADD_LIBRARY(${projname} ${headers} ${sources})
TARGET_LINK_LIBRARIES(${projname} ${dependencies})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)
