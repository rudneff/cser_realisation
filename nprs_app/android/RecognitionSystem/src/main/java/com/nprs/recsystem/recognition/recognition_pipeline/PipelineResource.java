package com.nprs.recsystem.recognition.recognition_pipeline;

public class PipelineResource<T> {
    private final T _value;

    public PipelineResource(T value) {
        this._value = value;
    }

    public T value() {
        return _value;
    }
}
