package com.nprs.app.recognition.common_structures;

public class NumberPlateCharacter {
    private final short _code;
    private final Rectangle _bounds;

    public NumberPlateCharacter(short code, float x, float y, float width, float height) {
        this(code, new Rectangle(x, y, width, height));
    }

    public NumberPlateCharacter(short code, Rectangle bounds) {
        _code = code;
        _bounds = bounds;
    }

    public short getCode() {
        return _code;
    }

    public Rectangle getBounds() {
        return _bounds;
    }

}
