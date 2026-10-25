#ifndef SENSOR_H
#define SENSOR_H

#include "Server.h"

#include <chrono>
#include <string>

class Sensor
{
private:
    static int nextId;
    int id;
    std::string type;
    std::string value;
    Server* server;
    std::chrono::milliseconds period;
    std::chrono::steady_clock::time_point lastExecution;

protected:
    virtual std::string generateValue() = 0;

public:
    Sensor(const std::string& type, Server* server, std::chrono::milliseconds period);
    virtual ~Sensor();

    virtual void update();

    void execute();

    int getId() const;

    const std::string& getType() const;
};

#endif
