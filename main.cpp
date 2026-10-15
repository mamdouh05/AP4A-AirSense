#include "Server.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "SoundSensor.h"
#include "LightSensor.h"
#include "Scheduler.h"

#include <chrono>
#include <exception>
#include <iostream>

int main()
{
    try
    {
        Server server("Central Server");

        std::cout << server << "\n\n";

        TemperatureSensor temperature(&server, std::chrono::milliseconds(2000));

        HumiditySensor humidity(&server, std::chrono::milliseconds(3000));

        SoundSensor sound(&server, std::chrono::milliseconds(1000));

        LightSensor light(&server, std::chrono::milliseconds(5000));

        Scheduler scheduler;

        scheduler.addSensor(&temperature);
        scheduler.addSensor(&humidity);
        scheduler.addSensor(&sound);
        scheduler.addSensor(&light);

        std::cout << "Debut de la simulation...\n";

        scheduler.simulation(std::chrono::seconds(30));

        std::cout << "\nFin de la simulation.\n";
    }
    catch (const std::exception& e)
    {
        std::cerr << "Erreur : " << e.what() << '\n';
        return 1;
    }

    return 0;
}
