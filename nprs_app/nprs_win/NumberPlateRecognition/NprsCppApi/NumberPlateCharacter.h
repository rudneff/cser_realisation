#ifndef NUMBERPLATECHARACTER_H
#define NUMBERPLATECHARACTER_H

#include "Rectangle.h"

namespace NprsCppApi {

public ref class NumberPlateCharacter {
public:
    NumberPlateCharacter(int code, Rectangle^ bounds)
        : _code(code), _bounds(bounds)
    {}

    property int Code {
        int get() {
            return _code;
        }
    }

    property Rectangle^ Bounds {
        Rectangle^ get() {
            return _bounds;
        }
    }

    String^ ToString() override {
        return String::Format("( Bounds: {0}, Code: {1} )", _bounds, _code);
    }

private:
    int _code;
    Rectangle^ _bounds;
};

}

#endif // NUMBERPLATECHARACTER_H