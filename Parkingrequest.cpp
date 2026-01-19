#include "ParkingRequest.h"

// Ali: Standard constructor
ParkingRequest::ParkingRequest() : vehicleID(""), requestedZone(""), currentState(REQUESTED) {}

// Ali: Enforce the strict lifecycle (Requirement 4) [cite: 42, 53]
bool ParkingRequest::transitionTo(ParkingRequest::State nextState) {
    if (this->currentState == ParkingRequest::REQUESTED) {
        if (nextState == ParkingRequest::ALLOCATED || nextState == ParkingRequest::CANCELLED) {
            this->currentState = nextState;
            return true;
        }
    } 
    else if (this->currentState == ParkingRequest::ALLOCATED) {
        if (nextState == ParkingRequest::OCCUPIED || nextState == ParkingRequest::CANCELLED) {
            this->currentState = nextState;
            return true;
        }
    } 
    else if (this->currentState == ParkingRequest::OCCUPIED) {
        if (nextState == ParkingRequest::RELEASED) {
            this->currentState = nextState;
            return true;
        }
    }
    return false; // Prevents invalid transitions like REQUESTED -> RELEASED 
}