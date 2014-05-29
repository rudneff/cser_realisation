cmake_minimum_required(VERSION 2.8)

set(projname nprs_cs_api)

project(${projname})

set (headers 
	src/NativeRecognizer.h
	src/RecognitionResults.h
	src/NumberPlate.h
	src/NumberPlateCharacter.h
	src/Rectangle.h
)

set (sources 
	src/NativeRecognizer.cpp
	src/RecognitionResults.cpp
)

set (dependencies 
	recognition_system
	common
)

foreach(dep ${dependencies})
	include_directories("../${dep}/src")
endforeach()

ADD_LIBRARY(${projname} SHARED ${headers} ${sources})
TARGET_LINK_LIBRARIES(${projname} ${dependencies})

# configure c++/cli
SET_TARGET_PROPERTIES(${projname} PROPERTIES VS_DOTNET_REFERENCES "System.Drawing")
SET_TARGET_PROPERTIES(${projname} PROPERTIES COMPILE_FLAGS "/clr /EHa")
STRING(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
# --

INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)