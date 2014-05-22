#include "nprs_jni.h"

#include <rec_system/RecognitionSystem.h>
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <rec_system/common_structures/NumberPlateCharacter.h>
#include <common/image/Image.h>
#include <common/image/Color.h>
#include <iostream>

const char RR_CLASS_NAME[] = "com/nprs/app/recognition/common_structures/RecognitionResults";
const char NUM_PLATE_CLASS_NAME[] = "com/nprs/app/recognition/common_structures/NumberPlate";
using namespace nprs;

static jobject createRecResultsInstance(JNIEnv *env, const pRecognitionResults &results);
static jobject createNumberPlateInstance(JNIEnv *env, const pNumberPlate &numPlate);

jobject Java_com_nprs_app_recognition_jni_RecognizerJNI_recognize(JNIEnv *env, jobject object, jintArray pixels, jint width, jint height) {
    RecognitionSystem recognitionSystem;
    pRecognitionResults results = recognitionSystem.recognize(Image<uchar>(10, 10, ColorInfo(COLORFORMAT_RGB, 3)));
    jobject resultsJava = createRecResultsInstance(env, results);
    return resultsJava;
}

static jobject createRecResultsInstance(JNIEnv *env, const pRecognitionResults &results) {
    jclass recResultsClass = env->FindClass(RR_CLASS_NAME);
    jmethodID recResultsConstructor = env->GetMethodID(recResultsClass, "<init>", "()V");
    jmethodID recResultsAdd = env->GetMethodID(
                                    recResultsClass,
                                    "addNumberPlate",
                                    ("(Lcom/nprs/app/recognition/common_structures/NumberPlate;)V")
    );

    jobject result = env->NewObject(recResultsClass, recResultsConstructor);

    for (auto numPlate : results->numberPlates()) {
        jobject numPlateJava = createNumberPlateInstance(env, numPlate);
        env->CallVoidMethod(result, recResultsAdd, numPlateJava);
    }

    return result;
}

static jobject createNumberPlateInstance(JNIEnv *env, const pNumberPlate &numPlate) {
    jclass nprCls = env->FindClass(NUM_PLATE_CLASS_NAME);
    jmethodID npInit = env->GetMethodID(
            nprCls,
            "<init>",
            "(FFFF)V"
    );

    Rectangle bounds = numPlate->bounds();
    jobject nprObject = env->NewObject(nprCls, npInit, npInit, bounds.x(), bounds.y(), bounds.width(), bounds.height());
    jmethodID npAddChar = env->GetMethodID(nprCls, "addCharacter", "(FFFFS)V");

    for (auto npChar : numPlate->characters()) {
        Rectangle charBounds = npChar->bounds();
        env->CallVoidMethod(nprObject, npAddChar, charBounds.x(), charBounds.y(), charBounds.width(), charBounds.height(), npChar->code());
    }

    return nprObject;
}