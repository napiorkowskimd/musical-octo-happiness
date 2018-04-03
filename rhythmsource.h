#ifndef RHYTHMSOURCE_H
#define RHYTHMSOURCE_H

struct RhythmData
{
    RhythmData() {}
    float carrier_frequency;
    float duration;
    float period;
};

class RhythmSource
{
public:
    virtual RhythmData get_data() = 0;
};

#endif // RHYTHMSOURCE_H
