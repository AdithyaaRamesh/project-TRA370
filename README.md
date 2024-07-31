# project-TRA370
A C++ interface that allows for relaying data from crazyflie 2.x drone to opendlv type microservices

# Changes to do to ensure a proper build:

1) Add the following command to CMakeLists.txt in crazyflie-lib-cpp to account for the header files in crazyflie-link-cpp library 

  ${CMAKE_CURRENT_SOURCE_DIR}/crazyflie-lib-cpp/include

2)  The PacketUtils.hpp file in examples folder of crazyflie-link-cpp should be placed in include/crazyflieLinkCpp of the same library.

3) Set the following commands to OFF in CMakeLists.txt of crazyflie-link-cpp folder

  BUILD_PYTHON_BINDINGS
  BUILD_CPP_EXAMPLES

  option(BUILD_PYTHON_BINDINGS "Generate Python Bindings" OFF)
  option(BUILD_CPP_EXAMPLES "Generate C++ Examples" OFF)
