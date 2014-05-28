package com.nprs.recsystem.image_processing.filters;

import com.nprs.recsystem.common.exceptions.ArgumentException;
import com.nprs.recsystem.common.image.Image;
import com.nprs.recsystem.image_processing.Convolution;

public class SimpleMaskFilter implements IImageFilter {
    private final Mask _mask;

    public SimpleMaskFilter(Mask mask) throws ArgumentException {
        _mask = mask;
    }

    public Mask mask() {
        return _mask;
    }

    @Override
    public Image apply(Image image) {
        Image res = new Image(image.width(), image.height(), image.colorInfo());

        for (int x = 0; x < res.width(); x++) {
            for (int y = 0; y < res.height(); y++) {
                res.setColor(x, y, Convolution.convolve(_mask, image, x, y));
            }
        }

        return res;
    }
}
