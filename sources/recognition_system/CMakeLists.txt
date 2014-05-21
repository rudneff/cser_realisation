cmake_minimum_required(VERSION 2.8)

set(projname recognition_system)

project(${projname})

set (headers 
    src/rec_system/RecognitionSystem.h

    src/rec_system/common_structures/NumberPlate.h
    src/rec_system/common_structures/NumberPlateCharacter.h
    src/rec_system/common_structures/RecognitionResults.h

    src/rec_system/image_processing/region_detection/cser/CSERDetector.h
    src/rec_system/image_processing/region_detection/cser/ExtremalRegion.h
    src/rec_system/image_processing/region_detection/cser/ERFilter.h
    src/rec_system/image_processing/region_detection/cser/ERFilter
    src/rec_system/image_processing/region_detection/cser/ERFilterLight.h
    src/rec_system/image_processing/region_detection/cser/ERFilterHeavy.h
)

set (sources
    src/rec_system/RecognitionSystem.cpp

    src/rec_system/image_processing/region_detection/cser/CSERDetector.cpp
    src/rec_system/image_processing/region_detection/cser/ExtremalRegion.cpp
    src/rec_system/image_processing/region_detection/cser/ERFilterLight.cpp
    src/rec_system/image_processing/region_detection/cser/ERFilterHeavy.cpp
)

set (source_files ${sources} ${headers})

foreach(file ${source_files})
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/${file} "\n")
    endif()
endforeach()

include_directories(src)

set (directories
    src/rec_system
    src/rec_system/common_structures
    src/rec_system/image_processing
    src/rec_system/image_processing/region_detection/cser
)

foreach(directory ${directories})
	file(GLOB dir_headers "${directory}/*.h")
	file(GLOB dir_sources "${directory}/*.cpp")
	string(REGEX REPLACE "/" "\\\\\\\\" convdir ${directory})
	source_group(${convdir} FILES ${dir_headers} ${dir_sources})
endforeach()

set (dependencies
	common
)

foreach(dep ${dependencies})
	include_directories("../${dep}/src")
endforeach()

#make sure to used shared in in the jni library, as this will be loaded by
#java
add_library(${projname} ${headers} ${sources})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)