package com.nprs.app.recognition.common_structures;

public class Rectangle {
    private final float _x;
    private final float _y;
    private final float _width;
    private final float _height;

    public Rectangle(float x, float y, float width, float height) {
        _x = x;
        _y = y;
        _width = width;
        _height = height;
    }

    public float x() {
        return _x;
    }

    public float y() {
        return _y;
    }

    public float width() {
        return _width;
    }

    public float height() {
        return _height;
    }
}
