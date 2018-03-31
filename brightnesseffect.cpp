#include "brightnesseffect.h"

BrightnessEffect::BrightnessEffect(int duration) : duration(duration)
{

}

void BrightnessEffect::apply(cv::Mat &input, cv::Mat &output)
{
    timer->update();
    int elapsed = timer->get_total_time();
    double half_duration = duration/2.0;
    if(elapsed > duration){
        timer->reset();
        input.copyTo(output);
        return;
    }
    double a = 100.0/half_duration;
    if(elapsed < half_duration){
        int delta = a*elapsed;
        output = input + cv::Scalar(0, delta, 0);
        return;
    }
    if(elapsed >= half_duration){
        int b = 200;
        int delta = -a*elapsed + b;
        output = input + cv::Scalar(0, delta, 0);
        return;
    }
    return;
}
