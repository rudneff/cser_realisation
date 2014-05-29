package com.nprs.recsystem.recognition.recognition_results;

public class RecognitionResults {
    private final NumberPlate[] _numberPlates;

    public RecognitionResults(NumberPlate[] numberPlates) {
        _numberPlates = numberPlates;
    }

    public NumberPlate[] numberPlates() {
        return _numberPlates;
    }
}
