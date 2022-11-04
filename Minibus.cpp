//
// Created by Nikkson.
//

#include <ctime>
#include "Minibus.h"

int Minibus::getId() const {
    return id;
}

void Minibus::setId(int id) {
    Minibus::id = id;
}

const string &Minibus::getMake() const {
    return make;
}

void Minibus::setMake(const string &make) {
    Minibus::make = make;
}

const string &Minibus::getModel() const {
    return model;
}

void Minibus::setModel(const string &model) {
    Minibus::model = model;
}

int Minibus::getProductionYear() {
    return productionYear;
}

void Minibus::setProductionYear(int productionYear) {
    Minibus::productionYear = productionYear;
}

int Minibus::getAge() const {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentYear = 1900+ltm->tm_year;
    return currentYear - productionYear;
}

int Minibus::getNumOfPassengerSeats() const {
    return numOfPassengerSeats;
}

void Minibus::setNumOfPassengerSeats(int numOfPassengerSeats) {
    Minibus::numOfPassengerSeats = numOfPassengerSeats;
}

double Minibus::getMaxLoad() const {
    return maxLoad;
}

void Minibus::setMaxLoad(double maxLoad) {
    Minibus::maxLoad = maxLoad;
}

double Minibus::getFuelConsumption() const {
    return fuelConsumption;
}

void Minibus::setFuelConsumption(double fuelConsumption) {
    Minibus::fuelConsumption = fuelConsumption;
}

int Minibus::getRouteId() const {
    return routeID;
}

void Minibus::setRouteId(int routeId) {
    routeID = routeId;
}

Minibus::Minibus(int id, string make, string model, int productionYear, int numOfPassengerSeats, double maxLoad, double fuelConsumption, int routeId)
{
    setId(id);
    setMake(make);
    setModel(model);
    setProductionYear(productionYear);
    setNumOfPassengerSeats(numOfPassengerSeats);
    setMaxLoad(maxLoad);
    setFuelConsumption(fuelConsumption);
    setRouteId(routeId);
}

Minibus::Minibus() = default;

void Minibus::printInfo() {
    cout<<"ID: "<< this->id<<endl;
    cout<<"Make: "<< this->make<<endl;
    cout<<"Model: "<< this->model<<endl;
    cout<<"Age: "<<getAge()<<endl;
    cout<<"Passenger seats: "<<this->numOfPassengerSeats<<endl;
    cout<<"Max load: "<<this->maxLoad<<endl;
    cout<<"Fuel consumption: "<<this->fuelConsumption<<"l/100km"<<endl;
    cout<<"Route: "<< this->routeID<<endl;
}
