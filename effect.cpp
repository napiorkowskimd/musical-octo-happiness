#include "effect.h"

using namespace cv;

Effect::Effect()
{
    timer = new Timer("timer");
}

Effect::~Effect()
{
    delete timer;
}

void Effect::apply(Mat &input, Mat &output)
{
    output = input;
}
