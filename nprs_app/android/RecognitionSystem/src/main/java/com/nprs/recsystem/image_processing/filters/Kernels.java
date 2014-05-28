package com.nprs.recsystem.image_processing.filters;

public class Kernels {
    public static Mask createGaussian(int maskSize, float x_spread, float y_spread) {
        float[][] mask = new float[maskSize][maskSize];
        int halfSize = maskSize / 2;

        float sum = 0.0f;
        for (int x = - halfSize; x <= halfSize; x++) {
            for (int y = - halfSize; y <= halfSize; y++) {
                sum += mask[x + halfSize][y + halfSize] = (float) Math.exp (- ( (x * x) / (2.0f * x_spread * x_spread) + (y * y) / (2.0f * y_spread * y_spread) ) );
            }
        }

        for (int x = - halfSize; x <= halfSize; x++) {
            for (int y = - halfSize; y <= halfSize; y++) {
                mask[x + halfSize][y + halfSize] /= sum;
            }
        }

        return new Mask(mask, maskSize);
    }
}
