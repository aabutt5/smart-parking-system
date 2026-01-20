#include <iostream>
#include "ParkingSystem.h"

// Helper function to handle the Menu GUI
void showMenu() {
    std::cout << "\n====================================" << std::endl;
    std::cout << "   SMART PARKING MANAGEMENT GUI    " << std::endl;
    std::cout << "====================================" << std::endl;
    std::cout << "1. Park Vehicle (Car, Bike, Jeep)" << std::endl;
    std::cout << "2. Checkout & Generate Receipt" << std::endl;
    std::cout << "3. View All Building Status" << std::endl;
    std::cout << "4. Show System Analytics" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Select an option: ";
}

int main() {
    // Initialize with 5 buildings as per your requirement
    ParkingSystem city(5); 
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;

        if (choice == 5) break;

        switch (choice) {
            case 1: {
                char id[20], type[10], deal[10];
                int preferredBuilding;
                
                std::cout << "Enter Vehicle ID: "; std::cin >> id;
                std::cout << "Type (Car/Bike/Jeep): "; std::cin >> type;
                std::cout << "Building Preference (1-5): "; std::cin >> preferredBuilding;
                std::cout << "Deal (None/Weekly/Monthly): "; std::cin >> deal;

                // Process request - Auto-redirects if building is full
                ParkingRequest req(id, preferredBuilding, type, deal);
                city.processRequest(req);
                break;
            }
            case 2: {
                char id[20];
                int hours;
                std::cout << "Enter Vehicle ID for checkout: "; std::cin >> id;
                std::cout << "Total stay duration (hours): "; std::cin >> hours;
                
                // Generates 20 PKR for Bike, 100 PKR for Car/Jeep
                city.generateReceipt(id, hours);
                break;
            }
            case 3:
                city.displayBuildingStatus(); // Shows which buildings are full
                break;
            case 4:
                city.showAnalytics();
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
    }
    return 0;
}