#ifndef NUMBER_PLATE_H
#define NUMBER_PLATE_H

#include "NumberPlateCharacter.h"

using namespace System;
using namespace System::Text;
using namespace System::Collections::Generic;

namespace NprsCppApi {

public ref class NumberPlate {
public:
    NumberPlate(Rectangle^ bounds, List<NumberPlateCharacter^>^ characters)
        : _bounds(bounds), _characters(characters)
    {}

    property Rectangle^ Bounds {
        Rectangle^ get() {
            return _bounds;
        }
    }

    property List<NumberPlateCharacter^>^ Characters {
        List<NumberPlateCharacter^>^ get() {
            return _characters;
        }
    }

    String^ ToString() override {
        StringBuilder^ sb = gcnew StringBuilder();
        sb->AppendFormat("( Bounds: {0}, Characters: [", _bounds);

        for each(NumberPlateCharacter^ ch in _characters) {
            sb->AppendFormat("{0} ", ch->ToString());
        }
        sb->Append(")");

        return sb->ToString();
    }

private:
    Rectangle^ _bounds;
    List<NumberPlateCharacter^>^ _characters;
};

}

#endif // NUMBER_PLATE_H