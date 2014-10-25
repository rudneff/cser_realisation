CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

SET(projname recognition_system)

PROJECT(${projname})

SET (headers 
    src/rec_system/RecognitionSystem.h
    src/rec_system/Algorithm.h

    src/rec_system/common_structures/NumberPlate.h
    src/rec_system/common_structures/NumberPlateCharacter.h
    src/rec_system/common_structures/RecognitionResults.h

	src/rec_system/image_processing/SobelOperator.h
	src/rec_system/image_processing/GradientOperator.h
	src/rec_system/image_processing/SimpleGradientOperator.h
	src/rec_system/image_processing/filters/IntensityRescaleFilter.h
    src/rec_system/image_processing/feature_extraction/FeatureExtractor.h
    src/rec_system/image_processing/feature_extraction/HogFeatureExtractor.h
    src/rec_system/image_processing/feature_extraction/HistogramExtractor.h
	src/rec_system/image_processing/filters/thresholding/OtsuThresholder.h
	src/rec_system/image_processing/filters/thresholding/Thresholder.h
	src/rec_system/image_processing/filters/MaskFilter.h
	src/rec_system/image_processing/filters/Convolution.h
	src/rec_system/image_processing/filters/Convolution.h
	src/rec_system/image_processing/object_detection/CascadeObjectDetector.h
	src/rec_system/image_processing/object_detection/ObjectDetector.h
	src/rec_system/image_processing/object_detection/OcvHelper.h
	
	src/rec_system/image_processing/filters/ImageFilter.h

	src/rec_system/classification/Classifier.h
	src/rec_system/machine_learning/TrainingSet.h
	src/rec_system/classification/adaboost/AdaboostClassifier.h
	src/rec_system/clusterization/fuzzy_fcmeans/FCMeansClusterer.h
	src/rec_system/clusterization/fuzzy_fcmeans/FuzzyCluster.h
	src/rec_system/clusterization/Clusterer.h

	src/rec_system/machine_learning/TrainingSet.h
	src/rec_system/machine_learning/DecisionMaker.h
	src/rec_system/machine_learning/Trainer.h
	src/rec_system/machine_learning/SvmRegressionTrainer.h
	src/rec_system/machine_learning/DLibDecisionMaker.h
	src/rec_system/machine_learning/DLibHelper.h
	src/rec_system/machine_learning/CascadeClassifierTrainer.h
	src/rec_system/machine_learning/HaarCascadeDecisionMaker.h
	src/rec_system/machine_learning/OneVsOneTrainer.h
	src/rec_system/machine_learning/OneVsOneDecisionFunction.h

    src/rec_system/plate_detection/PlateDetector.h
	src/rec_system/plate_detection/HoughLineDetector.h
	src/rec_system/plate_detection/RegionGrouper.h
	src/rec_system/plate_detection/SimpleRegionGrouper.h
	src/rec_system/plate_detection/HoughRegionGrouper.h
    src/rec_system/plate_detection/region_detection/cser/CSERDetector.h
    src/rec_system/plate_detection/region_detection/cser/ExtremalRegion.h
    src/rec_system/plate_detection/region_detection/cser/ERFilter.h
    src/rec_system/plate_detection/region_detection/cser/ERDescriptor.h
    src/rec_system/plate_detection/region_detection/cser/filters/ERFilterMNLight.h
    src/rec_system/plate_detection/region_detection/cser/filters/ERFilterMNHeavy.h
    src/rec_system/plate_detection/region_detection/cser/filters/ERFilterEmpty.h
    src/rec_system/plate_detection/region_detection/cser/algorithm/CserAlgorithm.h
    src/rec_system/plate_detection/region_detection/cser/features/ICFeature.h
    src/rec_system/plate_detection/region_detection/cser/features/ICAspectRatioFeature.h
    src/rec_system/plate_detection/region_detection/cser/features/ICCompactnessFeature.h
    src/rec_system/plate_detection/region_detection/cser/features/ICHCrossingsFeature.h
    src/rec_system/plate_detection/region_detection/cser/features/ICNumHolesFeature.h

    src/rec_system/symbol_recognition/SymbolRecognizer.h
)

