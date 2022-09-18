cmake_minimum_required(VERSION 3.20)
project(Trains)

set(CMAKE_CXX_STANDARD 11)

add_executable(Trains
        main.cpp
        TrainStation.cpp
        TrainStation.h
        Train.cpp
        Train.h)
