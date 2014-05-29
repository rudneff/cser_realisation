package com.nprs.recsystem.recognition.recognition_results;

import com.nprs.recsystem.common.Rectangle;

public class NumberPlateCharacter {
    private final char _asciiCode;
    private final Rectangle _bounds;

    public NumberPlateCharacter(char asciiCode, Rectangle bounds) {
        _asciiCode = asciiCode;
        _bounds = bounds;
    }

    public char asciiCode() {
        return _asciiCode;
    }

    public Rectangle bounds() {
        return _bounds;
    }
}
