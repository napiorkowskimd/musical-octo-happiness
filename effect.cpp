#include "effect.h"


Effect::Effect()
{
    timer = new Timer("timer");
}

Effect::~Effect()
{
    delete timer;
}

void Effect::apply(cv::Mat &mat)
{
    return;
}

void Effect::start()
{
    timer->stop();
    timer->reset();
    timer->start();
}


