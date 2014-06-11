CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

SET(projname qt_training_utility)
PROJECT(${projname})

SET(headers
)

SET(sources
	src/main.cpp
)

SET(dependencies
	common
	recognition_system
	training_lib
)

SET(directories
	src
)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES("../../libs")

CHECK_FILES("${sources};${headers}")
GROUP_FILES("${directories}")

FOREACH(dependency ${dependencies})
    INCLUDE_DIRECTORIES(../${dependency}/src)
ENDFOREACH()

# Find includes in corresponding build directories
SET(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
SET(CMAKE_AUTOMOC ON)

FIND_PACKAGE(Qt5Core)

ADD_EXECUTABLE(${projname} ${headers} ${sources})
TARGET_LINK_LIBRARIES(${projname} ${dependencies} Qt5::Core Qt5::Widgets)
TARGET_LINK_LIBRARIES(${projname} ${Boost_LIBRARIES})
QT5_USE_MODULES(${projname} Core)
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)
