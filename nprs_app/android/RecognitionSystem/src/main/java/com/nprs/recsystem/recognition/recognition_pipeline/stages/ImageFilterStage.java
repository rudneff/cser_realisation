package com.nprs.recsystem.recognition.recognition_pipeline.stages;

import com.nprs.recsystem.common.image.Image;
import com.nprs.recsystem.image_processing.filters.IImageFilter;
import com.nprs.recsystem.recognition.recognition_pipeline.PipelineResource;
import com.nprs.recsystem.recognition.recognition_pipeline.PipelineStage;


public class ImageFilterStage extends PipelineStage<Image, Image> {
    private final IImageFilter _filter;

    public ImageFilterStage(IImageFilter filter, PipelineStage<Image, ?> nextStage) {
        super(nextStage);
        _filter = filter;
    }

    @Override
    public PipelineResource<Image> doJob(PipelineResource<Image> input) {
        return new PipelineResource<>(_filter.apply(input.value()));
    }
}
