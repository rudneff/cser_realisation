package com.nprs.app.recognition;

import android.graphics.Bitmap;

import com.nprs.app.recognition.common_structures.RecognitionResults;

public abstract class Recognizer {
    public abstract RecognitionResults recognize(Bitmap image);
}
