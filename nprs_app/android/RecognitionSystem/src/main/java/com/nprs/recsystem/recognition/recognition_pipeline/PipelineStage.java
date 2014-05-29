package com.nprs.recsystem.recognition.recognition_pipeline;

public abstract class PipelineStage<TIn, TOut> {
    protected final PipelineStage<TOut, ?> _nextStage;

    protected PipelineStage(PipelineStage<TOut, ?> nextStage) {
        _nextStage = nextStage;
    }

    public abstract PipelineResource<TOut> doJob(PipelineResource<TIn> input);
}
