#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

enum SlotStatus { AVAILABLE, OCCUPIED, RESERVED };

class ParkingSlot {
public:
    int slotID;
    int zoneID;
    SlotStatus status;

    ParkingSlot() : slotID(-1), zoneID(-1), status(AVAILABLE) {} // [cite: 121]
    ParkingSlot(int id, int z) : slotID(id), zoneID(z), status(AVAILABLE) {}
};
#endif