package com.nprs.app.recognition.jni;

import android.graphics.Bitmap;

import com.nprs.app.recognition.Recognizer;
import com.nprs.app.recognition.common_structures.NumberPlate;
import com.nprs.app.recognition.common_structures.NumberPlateCharacter;
import com.nprs.app.recognition.common_structures.RecognitionResults;
import com.nprs.app.recognition.common_structures.Rectangle;
import java.util.Arrays;
import java.util.List;

public class NativeRecognizer extends Recognizer {
    @Override
    public RecognitionResults recognize(Bitmap image) {
        int[] pixels = new int[image.getWidth() * image.getHeight()];
        image.getPixels(pixels,0, image.getWidth(), 0, 0, image.getWidth(), image.getHeight());
        return new RecognizerJNI().recognize(pixels, image.getWidth(), image.getHeight());
    }

    private RecognitionResults recognize(int[] colors, int width, int height) {
        List<NumberPlate> plates = Arrays.asList(
                new NumberPlate(
                        Arrays.asList(
                                new NumberPlateCharacter((short)'a', new Rectangle(12, 3, 5, 8)),
                                new NumberPlateCharacter((short)'a', new Rectangle(22, 3, 5, 8))
                                ),
                        new Rectangle(10, 10, 90, 30))
        );
        return new RecognitionResults(plates);
    }
}
