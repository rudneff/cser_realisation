CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname console_tests)

PROJECT(${projname})

SET (sources
    src/console_test.cpp
)

SET (source_files ${sources})

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

SET (dependencies
    common
    recognition_system
)

FOREACH(dep ${dependencies})
	INCLUDE_DIRECTORIES("../${dep}/src")
ENDFOREACH()

ADD_EXECUTABLE(${projname} ${sources})
TARGET_LINK_LIBRARIES(${projname} ${dependencies})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)