CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

SET(projname qt_test_gui)
PROJECT(${projname})

SET(headers
	
)

SET(sources
	main.cpp
)

SET(dependencies
	common
	recognition_system
)

SET(directories
	src
)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES("../../libs")

FOREACH(directory ${directories})
	FILE(GLOB dir_headers "${directory}/*.cpp")
	FILE(GLOB dir_sources "${directory}/*.h")
	STRING(REGEX REPLACE "/" "\\\\\\\\" convdir ${directory}) 
	SOURCE_GROUP(${convdir} FILES ${dir_headers} ${dir_sources})
ENDFOREACH()

FOREACH(dependency ${dependencies})
    INCLUDE_DIRECTORIES(../${dependency}/src)
ENDFOREACH()

# Find includes in corresponding build directories
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
SET(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Core)
FIND_PACKAGE(Qt5Gui)
FIND_PACKAGE(Qt5Widgets)

ADD_EXECUTABLE(${projname} ${headers} ${source})
TARGET_LINK_LIBRARIES(${projname} ${dependencies} Qt5::Core Qt5::Widgets)
TARGET_LINK_LIBRARIES(${projname} ${Boost_LIBRARIES})

QT5_USE_MODULES(${projname} Core Widgets)
