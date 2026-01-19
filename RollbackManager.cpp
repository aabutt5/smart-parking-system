#include "RollbackManager.h"

// Ali: Custom Stack (No STL allowed) [cite: 79]
void RollbackManager::pushAction(ParkingRequest* r, ParkingSlot* s, ParkingRequest::State st) {
    RollbackNode* newNode = new RollbackNode;
    newNode->req = r;
    newNode->slot = s;
    newNode->oldState = st;
    newNode->next = top;
    top = newNode;
}

void RollbackManager::rollbackK(int k) {
    while (k > 0 && top != nullptr) {
        RollbackNode* temp = top;
        // Undo request state and slot availability [cite: 68-70]
        temp->req->setState(temp->oldState);
        if (temp->slot != nullptr) {
            temp->slot->setAvailable(true);
        }
        top = top->next;
        delete temp;
        k--;
    }
}