cmake_minimum_required(VERSION 3.20)
project(WeddingAgency)

set(CMAKE_CXX_STANDARD 11)

add_executable(WeddingAgency
        main.cpp
        Person.h
        Person.cpp
        WeddingAgency.cpp
        WeddingAgency.h)
