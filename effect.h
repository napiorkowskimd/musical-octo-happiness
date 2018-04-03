#ifndef EFFECT_H
#define EFFECT_H

#include "timer.h"
#include <opencv2/core.hpp>

class Effect
{
public:
    Effect();
    virtual ~Effect();
    virtual void apply(cv::Mat& mat);
    virtual void start();
protected:
    Timer* timer;
};

#endif // EFFECT_H
