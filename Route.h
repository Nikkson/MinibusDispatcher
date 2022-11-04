//
// Created by Nikkson.
//

#ifndef COURSEPROJECT_ROUTE_H
#define COURSEPROJECT_ROUTE_H

#include <string>

using namespace std;

class Route {
private:
    int id;
    double length;
    string mainPoints;
    int tours;
public:
    Route();
    Route(int id, double length, string mainPoints, int tours);
    int getId() const;
    void setId(int id);
    double getLength() const;
    void setLength(double length);
    const string &getMainPoints() const;
    void setMainPoints(const string &mainPoints);
    int getTours() const;
    void setTours(int tours);
    void printInfo();
    friend ostream& operator<<(ostream& os, const Route& route);
    friend istream& operator>>(istream &is, Route &route);
};


#endif //COURSEPROJECT_ROUTE_H