SET (sources
    src/rec_system/RecognitionSystem.cpp
    src/rec_system/Algorithm.cpp

    src/rec_system/common_structures/NumberPlate.cpp
    src/rec_system/common_structures/NumberPlateCharacter.cpp
    src/rec_system/common_structures/RecognitionResults.cpp

	src/rec_system/image_processing/SobelOperator.cpp
	src/rec_system/image_processing/SimpleGradientOperator.cpp
    src/rec_system/image_processing/feature_extraction/HogFeatureExtractor.cpp
    src/rec_system/image_processing/feature_extraction/HistogramExtractor.cpp
	src/rec_system/image_processing/filters/Convolution.cpp
	src/rec_system/image_processing/filters/thresholding/OtsuThresholder.cpp
	src/rec_system/image_processing/filters/thresholding/Thresholder.cpp
	src/rec_system/image_processing/filters/IntensityRescaleFilter.cpp
	src/rec_system/image_processing/filters/MaskFilter.cpp
	src/rec_system/image_processing/filters/ImageFilter.cpp
	src/rec_system/image_processing/object_detection/CascadeObjectDetector.cpp
	src/rec_system/image_processing/object_detection/OcvHelper.cpp

	src/rec_system/classification/adaboost/AdaboostClassifier.cpp
	src/rec_system/machine_learning/TrainingSet.cpp
	src/rec_system/clusterization/fuzzy_fcmeans/FCMeansClusterer.cpp
	src/rec_system/clusterization/fuzzy_fcmeans/FuzzyCluster.cpp

	src/rec_system/clusterization/Clusterer.cpp

	src/rec_system/machine_learning/TrainingSet.cpp
	src/rec_system/machine_learning/SvmRegressionTrainer.cpp
	src/rec_system/machine_learning/DLibDecisionMaker.cpp
	src/rec_system/machine_learning/DLibHelper.cpp
	src/rec_system/machine_learning/CascadeClassifierTrainer.cpp
	src/rec_system/machine_learning/HaarCascadeDecisionMaker.cpp
	src/rec_system/machine_learning/OneVsOneTrainer.cpp
	src/rec_system/machine_learning/OneVsOneDecisionFunction.cpp

	src/rec_system/plate_detection/HoughLineDetector.cpp

    src/rec_system/plate_detection/PlateDetector.cpp
    src/rec_system/plate_detection/RegionGrouper.cpp
    src/rec_system/plate_detection/SimpleRegionGrouper.cpp
    src/rec_system/plate_detection/HoughRegionGrouper.cpp
    src/rec_system/plate_detection/region_detection/cser/CSERDetector.cpp
    src/rec_system/plate_detection/region_detection/cser/ExtremalRegion.cpp
    src/rec_system/plate_detection/region_detection/cser/ERDescriptor.cpp
    src/rec_system/plate_detection/region_detection/cser/filters/ERFilterMNLight.cpp
    src/rec_system/plate_detection/region_detection/cser/filters/ERFilterMNHeavy.cpp
    src/rec_system/plate_detection/region_detection/cser/filters/ERFilterEmpty.cpp
    src/rec_system/plate_detection/region_detection/cser/algorithm/CserAlgorithm.cpp
    src/rec_system/plate_detection/region_detection/cser/features/ICFeature.cpp
    src/rec_system/plate_detection/region_detection/cser/features/ICAspectRatioFeature.cpp
    src/rec_system/plate_detection/region_detection/cser/features/ICCompactnessFeature.cpp
    src/rec_system/plate_detection/region_detection/cser/features/ICHCrossingsFeature.cpp
    src/rec_system/plate_detection/region_detection/cser/features/ICNumHolesFeature.cpp

    src/rec_system/symbol_recognition/SymbolRecognizer.cpp
)

INCLUDE_DIRECTORIES(src)

SET(directories
    src/rec_system
    src/rec_system/common_structures

    src/rec_system/image_processing
    src/rec_system/image_processing/feature_extraction
	src/rec_system/image_processing/filters
	src/rec_system/image_processing/filters/thresholding
	src/rec_system/image_processing/object_detection
    src/rec_system/plate_detection/region_detection/cser
    src/rec_system/plate_detection/region_detection/cser/filters
    src/rec_system/plate_detection/region_detection/cser/algorithm
    src/rec_system/plate_detection/region_detection/cser/features

	src/rec_system/classification
	src/rec_system/classification/adaboost
	src/rec_system/clusterization/fuzzy_fcmeans

	src/rec_system/machine_learning
	src/rec_system/plate_detection
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
