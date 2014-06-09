CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname training_lib)

PROJECT(${projname})

SET (headers
	src/training_lib/SymbolDetectorTrainer.h
)

SET (sources
	src/training_lib/SymbolDetectorTrainer.cpp
)

# create missing files
SET (source_files ${sources} ${headers})
FOREACH(file ${source_files})
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        FILE(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/${file} "\n")
    ENDIF()
ENDFOREACH()
# --

INCLUDE_DIRECTORIES(src)

# create directories in XCode and Visual Studio
SET(directories
    src/training_lib
)

FOREACH(directory ${directories})
	FILE(GLOB dir_headers "${directory}/*.h")
	FILE(GLOB dir_sources "${directory}/*.cpp")
	STRING(REGEX REPLACE "/" "\\\\\\\\" convdir ${directory})
	SOURCE_GROUP(${convdir} FILES ${dir_headers} ${dir_sources})
ENDFOREACH()
# --

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
