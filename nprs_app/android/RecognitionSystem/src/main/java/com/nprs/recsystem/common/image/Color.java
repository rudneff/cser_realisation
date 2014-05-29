package com.nprs.recsystem.common.image;

public class Color {
    private final float[] _values;
    private final int _numChannels;
    private final ColorInfo _colorInfo;

    public Color(ColorInfo colorInfo) {
        _numChannels = colorInfo.numChannels();
        _colorInfo = colorInfo;
        _values = new float[colorInfo.numChannels()];
    }

    public Color(float[] values, ColorInfo colorInfo) {
        _colorInfo = colorInfo;
        _numChannels = values.length;
        _values = values;
    }

    public float[] getValues() {
        return _values;
    }

    public float value(int channel) {
        return _values[channel];
    }

    public void setValue(int channel, float value) {
        _values[channel] = value;
    }

    public int numChannels() {
        return _numChannels;
    }

    public ColorInfo getColorInfo() {
        return _colorInfo;
    }
}
