#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "Sensor.h"

class TemperatureSensor : public Sensor
{
public:
    TemperatureSensor(Server* server, std::chrono::milliseconds period = std::chrono::milliseconds(2000));

protected:
    std::string generateValue() override;
};

#endif
