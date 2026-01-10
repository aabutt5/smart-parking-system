#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle {
public:
    int vehicleID; // [cite: 124]
    int preferredZone; // [cite: 125]

    Vehicle() : vehicleID(-1), preferredZone(-1) {}
    Vehicle(int id, int zone) : vehicleID(id), preferredZone(zone) {}
};
#endif