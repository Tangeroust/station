#pragma once

#include <thread>
#include <iostream>
#include <string>

#include "railwayStation.h"

using std::cout;   using std::string;
using std::cin;    using std::thread;
using std::ref;

class Train {
private:
    thread* road;
    static RailwayStation placeArrival;
    static char designation;
    unsigned int travelTime;
    char symbol;

    void traffic();
    void departure();

public:
    Train();
    ~Train();

    void start();
};


