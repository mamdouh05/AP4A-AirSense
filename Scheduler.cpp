#include "Scheduler.h"

#include <algorithm>
#include <stdexcept>
#include <thread>

Scheduler::Scheduler()
{
}

Scheduler::Scheduler(const Scheduler& other) : sensors(other.sensors)
{
}

Scheduler& Scheduler::operator=(const Scheduler& other)
{
    if (this != &other)
        sensors = other.sensors;

    return *this;
}

Scheduler::~Scheduler()
{
}

void Scheduler::addSensor(Sensor* sensor)
{
    if (sensor != nullptr && std::find(sensors.begin(), sensors.end(), sensor) == sensors.end())
    {
        sensors.push_back(sensor);
    }
}

void Scheduler::simulation(std::chrono::seconds duration, std::chrono::milliseconds tick)
{
    if (duration.count() < 0 || tick.count() <= 0)
        throw std::invalid_argument("Duree ou intervalle invalide.");

    const auto endTime = std::chrono::steady_clock::now() + duration;

    while (std::chrono::steady_clock::now() < endTime)
    {
        for (Sensor* sensor : sensors)
        {
            if (sensor != nullptr)
                sensor->update();
        }

        std::this_thread::sleep_for(tick);
    }
}