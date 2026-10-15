cmake_minimum_required(VERSION 3.16)

project(AP4A-Project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(AP4A-Project
    main.cpp
    Server.cpp
    Sensor.cpp
    TemperatureSensor.cpp
    HumiditySensor.cpp
    SoundSensor.cpp
    LightSensor.cpp
    Scheduler.cpp
)

target_link_libraries(AP4A-Project PRIVATE Threads::Threads)
