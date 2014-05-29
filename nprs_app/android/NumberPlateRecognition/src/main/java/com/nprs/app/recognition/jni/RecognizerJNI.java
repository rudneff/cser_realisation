package com.nprs.app.recognition.jni;

import com.nprs.app.recognition.common_structures.RecognitionResults;

public class RecognizerJNI {
    static {
        System.loadLibrary("nprs_java_api");
    }

    public native RecognitionResults recognize(int[] pixels, int width, int height);
}
