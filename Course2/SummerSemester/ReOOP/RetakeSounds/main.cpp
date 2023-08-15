//
// Created by Sybatron on 8/14/2023.
//
#include "Sound.h"
#include "Effect.h"

int main() {
    std::cout << "HELLO" << std::endl;
    Effect<double>::EffectLambdaType normalizationEffect = [](double sample, size_t index) -> double {
        double amplitudeBoundary = 1; // M
        if (std::abs(sample) > amplitudeBoundary) {
            return amplitudeBoundary;
        }
        return sample;
    };
}