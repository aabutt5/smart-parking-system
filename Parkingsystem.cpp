#ifndef PARKINGSYSTEM_H
#define PARKINGSYSTEM_H

#include "Zone.h"
#include "AllocationEngine.h"
#include "RollbackManager.h"

class ParkingSystem {
private:
    Zone* zones;
    int zoneCount;
    int totalSlots;
    int totalOccupied;
    double totalDuration;
    int completedRequests;
    RollbackManager rollback;
    AllocationEngine engine;

public:
    ParkingSystem(int count);
    ~ParkingSystem();
    void processRequest(ParkingRequest& req);
    void performRollback(int k);
    void showAnalytics(); // Required for Analytics
};

#endif
