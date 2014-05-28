//package com.nprs.app.tools;
//
//import android.graphics.Bitmap;
//import com.nprs.recsystem.common.exceptions.ArgumentException;
//import com.nprs.recsystem.common.image.ColorFormat;
//import com.nprs.recsystem.common.image.ColorInfo;
//import com.nprs.recsystem.common.image.Image;
//
//
//public class ImageConverter {
//    public static Image bmpToRsImage(Bitmap bmp) {
//        Image res = new Image(bmp.getWidth(), bmp.getHeight(), ColorInfo.Rgb);
//        int[] pixels = new int[bmp.getWidth() * bmp.getHeight()];
//        bmp.getPixels(pixels, 0, bmp.getWidth(), 0, 0, bmp.getWidth(), bmp.getHeight());
//
//        for(int x = 0; x < bmp.getWidth(); x++) {
//            for (int y = 0; y < bmp.getHeight(); y++) {
//                int c = pixels[x + bmp.getWidth() * y];
//                res.setValue(x, y, 0, android.graphics.Color.red(c));
//                res.setValue(x, y, 1, android.graphics.Color.green(c));
//                res.setValue(x, y, 2, android.graphics.Color.blue(c));
//            }
//        }
//
//        return res;
//    }
//
//    public static Bitmap rsImageToBitmap(Image image) throws ArgumentException {
//        int[] colors = new int[image.width() * image.height()];
//
//        for (int x = 0; x < image.width(); x++) {
//            for (int y = 0; y < image.height(); y++) {
//                try {
//                    colors[x + y * image.width()] = colorToInt(image, x, y);
//                } catch (ArgumentException e) {
//                    throw new ArgumentException("ImageConverter.rsImageToBitmap: Failed to convert image to bitmap. " + e.getMessage());
//                }
//            }
//        }
//
//        return Bitmap.createBitmap(colors, image.width(), image.height(), Bitmap.Config.ARGB_8888);
//    }
//
//    private static int colorToInt(Image image, int x, int y) throws ArgumentException {
//        int res = -1;
//
//        if (image.numChannels() == 3 && image.colorInfo().colorFormat() == ColorFormat.RGB) {
//            res = android.graphics.Color.argb(255, (int) (image.getValue(x, y, 0)),
//                    (int) (image.getValue(x, y, 1)),
//                    (int) (image.getValue(x, y, 2)));
//        }
//        else if (image.numChannels() == 1 && image.colorInfo().colorFormat() == ColorFormat.INTENSITY) {
//            int value = (int) (255 * image.getValue(x, y, 0));
//            res = android.graphics.Color.argb(255, value, value, value);
//        }
//        else {
//            throw new ArgumentException("ImageConverter.colorToInt(): Unknown image format");
//        }
//
//        return res;
//    }
//}
