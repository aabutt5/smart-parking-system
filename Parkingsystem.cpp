#include "ParkingSystem.h"
#include <iostream>

// Ali: Constructor - Setting up the city zones
ParkingSystem::ParkingSystem(int count) : zoneCount(count), totalOccupied(0), completedRequests(0), totalDuration(0.0) {
    zones = new Zone[count]; 
    totalSlots = count * 20; // Example: assuming 20 slots per zone
}

// Ali: Processing the car parking request
void ParkingSystem::processRequest(ParkingRequest& req) {
    ParkingSlot* slot = engine.allocate(zones, zoneCount, req.getRequestedZone());
    
    if (slot) {
        // Save to Rollback Manager first (Abdullah's logic)
        rollback.pushAction(&req, slot, req.getState());
        
        // Transition state (Ali's State Machine)
        if (req.transitionTo(ParkingRequest::ALLOCATED)) {
            slot->setAvailable(false);
            totalOccupied++;
        }
    }
}

// Requirement 7: Analytics Implementation
void ParkingSystem::showAnalytics() {
    double utilization = (totalOccupied / (double)totalSlots) * 100.0;
    double avgDuration = (completedRequests > 0) ? (totalDuration / completedRequests) : 0;

    std::cout << "--- Smart Parking Analytics ---" << std::endl;
    std::cout << "City Utilization: " << utilization << "%" << std::endl;
    std::cout << "Average Stay: " << avgDuration << " mins" << std::endl;
}

void ParkingSystem::performRollback(int k) {
    rollback.rollbackK(k);
}

ParkingSystem::~ParkingSystem() {
    delete[] zones; // Cleanup custom array
<<<<<<< HEAD
}
=======
}
>>>>>>> 4e3bbd53271a4b781c66c402e09b4fb8057c680d
