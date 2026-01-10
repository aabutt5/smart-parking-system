#include "ParkingSlot.h"

ParkingSlot::ParkingSlot(int id, int zone) 
    : slotId(id), zoneId(zone), isAvailable(true) {}

int ParkingSlot::getSlotId() const { return slotId; }
int ParkingSlot::getZoneId() const { return zoneId; }
bool ParkingSlot::getAvailability() const { return isAvailable; }

bool ParkingSlot::allocate() {
    if (isAvailable) {
        isAvailable = false;
        return true;
    }
    return false;
}

bool ParkingSlot::release() {
    if (!isAvailable) {
        isAvailable = true;
        return true;
    }
    return false;
}