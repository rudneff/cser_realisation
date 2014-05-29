package com.nprs.recsystem.common;

public class Line {
    private final float _x0;
    private final float _y0;
    private final float _x1;
    private final float _y1;

    public Line(float x0, float y0, float x1, float y1) {
        _x0 = x0;
        _y0 = y0;
        _x1 = x1;
        _y1 = y1;
    }

    public float x0() {
        return _x0;
    }

    public float y0() {
        return _y0;
    }

    public float x1() {
        return _x1;
    }

    public float y1() {
        return _y1;
    }
}
