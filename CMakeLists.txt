cmake_minimum_required(VERSION 3.26)
project(MolecularDynamics)

set(CMAKE_CXX_STANDARD 17)

add_executable(MolecularDynamics main.cpp
        src/engine/Particle.cpp
        src/engine/Particle.h
        src/general/constants.h
        src/general/params.h
        src/engine/System.cpp
        src/engine/System.h)
