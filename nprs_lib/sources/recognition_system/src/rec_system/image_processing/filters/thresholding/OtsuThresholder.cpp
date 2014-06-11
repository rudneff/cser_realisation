#include "OtsuThresholder.h"
#include <common/image/Image.h>
#include <cmath>

using namespace nprs;

float OtsuThresholder::findThreshold(const Image &image, int channel) {
    std::vector<float> hist = histogram(image, channel);
    std::vector<float> vet(256);
    for (int k = 1; k < 256; k++) {
        float p1 = px(0, k, hist);
        float p2 = mx(k + 1, 255, hist);
        float p12 = p1 * p2;
        p12 = fmax(p12, 1.0f);
        double diff = (mx(0, k, hist) * p2) - (mx(k + 1, 255, hist) * p1);
        vet[k] = diff * diff / p12;
    }
    int t = findMaxIndex(vet);
    return t / 256.0f;
}

// function is used to compute the q values in the equation
double OtsuThresholder::px(int init, int end, const std::vector<float> &hist)
{
    int sum = 0;
    for (int i = init; i <= end; i++)
        sum += hist[i];

    return sum;
}

// function is used to compute the mean values in the equation (mu)
double OtsuThresholder::mx(int init, int end, const std::vector<float> &hist) {
    int sum = 0;
    for (int i = init; i <= end; i++)
        sum += i * hist[i];
    return sum;
}

int OtsuThresholder::findMaxIndex(const std::vector<float> &vec) {
    double max = vec[0];
    int maxIndex = 0;

    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] > max) {
            max = vec[i];
            maxIndex = i;
        }
    }

    return maxIndex;
}

std::vector<float> OtsuThresholder::histogram(const Image &image, int channel) {
    std::vector<float> hist(256);
    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            int intensity = image(x, y, channel) * 255;
            hist[intensity] += 1.0f;
        }
    }

    return hist;
}
