# AirSense — IoT Air Quality Monitoring Simulator

## Overview

AirSense is a C++17 object-oriented project developed as part of the AP4A practical work at UTBM during Autumn 2026.

The project simulates an IoT ecosystem designed to monitor environmental conditions in a workplace using different types of sensors connected to a centralized server.

## Features

- **Temperature Sensor:** Simulates temperature measurements.
- **Humidity Sensor:** Simulates humidity measurements.
- **Sound Sensor:** Simulates sound level measurements.
- **Light Sensor:** Simulates light detection.
- **Centralized Server:** Receives, processes, displays, and logs sensor data.
- **Scheduler:** Organizes sensor execution and simulates periodic measurements.
- **Data Logging:** Stores measurements in log files for further analysis.

## Technologies

- C++17
- Object-Oriented Programming
- CMake
- GNU C++ Compiler (g++)

## Project Architecture

The simulator is organized around three main components:

- `Sensor`: Generates simulated environmental measurements.
- `Server`: Receives and manages data sent by sensors.
- `Scheduler`: Coordinates sensor execution.

Specialized sensor classes extend the base `Sensor` class to represent different environmental measurements.

## Compilation and Execution

### Prerequisites

- A C++17-compatible compiler, such as `g++`
- CMake
- Make or another supported build tool

### Build

```bash
cmake -S . -B build
cmake --build build
```

### Run

Execute the generated program from the build directory, using the executable name defined by the project.

For example, on Linux:

```bash
./build/AirSense
```

Adjust the executable path if your CMake configuration uses a different target name.

## Learning Objectives

This project demonstrates key C++ concepts, including:

- Classes, constructors, and destructors
- The Coplien canonical form
- Operator overloading
- Inheritance and polymorphism
- Virtual functions and abstract classes
- STL containers and algorithms
- Random data generation
- File handling and data logging
- Cross-platform compilation with CMake

## Academic Context

**Course:** AP4A — Object-Oriented Programming in C++  
**Academic Year:** Autumn 2026  
**Institution:** Université de Technologie de Belfort-Montbéliard (UTBM)
