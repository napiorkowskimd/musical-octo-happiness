#ifndef BRIGHTNESSEFFECT_H
#define BRIGHTNESSEFFECT_H

#include "effect.h"
#include "rhythmsource.h"

class BrightnessEffect : public Effect
{
public:
    BrightnessEffect(int duration, int delta);
    void apply(cv::Mat &mat);
private:
    int duration;
    int delta;
};

#endif // BRIGHTNESSEFFECT_H
