cmake_minimum_required(VERSION 2.8)

set(projname ocv_textdetection_sample)

project(${projname})

set (sources 
	src/textdetection.cpp
)

find_package(OpenCV REQUIRED)
set(OpenCV_STATIC true)
include_directories("${OpenCV_DIR}/include")
add_executable(${projname} ${sources})

message(${OpenCV_LIBS})
target_link_libraries(${projname} ${OpenCV_LIBS})

INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)