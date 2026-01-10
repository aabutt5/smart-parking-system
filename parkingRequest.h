#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

// Define this OUTSIDE the class so the whole project can see it
enum SlotStatus { AVAILABLE, ALLOCATED, OCCUPIED, RELEASED, CANCELLED };

class ParkingSlot {
public:
    int slotId;
    int zoneId;
    bool isAvailable;

    ParkingSlot();
    ParkingSlot(int id, int z);

    // You MUST declare these here to fix the "no member" errors in your image
    int getSlotId() const;
    int getZoneId() const;
    bool getAvailability() const;
    void allocate();
    void release();
};
#endif
