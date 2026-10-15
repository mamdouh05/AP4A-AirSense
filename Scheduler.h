#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "Sensor.h"

#include <chrono>
#include <vector>

class Scheduler
{
private:
    std::vector<Sensor*> sensors;

public:
    Scheduler();
    Scheduler(const Scheduler& other);
    Scheduler& operator=(const Scheduler& other);
    ~Scheduler();

    void addSensor(Sensor* sensor);

    void simulation(std::chrono::seconds duration, std::chrono::milliseconds tick = std::chrono::milliseconds(100));
};

#endif