#include "railwayStation.h"

RailwayStation::RailwayStation()
{   }

RailwayStation::~RailwayStation()
{   }

void RailwayStation::blockStation(){
    block.lock();
}

void RailwayStation::unblockStation() {
    block.unlock();
}

bool RailwayStation::stationBusy(){
   return !block.try_lock();
}