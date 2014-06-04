CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname recognition_system)

PROJECT(${projname})

SET (headers 
    src/rec_system/RecognitionSystem.h
    src/rec_system/Algorithm.h

    src/rec_system/common_structures/NumberPlate.h
    src/rec_system/common_structures/NumberPlateCharacter.h
    src/rec_system/common_structures/RecognitionResults.h

    src/rec_system/image_processing/region_detection/cser/CSERDetector.h
    src/rec_system/image_processing/region_detection/cser/ExtremalRegion.h
    src/rec_system/image_processing/region_detection/cser/ERFilter.h
    src/rec_system/image_processing/region_detection/cser/ERFilter
    src/rec_system/image_processing/region_detection/cser/ERDescriptor.h

    src/rec_system/image_processing/region_detection/cser/filters/ERFilterMNLight.h
    src/rec_system/image_processing/region_detection/cser/filters/ERFilterMNHeavy.h
    src/rec_system/image_processing/region_detection/cser/filters/ERFilterConditional.h

    src/rec_system/image_processing/region_detection/cser/algorithm/CserAlgorithm.h

    src/rec_system/image_processing/region_detection/cser/features/ICFeature.h
    src/rec_system/image_processing/region_detection/cser/features/ICAspectRatioFeature.h
    src/rec_system/image_processing/region_detection/cser/features/ICCompactnessFeature.h
    src/rec_system/image_processing/region_detection/cser/features/ICHCrossingsFeature.h
    src/rec_system/image_processing/region_detection/cser/features/ICNumHolesFeature.h

	src/rec_system/classification/Classifier.h
)

SET (sources
    src/rec_system/RecognitionSystem.cpp
    src/rec_system/Algorithm.cpp

    src/rec_system/image_processing/region_detection/cser/CSERDetector.cpp
    src/rec_system/image_processing/region_detection/cser/ExtremalRegion.cpp
    src/rec_system/image_processing/region_detection/cser/ERDescriptor.cpp

    src/rec_system/image_processing/region_detection/cser/filters/ERFilterMNLight.cpp
    src/rec_system/image_processing/region_detection/cser/filters/ERFilterMNHeavy.cpp
    src/rec_system/image_processing/region_detection/cser/filters/ERFilterConditional.cpp

    src/rec_system/image_processing/region_detection/cser/algorithm/CserAlgorithm.cpp

	src/rec_system/image_processing/region_detection/cser/features/ICFeature.cpp
    src/rec_system/image_processing/region_detection/cser/features/ICAspectRatioFeature.cpp
    src/rec_system/image_processing/region_detection/cser/features/ICCompactnessFeature.cpp
    src/rec_system/image_processing/region_detection/cser/features/ICHCrossingsFeature.cpp
    src/rec_system/image_processing/region_detection/cser/features/ICNumHolesFeature.cpp
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
    src/rec_system
    src/rec_system/common_structures
    src/rec_system/image_processing
    src/rec_system/image_processing/region_detection/cser
    src/rec_system/image_processing/region_detection/cser/filters
    src/rec_system/image_processing/region_detection/cser/algorithm
    src/rec_system/image_processing/region_detection/cser/features
	src/rec_system/classification
)

FOREACH(directory ${directories})
	FILE(GLOB dir_headers "${directory}/*.h")
	FILE(GLOB dir_sources "${directory}/*.cpp")
	STRING(REGEX REPLACE "/" "\\\\\\\\" convdir ${directory})
	SOURCE_GROUP(${convdir} FILES ${dir_headers} ${dir_sources})
ENDFOREACH()
# --

SET(dependencies
    common
)

FOREACH(dep ${dependencies})
	INCLUDE_DIRECTORIES("../${dep}/src")
ENDFOREACH()

ADD_LIBRARY(${projname} ${headers} ${sources})
TARGET_LINK_LIBRARIES(${projname} ${dependencies})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)
