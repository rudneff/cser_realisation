#include "nprs_jni.h"

#include <rec_system/RecognitionSystem.h>
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <rec_system/common_structures/NumberPlateCharacter.h>
#include <common/image/Image.h>
#include <common/image/Color.h>
#include <common/image/Bitmap.h>
#include <iostream>

const char RR_CLASS_NAME[] = "com/nprs/app/recognition/common_structures/RecognitionResults";
const char NUM_PLATE_CLASS_NAME[] = "com/nprs/app/recognition/common_structures/NumberPlate";

using namespace nprs;

static jobject createRecResultsInstance(JNIEnv *env, const RecognitionResults &results);
static jobject createNumberPlateInstance(JNIEnv *env, const pNumberPlate &numPlate);

jobject JNICALL Java_com_nprs_app_recognition_jni_RecognizerJNI_recognize(JNIEnv *env, jobject object, jintArray pixels, jint width, jint height) {
    RecognitionSystem recognitionSystem;
    jboolean isCopy;
    uchar *data = reinterpret_cast<uchar*>(env->GetIntArrayElements(pixels, &isCopy));
    RecognitionResults results = recognitionSystem.recognize(Bitmap(data, width, height, nprs::ColorInfo(nprs::ColorFormat::RGBA, 3)));
    jobject resultsJava = createRecResultsInstance(env, results);
    return resultsJava;
}

static jobject createRecResultsInstance(JNIEnv *env, const RecognitionResults &results) {
    jclass recResultsClass = env->FindClass(RR_CLASS_NAME);
    jmethodID recResultsConstructor = env->GetMethodID(recResultsClass, "<init>", "()V");
    jmethodID recResultsAdd = env->GetMethodID(
                                    recResultsClass,
                                    "addNumberPlate",
                                    ("(Lcom/nprs/app/recognition/common_structures/NumberPlate;)V")
    );

    jobject result = env->NewObject(recResultsClass, recResultsConstructor);

    int count = 0;
    for (auto numPlate : results.numberPlates()) {
        if (count > 250)
            break;

        if (numPlate->bounds().width() > 5 && numPlate->bounds().width() < 30 &&
            numPlate->bounds().height() > 5 && numPlate->bounds().height() < 30)
        {
            count++;
            jobject numPlateJava = createNumberPlateInstance(env, numPlate);
            env->CallVoidMethod(result, recResultsAdd, numPlateJava);
        }
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