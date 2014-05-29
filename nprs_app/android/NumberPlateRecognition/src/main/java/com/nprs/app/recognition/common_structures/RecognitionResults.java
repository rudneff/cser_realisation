package com.nprs.app.recognition.common_structures;
import java.util.ArrayList;
import java.util.List;

public class RecognitionResults {
    private final List<NumberPlate> _numberPlates;

    public RecognitionResults(List<NumberPlate> numberPlates) {
        _numberPlates = numberPlates;
    }

    public List<NumberPlate> getNumberPlates() {
        return _numberPlates;
    }

    // for JNI:

    public RecognitionResults() {
        this(new ArrayList<NumberPlate>());
    }

    public void addNumberPlate(NumberPlate numberPlate) {
        _numberPlates.add(numberPlate);
    }

    // --
}
