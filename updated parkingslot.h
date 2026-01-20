#ifndef PARKINGSLOT_H
#define PARKINGSLOT_H

// These must be defined before the class [cite: 134-140]
enum SlotStatus { AVAILABLE, ALLOCATED, OCCUPIED, RELEASED, CANCELLED };

class ParkingSlot {
public:
    int slotId;        // [cite: 119]
    int zoneId;        // [cite: 120]
    bool isAvailable;  // [cite: 121]

    ParkingSlot();
    ParkingSlot(int id, int z);

    // Declarations for the members the compiler says are missing
    int getSlotId() const;
    int getZoneId() const;
    bool getAvailability() const;
    void allocate();
    void release();
};

#endif