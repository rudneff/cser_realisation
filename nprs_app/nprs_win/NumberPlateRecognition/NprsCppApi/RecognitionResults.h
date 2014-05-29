#pragma once

#include "NumberPlate.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Text;

namespace NprsCppApi {

public ref class RecognitionResults
{
public:
    RecognitionResults(List<NumberPlate^>^ numberPlates) 
        : _numberPlates(numberPlates)
    {}

    property List<NumberPlate^>^ NumberPlates {
        List<NumberPlate^>^ get() {
            return _numberPlates;
        }
    }

    String^ ToString() override {
        StringBuilder^ sb = gcnew StringBuilder();
        sb->Append("RecognitionResults: [");

        for each(NumberPlate^ np in _numberPlates) {
            sb->AppendFormat("{0} ", np->ToString());
        }
        sb->Append("]");

        return sb->ToString();
    }

private:
    List<NumberPlate^>^ _numberPlates;
};

}


