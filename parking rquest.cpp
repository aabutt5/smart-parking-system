#include "ParkingSlot.h"

// Use the ParkingSlot:: prefix so the compiler knows these belong to the class
ParkingSlot::ParkingSlot() : slotId(-1), zoneId(-1), isAvailable(true) {}

ParkingSlot::ParkingSlot(int id, int z) : slotId(id), zoneId(z), isAvailable(true) {}

int ParkingSlot::getSlotId() const {
    return slotId;
}

int ParkingSlot::getZoneId() const {
    return zoneId;
}

void ParkingSlot::allocate() {
    isAvailable = false;
}
