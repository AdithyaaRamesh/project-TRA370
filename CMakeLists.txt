cmake_minimum_required(VERSION 3.5)
project(interface)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)

# Set options to avoid building Python bindings and examples
set(BUILD_PYTHON_BINDINGS OFF)

find_package(Threads REQUIRED)


# Add the crazyflie-link-cpp and crazyflie-lib-cpp directories
# add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/crazyflie-lib-cpp/crazyflie-link-cpp)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/crazyflie-lib-cpp)

include_directories(
    SYSTEM ${INCLUDE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/crazyflie-lib-cpp/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/crazyflie-lib-cpp/crazyflie-link-cpp/include
)

# Add custom command to generate messages.hpp from messages.odvd
add_custom_command(
    OUTPUT ${INCLUDE_DIR}/messages.hpp
    COMMAND cluon-msc --cpp --out=${INCLUDE_DIR}/messages.hpp ${CMAKE_CURRENT_SOURCE_DIR}/src/messages.odvd
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/messages.odvd
)


# Define the executable
add_executable(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/interface.cpp
               ${INCLUDE_DIR}/messages.hpp)


               target_link_libraries(${PROJECT_NAME}
    crazyflieLibCpp
    crazyflieLinkCpp
    Threads::Threads
)
