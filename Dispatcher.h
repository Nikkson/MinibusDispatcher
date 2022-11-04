//
// Created by Nikkson.
//

#ifndef COURSEPROJECT_DISPATCHER_H
#define COURSEPROJECT_DISPATCHER_H

#include <iostream>
#include <vector>
#include "FileReaderWriter.h"
#include "Minibus.h"
#include "Route.h"

using namespace std;

class Dispatcher {
private:
    FileReaderWriter frw;
    vector<int> usedMinibusIDs;
    vector<int> usedRouteIDs;
    Minibus currentMinibus;
    Route currentRoute;
public:
    Dispatcher();
    void listAllMinibuses();
    void listAllRoutes();
    void addMinibus();
    void addRoute();
    void removeUsedMinibusID(int id);
    void removeUsedRouteID(int id);
    void removeMinibus();
    void removeRoute();
    void editMinibus();
    void editRoute();
    void getMinibusFuelInfo();
};


#endif //COURSEPROJECT_DISPATCHER_H
