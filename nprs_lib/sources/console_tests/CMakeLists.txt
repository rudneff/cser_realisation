cmake_minimum_required(VERSION 2.8)

set(projname console_tests)

project(${projname})

set (sources
    src/console_test.cpp
)

set (source_files ${sources})

foreach(file ${source_files})
    if(NOT EXISTS ${CMAKE_CURRENT_SOURCE_DIR}/${file})
        file(APPEND ${CMAKE_CURRENT_SOURCE_DIR}/${file} "\n")
    endif()
endforeach()

include_directories(src)

foreach(directory ${directories})
	file(GLOB dir_headers "${directory}/*.h")
	file(GLOB dir_sources "${directory}/*.cpp")
	string(REGEX REPLACE "/" "\\\\\\\\" convdir ${directory})
	source_group(${convdir} FILES ${dir_headers} ${dir_sources})
endforeach()

set (dependencies
    common
    recognition_system
)

foreach(dep ${dependencies})
	include_directories("../${dep}/src")
endforeach()

add_executable(${projname} ${sources})
target_link_libraries(${projname} ${dependencies})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)