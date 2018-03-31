#ifndef EFFECT_H
#define EFFECT_H

#include "timer.h"
#include <opencv2/opencv.hpp>

class Effect
{
public:
    Effect();
    ~Effect();
    void apply(cv::Mat& input, cv::Mat& output);
protected:
    Timer* timer;
};

#endif // EFFECT_H
