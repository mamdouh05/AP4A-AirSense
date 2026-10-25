#include "Sensor.h"

#include <iostream>
#include <stdexcept>

int Sensor::nextId = 1;

Sensor::Sensor(const std::string& type, Server* server, std::chrono::milliseconds period)
    : id(nextId++),
      type(type),
      value("0"),
      server(server),
      period(period),
      lastExecution(std::chrono::steady_clock::now() - period)
{
    if (period.count() <= 0)
        throw std::invalid_argument("La periode doit etre positive.");
}

Sensor::~Sensor() = default;

void Sensor::update()
{
    const auto now = std::chrono::steady_clock::now();
    if (now - lastExecution >= period)
    {
        execute();
        lastExecution = now;
    }
}

void Sensor::execute()
{
    value = generateValue();
    if (server == nullptr)
    {
        std::cerr << "Aucun serveur pour le capteur " << id << '\n';
        return;
    }
    server->consoleWrite(type, id, value);
    server->fileWrite(type, id, value);
}

int Sensor::getId() const
{
    return id;
}

const std::string& Sensor::getType() const
{
    return type;
}
