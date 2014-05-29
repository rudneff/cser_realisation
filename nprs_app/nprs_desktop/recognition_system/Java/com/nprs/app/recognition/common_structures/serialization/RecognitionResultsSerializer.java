package com.nprs.app.recognition.common_structures.serialization;

import com.nprs.app.recognition.common_structures.RecognitionResults;
import com.nprs.app.recognition.common_structures.NumberPlate;
import com.nprs.app.recognition.common_structures.NumberPlateCharacter;
import com.nprs.app.recognition.common_structures.Rectangle;

import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.ArrayList;

public class RecognitionResultsSerializer implements ISerializer<RecognitionResults> {
    private final ISerializer<NumberPlate> _numberPlateISerializer = new NumberPlateSerializer();

    @Override
    public RecognitionResults fromStream(InputStream stream) throws IOException {
        ArrayList<NumberPlate> numberPlates = new ArrayList<>();

        DataInputStream reader = new DataInputStream(stream);

        int numNumberPlates = reader.readInt();
        for (int i = 0; i < numNumberPlates; i++) {
            numberPlates.add(_numberPlateISerializer.fromStream(stream));
        }
        return new RecognitionResults(numberPlates);
    }

    @Override
    public void toStream(RecognitionResults object, OutputStream stream) throws IOException {
        DataOutputStream writer = new DataOutputStream(stream);
        writer.writeInt(object.getNumberPlates().size());
        for (NumberPlate numberPlate : object.getNumberPlates()) {
            _numberPlateISerializer.toStream(numberPlate, stream);
        }
    }
}

class NumberPlateSerializer implements ISerializer<NumberPlate> {
    private final ISerializer<NumberPlateCharacter> _characterSerializer = new NumberPlateCharacterSerializer();
    private final ISerializer<Rectangle> _rectangleSerializer = new RectangleSeriazlier();

    @Override
    public NumberPlate fromStream(InputStream stream) throws IOException {
        DataInputStream reader = new DataInputStream(stream);
        Rectangle bounds = _rectangleSerializer.fromStream(stream);
        int charCount = reader.readInt();
        ArrayList<NumberPlateCharacter> characters = new ArrayList<>();
        for (int i = 0; i < charCount; i++) {
            characters.add(_characterSerializer.fromStream(stream));
        }
        return new NumberPlate(characters, bounds);
    }

    @Override
    public void toStream(NumberPlate object, OutputStream stream) throws IOException {
        DataOutputStream writer = new DataOutputStream(stream);
        _rectangleSerializer.toStream(object.getBounds(), stream);
        writer.writeInt(object.getCharacters().size());
        for (NumberPlateCharacter character : object.getCharacters()) {
            _characterSerializer.toStream(character, stream);
        }
    }
}

class NumberPlateCharacterSerializer implements ISerializer<NumberPlateCharacter> {
    private final ISerializer<Rectangle> _rectangleISerializer = new RectangleSeriazlier();

    @Override
    public NumberPlateCharacter fromStream(InputStream stream) throws IOException {
        DataInputStream reader = new DataInputStream(stream);
        Rectangle bounds = _rectangleISerializer.fromStream(stream);
        short code = reader.readShort();
        return new NumberPlateCharacter(code, bounds);
    }

    @Override
    public void toStream(NumberPlateCharacter object, OutputStream stream) throws IOException {
        DataOutputStream writer = new DataOutputStream(stream);
        _rectangleISerializer.toStream(object.getBounds(), stream);
        writer.writeShort(object.getCode());
    }
}

class RectangleSeriazlier implements ISerializer<Rectangle> {
    @Override
    public Rectangle fromStream(InputStream stream) throws IOException {
        DataInputStream reader = new DataInputStream(stream);
        float x = reader.readFloat();
        float y = reader.readFloat();
        float width = reader.readFloat();
        float height = reader.readFloat();
        return new Rectangle(x, y, width, height);
    }

    @Override
    public void toStream(Rectangle object, OutputStream stream) throws IOException {
        DataOutputStream writer = new DataOutputStream(stream);
        writer.writeFloat(object.x());
        writer.writeFloat(object.y());
        writer.writeFloat(object.width());
        writer.writeFloat(object.height());
    }
}



