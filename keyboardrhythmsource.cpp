#include "keyboardrhythmsource.h"
#include <opencv2/highgui.hpp>

KeyboardRhythmSource::KeyboardRhythmSource()
{

}

RhythmData KeyboardRhythmSource::get_data()
{
    int key = cv::waitKey(1);
    RhythmData data;
    data.carrier_frequency = key;
    data.duration = 1;
    data.period = -1;
    return data;
}
