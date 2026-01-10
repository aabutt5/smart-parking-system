#include "ParkingRequest.h"

ParkingRequest::ParkingRequest() : vehicleID(-1), requestedZone(-1), currentState(REQUESTED) {}

bool ParkingRequest::transitionTo(SlotStatus nextState) {
    // Logic to prevent invalid transitions [cite: 142]
    if (currentState == REQUESTED && (nextState == ALLOCATED || nextState == CANCELLED)) {
        currentState = nextState;
        return true;
    }
    if (currentState == ALLOCATED && (nextState == OCCUPIED || nextState == CANCELLED)) {
        currentState = nextState;
        return true;
    }
    if (currentState == OCCUPIED && nextState == RELEASED) {
        currentState = nextState;
        return true;
    }
    return false; // Blocks invalid changes [cite: 143]
}