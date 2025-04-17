#include "SpacingGuildShip.hpp"
using namespace std;

float SpacingGuildShip::totalGuildTravel = 0;
int SpacingGuildShip::producedShips = 0;


SpacingGuildShip::SpacingGuildShip() : serialNum(producedShips + 1), maxPassengerCap(50), guildNavigatorCount(3){
    this->passengerCount = 0;
    this->spiceStock = 50;
    this->operatingGuildNavigator = 3;
    SpacingGuildShip::producedShips++;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : serialNum(producedShips + 1), maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount){
    this->passengerCount = 0;
    this->spiceStock = spiceStock;
    this->operatingGuildNavigator = guildNavigatorCount;
    SpacingGuildShip::producedShips++;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& spg) : serialNum(producedShips + 1), maxPassengerCap(spg.maxPassengerCap), guildNavigatorCount(spg.guildNavigatorCount){
    this->passengerCount = spg.passengerCount;
    this->spiceStock = spg.spiceStock;
    this->operatingGuildNavigator = spg.operatingGuildNavigator;
    SpacingGuildShip::producedShips++;
}

SpacingGuildShip::~SpacingGuildShip(){ 
}

int SpacingGuildShip::getShipSerialNum() const{
    return this->serialNum;
}

int SpacingGuildShip::getPassengerCount() const{
    return this->passengerCount;
}

void SpacingGuildShip::travel(float distance){
    if (this->operatingGuildNavigator > 0){
        SpacingGuildShip::totalGuildTravel += distance / (E * E * operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassengers){
    this->passengerCount += addedPassengers;
    if (this->passengerCount > this->maxPassengerCap){
        this->passengerCount = maxPassengerCap;
    }
}

void SpacingGuildShip::dropOff(int droppedPassengers){
    this->passengerCount -= droppedPassengers;
    if (this->passengerCount < 0){
        this->passengerCount = 0;
    }
}

void SpacingGuildShip::refreshNavigator(int n) {
    int m_spice = this->spiceStock / GUILD_NAVIGATOR_SPICE_DOSE;
    
    if (m_spice > n) {
        m_spice = n;
    }
    
    int m_refresh = this->guildNavigatorCount - this->operatingGuildNavigator;
    if (m_spice > m_refresh) {
        m_spice = m_refresh;
    }
    
    this->operatingGuildNavigator += m_spice;

    this->spiceStock -= (m_spice * GUILD_NAVIGATOR_SPICE_DOSE);
}

void SpacingGuildShip::transitToArrakis(int addedSpice){
    this->spiceStock += addedSpice;
}