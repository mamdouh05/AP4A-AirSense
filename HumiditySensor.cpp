#include "HumiditySensor.h"

#include <iomanip>
#include <random>
#include <sstream>

namespace
{
    std::mt19937 &generator()
    {
        static std::mt19937 gen(std::random_device{}());
        return gen;
    }
}

HumiditySensor::HumiditySensor(Server *server, std::chrono::milliseconds period)
    : Sensor("Humidity", server, period)
{
}

std::string HumiditySensor::generateValue()
{
    std::uniform_real_distribution<float> dist(0.0f, 100.0f);

    std::ostringstream output;
    output << std::fixed << std::setprecision(2) << dist(generator());

    return output.str();
}
