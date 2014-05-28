package com.nprs.recsystem.image_processing;

import com.nprs.recsystem.common.image.Color;
import com.nprs.recsystem.common.image.Image;
import com.nprs.recsystem.image_processing.filters.Mask;

public class Convolution {
    public static Color convolve(Mask mask, Image image, int x, int y) {
        int maskSize = mask.size();
        int maskMid = mask.size() / 2;
        Color sum = new Color(image.colorInfo());

        for (int mx = 0; mx < maskSize; mx++) {
            for (int my = 0; my < maskSize; my++) {
                int ix = mx + x - maskMid;
                int iy = mx + y - maskMid;

                if (image.isInBounds(ix, iy)) {
                    for (int i = 0; i < sum.numChannels(); i++) {
                        float pixValue = image.getValue(ix, iy, i);
                        sum.setValue(i, pixValue * mask.value(mx, my));
                    }
                }
            }
        }

        return sum;
    }

    public static Color convolve(Mask mask, Image image, int x, int y, int c) {
        int maskSize = mask.size();
        int maskMid = mask.size() / 2;
        Color sum = new Color(image.colorInfo());

        for (int mx = 0; mx < maskSize; mx++) {
            for (int my = 0; my < maskSize; my++) {
                int ix = mx + x - maskMid;
                int iy = mx + y - maskMid;

                if (image.isInBounds(ix, iy)) {
                    for (int i = 0; i < sum.numChannels(); i++) {
                        float pixValue = image.getValue(ix, iy, i);
                        sum.setValue(i, pixValue * mask.value(mx, my));
                    }
                }
            }
        }

        return sum;
    }
}
