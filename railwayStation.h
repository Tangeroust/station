#pragma once

#include <mutex>

using std::mutex;

class RailwayStation {
private:
    mutex block;

public:
    RailwayStation();
    ~RailwayStation();

    void blockStation();
    void unblockStation();
    bool stationBusy();
};


