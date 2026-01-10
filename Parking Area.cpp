#include "ParkingArea.h"

ParkingArea::ParkingArea() : slots(nullptr), slotCount(0) {}

void ParkingArea::initialize(int count, int zID) {
    slotCount = count;
    slots = new ParkingSlot[count]; // Manual memory management (No STL)
    for (int i = 0; i < count; i++) {
        slots[i] = ParkingSlot(i + 1, zID);
    }
}