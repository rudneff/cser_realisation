package com.nprs.recsystem.common.image;

import sun.misc.Unsafe;

public class Image {
    private final int _width;
    private final int _height;
    private final int _channels;
    private final ColorInfo _colorInfo;
    private final float[][] _data;

    public Image(int width, int height, ColorInfo colorInfo) {
        _width = width;
        _height = height;
        _colorInfo = colorInfo;
        _channels = colorInfo.numChannels();
        _data = new float[_channels][_width * _height];
    }

    public int width() {
        return _width;
    }

    public int height() {
        return _height;
    }

    public int numChannels() {
        return _channels;
    }

    public Color getColor(int x, int y) {
        float[] color = new float[_channels];
        for (int i = 0; i < _channels; i++) {
            color[i] = _data[i][y * _width + x];
        }
        return new Color(color, _colorInfo);
    }

    public void setColor(int x, int y, Color c) {
        for (int i = 0; i < _channels; i++) {
            _data[i][y * _width + x] = c.value(i);
        }
    }

    public float getValue(int x, int y, int c) {
        return _data[c][y * _width + x];
    }

    public void setValue(int x, int y, int c, float value) {
        _data[c][y * _width + x] = value;
    }

    public ColorInfo colorInfo() {
        return _colorInfo;
    }

    public boolean isInBounds(int x, int y) {
        return x >= 0 && x < _width && y >= 0 && y < _height;
    }
}
