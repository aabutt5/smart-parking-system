#include "Zone.h"

Zone::Zone() : zoneID(-1), areas(nullptr), areaCount(0) {}

void Zone::initialize(int id, int aCount) {
    zoneID = id;
    areaCount = aCount;
    areas = new ParkingArea[aCount];
    for (int i = 0; i < aCount; i++) {
        areas[i].initialize(5, id); // Each area gets 5 slots for example
    }
}