#include "TicketManager.hpp"
#include <iostream>

TicketManager::TicketManager(string eventName)
    : eventName(eventName), vipCapacity(5), regularCapacity(10), ticketCount(0), 
      currentVIPTickets(0), currentRegularTickets(0) {

    for (int i = 0; i < VENUE_CAPACITY; i++) {
        tickets[i] = nullptr;
    }
}

TicketManager::TicketManager(string eventName, int vipCapacity, int regularCapacity)
    : eventName(eventName), vipCapacity(vipCapacity), regularCapacity(regularCapacity), 
      ticketCount(0), currentVIPTickets(0), currentRegularTickets(0) {

    for (int i = 0; i < VENUE_CAPACITY; i++) {
        tickets[i] = nullptr;
    }

    int totalCapacity = vipCapacity + regularCapacity;
    if (totalCapacity > VENUE_CAPACITY) {
        cout << "The total capacity you construct is " << totalCapacity 
             << ", meanwhile the venue capacity is 15" << endl;
    }
}

TicketManager::~TicketManager() {
    for (int i = 0; i < ticketCount; i++) {
        delete tickets[i];
        tickets[i] = nullptr;
    }
}

string TicketManager::getEventName() const {
    return eventName;
}

void TicketManager::buyTicket(const string &ownerName, bool isVIP) {
    if (ticketCount >= VENUE_CAPACITY) {
        cout << "Error: All tickets are sold out!" << endl;
        return;
    }

    if (isVIP) {
        if (currentVIPTickets >= vipCapacity) {
            cout << "Error: No VIP tickets left!" << endl;
            return;
        }

        currentVIPTickets++;
        string ticketID = "V" + to_string(currentVIPTickets);

        tickets[ticketCount] = new VIPTicket(ticketID, ownerName);
        ticketCount++;
        
        cout << "Success: " << ownerName << " bought a VIP ticket! Ticket ID: " << ticketID << endl;
    } else {
        if (currentRegularTickets >= regularCapacity) {
            cout << "Error: No Regular tickets left!" << endl;
            return;
        }

        currentRegularTickets++;
        string ticketID = "R" + to_string(currentRegularTickets);

        tickets[ticketCount] = new RegularTicket(ticketID, ownerName);
        ticketCount++;
        
        cout << "Success: " << ownerName << " bought a Regular ticket! Ticket ID: " << ticketID << endl;
    }
}

void TicketManager::checkTicket(const string &ticketID) const {
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i]->getTicketID() == ticketID) {
            tickets[i]->printTicket();
            return;
        }
    }
    
    cout << "Ticket ID is invalid!" << endl;
}

void TicketManager::listAudience() const {
    if (ticketCount == 0) {
        cout << "No audience yet!" << endl;
        return;
    }
    
    for (int i = 0; i < ticketCount; i++) {
        cout << (i + 1) << ". ";
        tickets[i]->printTicket();
    }
}

int TicketManager::calculateRevenue() const {
    int totalRevenue = 0;
    
    for (int i = 0; i < ticketCount; i++) {
        if (tickets[i]->getType() == "VIP") {
            totalRevenue += 500;
        } else if (tickets[i]->getType() == "Regular") {
            totalRevenue += 275;
        }
    }
    
    return totalRevenue;
}