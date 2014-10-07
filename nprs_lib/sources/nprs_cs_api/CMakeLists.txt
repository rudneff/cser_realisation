CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname nprs_cs_api)

PROJECT(${projname})

SET (headers 
	src/NativeRecognizer.h
	src/RecognitionResults.h
	src/NumberPlate.h
	src/NumberPlateCharacter.h
	src/Rectangle.h
)

SET (sources 
	src/NativeRecognizer.cpp
	src/RecognitionResults.cpp
)

SET (dependencies 
	recognition_system
	common
)

CHECK_FILES("${sources};${headers}")
GROUP_FILES(src)

FOREACH(dep ${dependencies})
	INCLUDE_DIRECTORIES("../${dep}/src")
ENDFOREACH()

ADD_LIBRARY(${projname} SHARED ${headers} ${sources})
TARGET_LINK_LIBRARIES(${projname} ${dependencies})

# configure c++/cli
SET_TARGET_PROPERTIES(${projname} PROPERTIES VS_DOTNET_REFERENCES "System.Drawing")
SET_TARGET_PROPERTIES(${projname} PROPERTIES COMPILE_FLAGS "/clr /EHa")
STRING(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
# --

INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)