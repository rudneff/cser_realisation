#include <qdebug.h>
#include <qimage.h>
#include <rec_system/RecognitionSystem.h>
#include <rec_system/common_structures/RecognitionResults.h>
#include <rec_system/common_structures/NumberPlate.h>
#include <chrono>

using namespace nprs;

int main(int argc, char **argv) {
    QImage image = QImage("C:/numplates/mul.jpg").convertToFormat(QImage::Format_RGB888);
    RecognitionSystem rs;

    using std::chrono::high_resolution_clock;
    using std::chrono::milliseconds;
    
    auto beforeTime = high_resolution_clock::now();
    auto results = rs.recognize(image.bits(), image.width(), image.height(), ColorInfo(ColorFormat::RGB, 3));
    auto afterTime = high_resolution_clock::now();
    int ms = std::chrono::duration_cast<milliseconds>(afterTime - beforeTime).count();

    qDebug() << "recognition took " << ms << " ms";
}
