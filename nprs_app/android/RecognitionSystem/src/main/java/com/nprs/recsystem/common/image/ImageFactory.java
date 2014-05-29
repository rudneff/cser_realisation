package com.nprs.recsystem.common.image;

public class ImageFactory {
    public static Image fromRgb888(int colors[], int width, int height) {
        Image result = new Image(width, height, ColorInfo.Rgb);

        for(int x = 0; x < width; x++) {
            for (int y = 0; y < height; y++) {

            }
        }

        return result;
    }
}
