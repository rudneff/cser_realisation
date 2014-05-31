// NprsCppApi.h

#pragma once

#include "RecognitionResults.h"

#include <rec_system/RecognitionSystem.h>
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <rec_system/common_structures/NumberPlateCharacter.h>
#include <common/image/Image.h>

using namespace System;
using namespace System::Collections;
using namespace System::Drawing;

#pragma comment(lib, "recognition_system.lib")
#pragma comment(lib, "common.lib")

template <typename T> using ptr = std::shared_ptr<T>;

namespace NprsCppApi {

public enum class PixelFormat {
    RGB24, BGRA32
};

public ref class NativeRecognizer
{
public:
    NativeRecognizer() {
    }

    ~NativeRecognizer() {
    }

    RecognitionResults^ Recognize(array<Byte>^ image, PixelFormat pixelFormat, int width, int height) {
        nprs::RecognitionSystem recSystem;
        pin_ptr<Byte> ptr = &image[0];
        uchar* imgData = ptr;
        nprs::pRecognitionResults results = recSystem.recognize(nprs::Image<uchar>(imgData, width, height, PixFormatToColorInfo(pixelFormat)));

        return ConvertResults(results);
    }

private:
    RecognitionResults^ ConvertResults(nprs::pRecognitionResults &src) {
        List<NumberPlate^>^ numPlates = gcnew List<NumberPlate^>();
        for (auto numPlate : src->numberPlates()) {
            numPlates->Add(ConvertNumberPlate(numPlate));
        }

        array<Byte>^ image = gcnew array<Byte>(src->resultImage().width() * src->resultImage().height() * src->resultImage().getColorInfo().numChannels());

        return gcnew RecognitionResults(numPlates, image);
    }

    NumberPlate^ ConvertNumberPlate(ptr<nprs::NumberPlate> src) {
        List<NumberPlateCharacter^>^ charList = gcnew List<NumberPlateCharacter^>();
        for (ptr<nprs::NumberPlateCharacter> character : src->characters()) {
            charList->Add(ConvertNumberPlateCharacter(character));
        }

        Rectangle^ bounds = ConvertRectangle(src->bounds());
        return gcnew NumberPlate(bounds, charList);
    }

    NumberPlateCharacter^ ConvertNumberPlateCharacter(ptr<nprs::NumberPlateCharacter> src) {
        return gcnew NumberPlateCharacter(src->code(), ConvertRectangle(src->bounds()));
    }

    Rectangle^ ConvertRectangle(const nprs::Rectangle &src) {
        return gcnew Rectangle(src.x(), src.y(), src.width(), src.height());
    }

    nprs::ColorInfo PixFormatToColorInfo(PixelFormat pf) {
        switch (pf) {
        case PixelFormat::RGB24:
            return nprs::ColorInfo::RgbByte255();
        case PixelFormat::BGRA32:
            return nprs::ColorInfo::BgraByte255();
        }
    }
};

}
