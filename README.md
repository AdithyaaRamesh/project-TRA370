# Project-TRA370

A C++ interface that allows for relaying data from crazyflie 2.x drone to opendlv type microservices

## Changes to ensure a proper build

1. Add the following command to `CMakeLists.txt` in `crazyflie-lib-cpp` to account for the header files in `crazyflie-link-cpp` library:
   `${CMAKE_CURRENT_SOURCE_DIR}/crazyflie-lib-cpp/crazyflie-link-cpp/include`

2) Move the `PacketUtils.hpp` file from the `examples` folder of `crazyflie-link-cpp` to the `include/crazyflieLinkCpp` directory of the same library.


3) Set the following options to `OFF` in `CMakeLists.txt` of the `crazyflie-link-cpp` folder:
`option(BUILD_PYTHON_BINDINGS "Generate Python Bindings" OFF)`
`option(BUILD_CPP_EXAMPLES "Generate C++ Examples" OFF)`
