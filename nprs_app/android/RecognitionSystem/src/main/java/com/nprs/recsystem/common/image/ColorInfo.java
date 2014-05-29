package com.nprs.recsystem.common.image;

public class ColorInfo {
    private final int _numChannels;
    private final ColorFormat _format;

    public static final ColorInfo Rgb = new ColorInfo(3, ColorFormat.RGB);

    public ColorInfo(int numChannels) {
        this(numChannels, ColorFormat.UNKNOWN);
    }

    public ColorInfo(int numChannels, ColorFormat colorFormat) {
        _numChannels = numChannels;
        _format = colorFormat;
    }

    public int numChannels() {
        return _numChannels;
    }

    public ColorFormat colorFormat() {
        return _format;
    }
}
