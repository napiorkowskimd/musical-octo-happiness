#include "brightnesseffect.h"


BrightnessEffect::BrightnessEffect(int duration, int delta) : duration(duration), delta(delta)
{

}

void BrightnessEffect::apply(cv::Mat &mat)
{
    timer->update();
    int elapsed = timer->get_total_time();
    double half_duration = duration/2.0;
    if(elapsed > duration){
        return;
    }
    double a = double(delta)/half_duration;
    if(elapsed < half_duration){
        int delta = a*elapsed;
        mat += cv::Scalar(0, delta, 0);
        return;
    }
    if(elapsed >= half_duration){
        int b = 2*delta;
        int delta = -a*elapsed + b;
        mat += cv::Scalar(0, delta, 0);
        return;
    }
    return;
}
