package com.nprs.console;

import com.nprs.app.recognition.common_structures.NumberPlate;
import com.nprs.app.recognition.common_structures.NumberPlateCharacter;
import com.nprs.app.recognition.common_structures.RecognitionResults;
import com.nprs.app.recognition.common_structures.Rectangle;
import com.nprs.app.recognition.jni.RecognizerJNI;

import java.lang.management.ManagementFactory;

public class Main {
    public static void main(String[] args) {
        System.out.println(ManagementFactory.getRuntimeMXBean().getName());

        RecognizerJNI recognizerJNI = new RecognizerJNI();
        RecognitionResults results = recognizerJNI.recognize(new int[] {1, 2, 3}, 10, 10);

        for(NumberPlate numberPlate : results.getNumberPlates()) {
            System.out.printf("NumberPlate:\n");
            Rectangle bounds = numberPlate.getBounds();
            System.out.printf("    Bounds: (%f, %f, %f, %f)\n", bounds.x(), bounds.y(), bounds.width(), bounds.height());
            System.out.printf("    Characters:\n");
            for (NumberPlateCharacter c : numberPlate.getCharacters()) {
                System.out.printf("        code = %d, Bounds: (%f, %f, %f, %f)\n", c.getCode(), c.getBounds().x(), c.getBounds().y(), c.getBounds().width(), c.getBounds().height());
            }
        }
    }
}
