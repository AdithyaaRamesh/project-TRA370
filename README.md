# Project-TRA370

A C++ interface that allows for relaying data from Crazyflie 2.x drone to OpenDLV type microservices. This program is created with the help of two publicly available libraries: one made by the Crazyflie team itself and another by a GitHub user. The source file includes a .cpp file and a messages.odvd file. The messages.odvd file is custom-made to send and receive important telemetry data of the Crazyflie 2.x drone in an OpenDLV framework. To know more about OpenDLV, libcluon, and the odvd message format, please refer to this [link](https://opendlv.org/learn.html). The interface program is intended to send takeoff commands and the position and orientation data to systems listening on a specific network in odvd format. It is also designed to receive inputs from another system in odvd format, converts that into packets, and sends them to the Crazyflie drone.

## Changes to ensure a proper build

1) Add the following command to `CMakeLists.txt` in `crazyflie-lib-cpp` to account for the header files in `crazyflie-link-cpp` library:
   `${CMAKE_CURRENT_SOURCE_DIR}/crazyflie-lib-cpp/crazyflie-link-cpp/include`

2) Move the `PacketUtils.hpp` file from the `examples` folder of `crazyflie-link-cpp` to the `include/crazyflieLinkCpp` directory of the same library.


3) Set the following options to `OFF` in `CMakeLists.txt` of the `crazyflie-link-cpp` folder:
`option(BUILD_PYTHON_BINDINGS "Generate Python Bindings" OFF)`
`option(BUILD_CPP_EXAMPLES "Generate C++ Examples" OFF)`

## How to install and then compile:
1) `git clone --recursive https://github.com/Rishikeshvishnu/project-TRA370.git`
2) `mkdir build && cd build`
3) `cmake ..`
4) `make`
5) `./interface` (Some other example programs from crazyflie-lib-cpp repo. will also be downloaded)
