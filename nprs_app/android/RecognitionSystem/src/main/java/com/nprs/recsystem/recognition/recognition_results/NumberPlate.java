package com.nprs.recsystem.recognition.recognition_results;

import com.nprs.recsystem.common.Rectangle;

public class NumberPlate {
    private final Rectangle _bounds;
    private final NumberPlateCharacter[] _characters;

    public NumberPlate(Rectangle bounds, NumberPlateCharacter[] characters) {
        _bounds = bounds;
        _characters = characters;
    }

    public Rectangle bounds() {
        return _bounds;
    }

    public NumberPlateCharacter[] characters() {
        return _characters;
    }
}
