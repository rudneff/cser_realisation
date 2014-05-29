package com.nprs.recsystem.common;

public class Point {
    private float _x;
    private float _y;

    public Point(float x, float y) {
        _x = x;
        _y = y;
    }

    public float x() {
        return _x;
    }

    public float y() {
        return _y;
    }
}
