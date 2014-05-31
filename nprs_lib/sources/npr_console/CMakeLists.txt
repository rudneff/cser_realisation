CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname npr_console)

PROJECT(${projname})

SET(sources 
	src/main.cpp
)

SET (dependencies
	nprs_cs_api
)

FOREACH(dep ${dependencies})
	INCLUDE_DIRECTORIES("../${dep}/src")
ENDFOREACH()

ADD_EXECUTABLE(${projname} ${headers} ${sources})

# configure c++/cli
SET_TARGET_PROPERTIES(${projname} PROPERTIES VS_DOTNET_REFERENCES "System.Drawing;")
SET_TARGET_PROPERTIES(${projname} PROPERTIES COMPILE_FLAGS "/clr /EHa")
STRING(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
# --

INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)