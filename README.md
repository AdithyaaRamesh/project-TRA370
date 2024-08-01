# Project-TRA370

A C++ interface that allows for relaying data from Crazyflie 2.x drone to OpenDLV type microservices. This program is created with the help of two publicly available libraries: one made by the Crazyflie team itself and another by a GitHub user. The source file includes a .cpp file and a messages.odvd file. The messages.odvd file is custom-made to send and receive important telemetry data of the Crazyflie 2.x drone in an OpenDLV framework. To know more about OpenDLV, libcluon, and the odvd message format, please refer to this link [Opendlv](https://opendlv.org/learn.html). The interface program is intended to send takeoff commands and the position and orientation data to systems listening on a specific network in odvd format. It is also designed to receive inputs from another system in odvd format, converts that into packets, and sends them to the Crazyflie drone.

## Changes to ensure a proper build

1) Add the following command to `CMakeLists.txt` in `crazyflie-lib-cpp` to account for the header files in `crazyflie-link-cpp` library:
   `${CMAKE_CURRENT_SOURCE_DIR}/crazyflie-lib-cpp/crazyflie-link-cpp/include`

2) Move the `PacketUtils.hpp` file from the `examples` folder of `crazyflie-link-cpp` to the `include/crazyflieLinkCpp` directory of the same library.


3) Set the following options to `OFF` in `CMakeLists.txt` of the `crazyflie-link-cpp` folder:
`option(BUILD_PYTHON_BINDINGS "Generate Python Bindings" OFF)`
`option(BUILD_CPP_EXAMPLES "Generate C++ Examples" OFF)`

4) Change the `address` in crazyflie object to match the address of your crazyflie.

## How to install and then compile:
1) `git clone --recursive https://github.com/Rishikeshvishnu/project-TRA370.git`
2) `mkdir build && cd build`
3) `cmake ..`
4) `make` (Some other example programs from crazyflie-lib-cpp repo. will also be downloaded)
5) `./interface` 

# Simulation

The `conetrack` folder in the `simulation` folder contains the objects in the 3D simulation including the texture and the `.obj` files for the vehicle 
## Prerequisites

1. Install **Docker:** https://www.docker.com/get-started.
2. Install **Docker Compose:**https://docs.docker.com/compose/install/

## Setup Instructions

1. **Allow Docker to Access Desktop Environment:**

   Run the following command to enable Docker to open new windows on the display:
   ```bash
   xhost +
   ```
   Note: This step needs to be repeated each time you restart your program.

2. **Start the Application:**

   Launch the application using the following command:
   ```bash
   docker-compose -f simulation-kiwi-v7.yml up
   ```

- **Docker**: Ensure Docker is installed for your platform. You can download it from the 
- **docker-compose**: Install docker-compose to manage multi-container Docker applications. Follow the installation guide.
   
