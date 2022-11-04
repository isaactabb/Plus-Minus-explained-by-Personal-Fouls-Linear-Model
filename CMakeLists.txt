cmake_minimum_required(VERSION 3.21)
project(M3OEP_itabb)

set(CMAKE_CXX_STANDARD 14)

add_executable(M3OEP_itabb main.cpp PlayerStats.h PlayerStats.cpp linearModelPrint.R plotGraphs.py)
