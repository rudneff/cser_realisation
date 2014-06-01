CMAKE_MINIMUM_REQUIRED(VERSION 2.8.11)

SET(projname qt_test_gui)
PROJECT(${projname})

SET(headers
	src/MainWindow.h
)

SET(sources
	src/main.cpp
	src/MainWindow.cpp
)

SET(forms
	src/MainWindow.ui
)

QT5_WRAP_CPP(qt_moc src/MainWindow.h)
QT5_WRAP_UI(qt_ui_headers src/MainWindow.ui)

SET(headers ${headers} ${qt_ui_headers})
#SET(sources ${sources} ${qt_moc})

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
	FILE(GLOB dir_files "${directory}/*")
	STRING(REGEX REPLACE "/" "\\\\\\\\" convdir ${directory}) 
	SOURCE_GROUP(${convdir} FILES ${dir_files})
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

ADD_EXECUTABLE(${projname} ${headers} ${sources})
TARGET_LINK_LIBRARIES(${projname} ${dependencies} Qt5::Core Qt5::Widgets)
TARGET_LINK_LIBRARIES(${projname} ${Boost_LIBRARIES})

QT5_USE_MODULES(${projname} Core Widgets)
