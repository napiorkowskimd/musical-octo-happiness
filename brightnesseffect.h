#ifndef BRIGHTNESSEFFECT_H
#define BRIGHTNESSEFFECT_H

#include "effect.h"
#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>

class BrightnessEffect : public Effect
{
public:
    BrightnessEffect(int duration);
    void apply(cv::Mat &input, cv::Mat &output);
private:
    int duration;
};

#endif // BRIGHTNESSEFFECT_H
