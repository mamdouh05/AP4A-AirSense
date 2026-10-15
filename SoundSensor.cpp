#include "SoundSensor.h"

#include <random>

namespace
{
    std::mt19937& generator()
    {
        static std::mt19937 gen(std::random_device{}());
        return gen;
    }
}

SoundSensor::SoundSensor(Server* server, std::chrono::milliseconds period)
    : Sensor("Sound", server, period)
{
}

std::string SoundSensor::generateValue()
{
    std::uniform_int_distribution<int> dist(0, 120);

    return std::to_string(dist(generator()));
}
