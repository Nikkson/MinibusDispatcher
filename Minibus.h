//
// Created by Nikkson.
//

#ifndef COURSEPROJECT_MINIBUS_H
#define COURSEPROJECT_MINIBUS_H

#include <iostream>
#include <string>
using namespace std;

class Minibus {
private:
    int id;
  string make;
  string model;
  int productionYear;
  int numOfPassengerSeats;
  double maxLoad;
  double fuelConsumption;
  int routeID;
public:
    Minibus();
    Minibus(int id, string make, string model, int productionYear, int numOfPassengerSeats, double maxLoad, double fuelConsumption, int routeId);
    int getId() const;
    void setId(int id);
    const string &getMake() const;
    void setMake(const string &make);
    const string &getModel() const;
    void setModel(const string &model);
    int getProductionYear();
    void setProductionYear(int productionYear);
    int getAge() const;
    int getNumOfPassengerSeats() const;
    void setNumOfPassengerSeats(int numOfPassengerSeats);
    double getMaxLoad() const;
    void setMaxLoad(double maxLoad);
    double getFuelConsumption() const;
    void setFuelConsumption(double fuelConsumption);
    int getRouteId() const;
    void setRouteId(int routeId);
    void printInfo();
    friend ostream& operator<<(ostream& os, const Minibus& minibus);
    friend istream& operator>>(istream &is, Minibus &minibus);
};


#endif //COURSEPROJECT_MINIBUS_H
