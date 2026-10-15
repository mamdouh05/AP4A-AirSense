#ifndef SOUND_SENSOR_H
#define SOUND_SENSOR_H

#include "Sensor.h"

class SoundSensor : public Sensor
{
public:
    SoundSensor(Server* server, std::chrono::milliseconds period = std::chrono::milliseconds(1000));

protected:
    std::string generateValue() override;
};

#endif
