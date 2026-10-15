#include "LightSensor.h"

#include <random>

namespace
{
    std::mt19937& generator()
    {
        static std::mt19937 gen(std::random_device{}());
        return gen;
    }
}

LightSensor::LightSensor(Server* server, std::chrono::milliseconds period)
    : Sensor("Light", server, period)
{
}

std::string LightSensor::generateValue()
{
    std::bernoulli_distribution dist(0.5);

    return dist(generator()) ? "true" : "false";
}
