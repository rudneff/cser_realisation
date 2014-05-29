package com.nprs.recsystem.image_processing.filters;

import com.nprs.recsystem.common.image.Image;

public interface IImageFilter {
    Image apply(Image image);
}
