package com.nprs.app.recognition.common_structures;

import java.util.ArrayList;
import java.util.List;

public class NumberPlate {
    private final List<NumberPlateCharacter> _characters;
    private final Rectangle _bounds;

    public NumberPlate(float x, float y, float width, float height) {
        this(new ArrayList<NumberPlateCharacter>(), new Rectangle(x, y, width, height));
    }

    public NumberPlate(List<NumberPlateCharacter> characters, Rectangle bounds) {
        _characters = characters;
        _bounds = bounds;
    }

    public List<NumberPlateCharacter> getCharacters() {
        return _characters;
    }

    public Rectangle getBounds() {
        return _bounds;
    }

    // for JNI
    public void addCharacter(float bx, float by, float bwidth, float bheight, short code) {
        _characters.add(new NumberPlateCharacter(code, new Rectangle(bx, by, bwidth, bheight)));
    }
}
