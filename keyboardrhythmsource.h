#ifndef KEYBOARDRHYTHMSOURCE_H
#define KEYBOARDRHYTHMSOURCE_H
#include "rhythmsource.h"

class KeyboardRhythmSource : public RhythmSource
{
public:
    KeyboardRhythmSource();
    RhythmData get_data();
};

#endif // KEYBOARDRHYTHMSOURCE_H
