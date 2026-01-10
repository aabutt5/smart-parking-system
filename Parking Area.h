#ifndef PARKINGAREA_H
#define PARKINGAREA_H
#include "ParkingSlot.h"

class ParkingArea {
public:
    ParkingSlot* slots; // Array of slots
    int slotCount;

    ParkingArea();
    void initialize(int count, int zID);
};
#endif