package com.nprs.app.recognition.common_structures.serialization;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

public interface ISerializer<T> {
    T fromStream(InputStream stream) throws IOException;
    void toStream(T object, OutputStream stream) throws IOException;
}
