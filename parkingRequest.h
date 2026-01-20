#ifndef PARKINGREQUEST_H
#define PARKINGREQUEST_H
#include "ParkingSlot.h"

class ParkingRequest {
public:
    int vehicleID; // [cite: 129]
    int requestedZone; // [cite: 130]
    SlotStatus currentState; // [cite: 134]

    ParkingRequest();
    bool transitionTo(SlotStatus nextState); // Enforces state machine [cite: 143]
};
#endif