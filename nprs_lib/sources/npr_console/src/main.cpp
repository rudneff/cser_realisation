using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
using namespace NprsCppApi;

int main(array<String^> ^args) {
    Bitmap ^image = gcnew Bitmap("C:\\numplates\\mul.jpg");
    Bitmap ^clone = gcnew Bitmap(image);
    Bitmap ^converted = clone->Clone(Drawing::Rectangle(0,0, clone->Width, clone->Height),Imaging::PixelFormat::Format24bppRgb);

    Imaging::BitmapData ^bmpData = image->LockBits(Drawing::Rectangle(0,0,converted->Width, converted->Height), Imaging::ImageLockMode::ReadOnly, converted->PixelFormat);

    Console::WriteLine(converted->PixelFormat);

    array<Byte> ^bytes = gcnew array<Byte>(bmpData->Stride * bmpData->Height);
    Marshal::Copy(bmpData->Scan0, bytes, 0, bytes->Length);

    NativeRecognizer ^recognizer = gcnew NativeRecognizer();
    RecognitionResults ^results = recognizer->Recognize(bytes, PixelFormat::RGB24, converted->Width, converted->Height);

    Graphics ^g = Graphics::FromImage(clone);
    for each(NumberPlate ^np in results->NumberPlates) {
        g->DrawRectangle(Pens::Red, Drawing::Rectangle(np->Bounds->X, np->Bounds->Y, np->Bounds->Width, np->Bounds->Height));
    }

    clone->Save("result.jpg");
}
