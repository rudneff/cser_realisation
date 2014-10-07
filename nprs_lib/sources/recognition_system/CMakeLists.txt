CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname recognition_system)

PROJECT(${projname})

SET (headers 
    src/rec_system/RecognitionSystem.h
    src/rec_system/Algorithm.h

    src/rec_system/common_structures/NumberPlate.h
    src/rec_system/common_structures/NumberPlateCharacter.h
    src/rec_system/common_structures/RecognitionResults.h

	src/rec_system/image_processing/filters/thresholding/OtsuThresholder.h
	src/rec_system/image_processing/filters/thresholding/Thresholder.h

    src/rec_system/image_processing/region_detection/cser/CSERDetector.h
    src/rec_system/image_processing/region_detection/cser/ExtremalRegion.h
    src/rec_system/image_processing/region_detection/cser/ERFilter.h
    src/rec_system/image_processing/region_detection/cser/ERDescriptor.h

    src/rec_system/image_processing/region_detection/cser/filters/ERFilterMNLight.h
    src/rec_system/image_processing/region_detection/cser/filters/ERFilterMNHeavy.h
    src/rec_system/image_processing/region_detection/cser/filters/ERFilterEmpty.h

    src/rec_system/image_processing/region_detection/cser/algorithm/CserAlgorithm.h

    src/rec_system/image_processing/region_detection/cser/features/ICFeature.h
    src/rec_system/image_processing/region_detection/cser/features/ICAspectRatioFeature.h
    src/rec_system/image_processing/region_detection/cser/features/ICCompactnessFeature.h
    src/rec_system/image_processing/region_detection/cser/features/ICHCrossingsFeature.h
    src/rec_system/image_processing/region_detection/cser/features/ICNumHolesFeature.h
	
	src/rec_system/image_processing/filters/ImageFilter.h

	src/rec_system/classification/Classifier.h
	src/rec_system/classification/TrainingSet.h
	src/rec_system/classification/adaboost/AdaboostClassifier.h
	src/rec_system/clusterization/fuzzy_fcmeans/FCMeansClusterer.h
	src/rec_system/clusterization/fuzzy_fcmeans/FuzzyCluster.h
	src/rec_system/clusterization/Clusterer.h
)

SET (sources
    src/rec_system/RecognitionSystem.cpp
    src/rec_system/Algorithm.cpp

    src/rec_system/common_structures/NumberPlate.cpp
    src/rec_system/common_structures/NumberPlateCharacter.cpp
    src/rec_system/common_structures/RecognitionResults.cpp

	src/rec_system/image_processing/filters/thresholding/OtsuThresholder.cpp
	src/rec_system/image_processing/filters/thresholding/Thresholder.cpp

    src/rec_system/image_processing/region_detection/cser/CSERDetector.cpp
    src/rec_system/image_processing/region_detection/cser/ExtremalRegion.cpp
    src/rec_system/image_processing/region_detection/cser/ERDescriptor.cpp

    src/rec_system/image_processing/region_detection/cser/filters/ERFilterMNLight.cpp
    src/rec_system/image_processing/region_detection/cser/filters/ERFilterMNHeavy.cpp
    src/rec_system/image_processing/region_detection/cser/filters/ERFilterEmpty.cpp

    src/rec_system/image_processing/region_detection/cser/algorithm/CserAlgorithm.cpp

	src/rec_system/image_processing/region_detection/cser/features/ICFeature.cpp
    src/rec_system/image_processing/region_detection/cser/features/ICAspectRatioFeature.cpp
    src/rec_system/image_processing/region_detection/cser/features/ICCompactnessFeature.cpp
    src/rec_system/image_processing/region_detection/cser/features/ICHCrossingsFeature.cpp
    src/rec_system/image_processing/region_detection/cser/features/ICNumHolesFeature.cpp

	src/rec_system/classification/adaboost/AdaboostClassifier.cpp
	src/rec_system/classification/TrainingSet.cpp
	src/rec_system/clusterization/fuzzy_fcmeans/FCMeansClusterer.cpp
	src/rec_system/clusterization/fuzzy_fcmeans/FuzzyCluster.cpp

	src/rec_system/clusterization/Clusterer.cpp
)

INCLUDE_DIRECTORIES(src)

SET(directories
    src/rec_system
    src/rec_system/common_structures

    src/rec_system/image_processing
	src/rec_system/image_processing/filters
	src/rec_system/image_processing/filters/thresholding
    src/rec_system/image_processing/region_detection/cser
    src/rec_system/image_processing/region_detection/cser/filters
    src/rec_system/image_processing/region_detection/cser/algorithm
    src/rec_system/image_processing/region_detection/cser/features

	src/rec_system/classification
	src/rec_system/classification/adaboost
	src/rec_system/clusterization/fuzzy_fcmeans
)

GROUP_FILES( "${directories}" )

SET(dependencies
    common
    dlib
)

FOREACH(dep ${dependencies})
	INCLUDE_DIRECTORIES("../${dep}/src")
ENDFOREACH()

FIND_PACKAGE(OpenCV REQUIRED)
INCLUDE_DIRECTORIES("${OpenCV_DIR}/include")

ADD_LIBRARY(${projname} ${headers} ${sources})
TARGET_LINK_LIBRARIES(${projname} ${dependencies} ${OpenCV_LIBS})
INSTALL(TARGETS ${projname} DESTINATION ${CMAKE_BINARY_DIR}/../bin/)
