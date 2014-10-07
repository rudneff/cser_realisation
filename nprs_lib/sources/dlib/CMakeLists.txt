CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname dlib)

PROJECT(${projname})

INCLUDE_DIRECTORIES(src)

ADD_LIBRARY(${projname} src/dlib/all/source.cpp)
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)
