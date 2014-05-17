cmake_minimum_required(VERSION 2.8)

set(projname nprs_java_api)

project(${projname})

set (headers 
	src/nprs_jni.h
)

set (sources 
	src/nprs_jni.cpp
)

set (dependencies 
	recognition_system
	common
)

foreach(dep ${dependencies})
	include_directories("../${dep}/src")
endforeach()

#test for ANDROID and look for stuff not relevant to android.
if(NOT ANDROID)
#jni is available by default on android
find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
endif()
        
#make sure to used shared in in the jni library, as this will be loaded by
#java
add_library(${projname} SHARED ${headers} ${sources})
target_link_libraries(${projname} ${dependencies} )

INSTALL(TARGETS nprs_java_api DESTINATION ${CMAKE_BINARY_DIR}/../bin/)