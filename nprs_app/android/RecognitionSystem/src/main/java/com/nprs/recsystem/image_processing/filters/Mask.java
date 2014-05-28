package com.nprs.recsystem.image_processing.filters;

public class Mask {
    private final int _size;
    private final float[][] _c;

    public Mask(int size) {
        _size = size;
        _c = new float[size][size];
    }

    public Mask(float[][] values, int size) {
        _size = size;
        _c = values;
    }

    public float value(int x, int y) {
        return _c[x][y];
    }

    public int size() {
        return _size;
    }
}
