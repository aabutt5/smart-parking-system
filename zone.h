#ifndef ZONE_H
#define ZONE_H
#include "ParkingArea.h"

class Zone {
public:
    int zoneID; // [cite: 111]
    ParkingArea* areas; // Array of areas [cite: 112]
    int areaCount;

    Zone();
    void initialize(int id, int aCount);
};
#endif