CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname training_lib)

PROJECT(${projname})

SET (headers
	src/training_lib/SymbolDetectorTrainer.h
	src/training_lib/SampleExtractor.h
	src/training_lib/Sample.h
	src/training_lib/InputSample.h
	src/training_lib/IClassifierTrainer.h
	src/training_lib/trainers/LightClassifierTrainer.h
	
	src/training_lib/input_samples/ImageInputSample.h
	src/training_lib/input_samples/PositiveImageInputSample.h
	src/training_lib/input_samples/NegatvieRegionInputSample.h
	src/training_lib/input_samples/NegativeImageInputSample.h
	
	src/training_lib/input_sample_extractors/MultiThresholdExtractor.h
	src/training_lib/input_sample_extractors/AutoThresholdExtractor.h
	src/training_lib/input_sample_extractors/RandomRegionExtractor.h
)

SET (sources
	src/training_lib/SymbolDetectorTrainer.cpp
	src/training_lib/SampleExtractor.cpp
	src/training_lib/Sample.cpp
	src/training_lib/InputSample.cpp
	src/training_lib/trainers/LightClassifierTrainer.cpp
	
	src/training_lib/input_samples/ImageInputSample.cpp
	src/training_lib/input_samples/PositiveImageInputSample.cpp
	src/training_lib/input_samples/NegatvieRegionInputSample.cpp
	src/training_lib/input_samples/NegativeImageInputSample.cpp
	
	src/training_lib/input_sample_extractors/MultiThresholdExtractor.cpp
	src/training_lib/input_sample_extractors/AutoThresholdExtractor.cpp
	src/training_lib/input_sample_extractors/RandomRegionExtractor.cpp
)

INCLUDE_DIRECTORIES(src)

SET(directories
    src/training_lib
	src/training_lib/trainers
	src/training_lib/input_sample_extractors
	src/training_lib/input_samples
)

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
#FIND_PACKAGE(OpenCV REQUIRED)
#INCLUDE_DIRECTORIES("${OpenCV_DIR}/include")
# --

ADD_LIBRARY(${projname} ${headers} ${sources})
TARGET_LINK_LIBRARIES(${projname} ${dependencies})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_SOURCE_DIR}/../bin/)
