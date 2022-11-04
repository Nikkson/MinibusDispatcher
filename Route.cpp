//
// Created by Nikkson.
//

#include <iostream>
#include "Route.h"

using namespace std;

int Route::getId() const {
    return id;
}

void Route::setId(int id) {
    Route::id = id;
}

double Route::getLength() const {
    return length;
}

void Route::setLength(double length) {
    Route::length = length;
}

const string &Route::getMainPoints() const {
    return mainPoints;
}

void Route::setMainPoints(const string &mainPoints) {
    Route::mainPoints = mainPoints;
}

int Route::getTours() const {
    return tours;
}

void Route::setTours(int tours) {
    Route::tours = tours;
}

Route::Route(int id, double length, string mainPoints, int tours) {
    setId(id);
    setLength(length);
    setMainPoints(mainPoints);
    setTours(tours);
}

Route::Route() = default;

void Route::printInfo() {
    cout<<"Route ID: "<<getId()<<endl;
    cout<<"Length: "<<getLength()<<"km"<<endl;
    cout<<"Main points: "<<getMainPoints()<<endl;
    cout<<"Number of tours: "<<getTours()<<endl;
}