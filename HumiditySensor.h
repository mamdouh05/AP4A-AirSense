#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H

#include "Sensor.h"

class HumiditySensor : public Sensor
{
public:
    HumiditySensor(Server* server, std::chrono::milliseconds period = std::chrono::milliseconds(3000));

protected:
    std::string generateValue() override;
};

#endif
