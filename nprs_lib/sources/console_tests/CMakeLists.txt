CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname console_tests)

PROJECT(${projname})

SET (sources
    src/console_test.cpp
)

CHECK_FILES(${sources})
GROUP_FILES(src)

INCLUDE_DIRECTORIES(src)

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