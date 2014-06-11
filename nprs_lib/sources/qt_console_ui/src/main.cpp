#include <qdebug.h>
#include <qimage.h>
#include <rec_system/RecognitionSystem.h>
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <common/image/Bitmap.h>
#include <chrono>

using namespace nprs;

void performRecognition(QImage &image);

int main(int argc, char **argv) {
    QImage image = QImage("C:/Users/vardan/Desktop/cars/images00067.png").convertToFormat(QImage::Format_RGB888);
    
    for (int i = 0; i < 100; i++) {
        performRecognition(image);
    }

    return 0;
}

void performRecognition(QImage &image) {
    RecognitionSystem rs;

    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;

    Bitmap rawImage(image.bits(), image.width(), image.height(), ColorInfo(ColorFormat::RGB, 3));
    auto beforeTime = high_resolution_clock::now();
    auto results = rs.recognize(rawImage);
    auto afterTime = high_resolution_clock::now();
    int ms = std::chrono::duration_cast<milliseconds>(afterTime - beforeTime).count();

    qDebug() << "recognition took " << ms << " ms";
}
