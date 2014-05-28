#ifndef RECTANGLE_H
#define RECTANGLE_H

using namespace System;

namespace NprsCppApi {

public ref class Rectangle {
public:
    Rectangle(float x, float y, float width, float height)
    {
        X = x;
        Y = y;
        Width = width;
        Height = height;
    }

    property float X;
    property float Y;
    property float Width;
    property float Height;

    String^ ToString() override {
        return String::Format("[ X: {0}, Y: {1} Width: {2}, Height: {3} ]", X, Y, Width, Height);
    }
};

}

#endif // RECTANGLE_H