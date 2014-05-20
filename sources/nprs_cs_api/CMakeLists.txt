cmake_minimum_required(VERSION 2.8)

set(projname nprs_cs_api)

project(${projname})

set (headers 
	src/nprs_cs.h
)

set (sources 
	src/nprs_cs.cpp
)

set (dependencies 
	recognition_system
	common
)


foreach(dep ${dependencies})
	include_directories("../${dep}/src")
endforeach()

add_library(${projname} ${sources})
target_link_libraries(${projname} ${dependencies} )

INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)