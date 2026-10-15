#ifndef LIGHT_SENSOR_H
#define LIGHT_SENSOR_H

#include "Sensor.h"

class LightSensor : public Sensor
{
public:
    LightSensor(Server* server, std::chrono::milliseconds period = std::chrono::milliseconds(5000));

protected:
    std::string generateValue() override;
};

#endif