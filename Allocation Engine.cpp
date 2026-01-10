#include "AllocationEngine.h"

ParkingSlot* AllocationEngine::allocate(Zone* zones, int zoneCount, int preferredZoneID) {
    // 1. Same-zone preference [cite: 146]
    for (int i = 0; i < zoneCount; i++) {
        if (zones[i].zoneID == preferredZoneID) {
            for (int j = 0; j < zones[i].areaCount; j++) {
                for (int k = 0; k < zones[i].areas[j].slotCount; k++) {
                    if (zones[i].areas[j].slots[k].status == AVAILABLE) {
                        return &zones[i].areas[j].slots[k];
                    }
                }
            }
        }
    }
    // 2. Cross-zone allocation (if preferred is full) [cite: 149, 150]
    for (int i = 0; i < zoneCount; i++) {
        for (int j = 0; j < zones[i].areaCount; j++) {
            for (int k = 0; k < zones[i].areas[j].slotCount; k++) {
                if (zones[i].areas[j].slots[k].status == AVAILABLE) {
                    // System would record an extra cost/penalty here [cite: 151]
                    return &zones[i].areas[j].slots[k];
                }
            }
        }
    }
    return nullptr;
}