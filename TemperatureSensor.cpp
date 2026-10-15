#include "TemperatureSensor.h"

#include <iomanip>
#include <random>
#include <sstream>

namespace
{
    std::mt19937& generator()
    {
        static std::mt19937 gen(std::random_device{}());
        return gen;
    }
}

TemperatureSensor::TemperatureSensor(Server* server, std::chrono::milliseconds period)
    : Sensor("Temperature", server, period)
{
}

std::string TemperatureSensor::generateValue()
{
    std::uniform_real_distribution<float> dist(-10.0f, 40.0f);

    std::ostringstream output;
    output << std::fixed << std::setprecision(2) << dist(generator());

    return output.str();
}
