//
// Created by Nikkson.
//

#ifndef COURSEPROJECT_FILEREADERWRITER_H
#define COURSEPROJECT_FILEREADERWRITER_H

#include "Minibus.h"
#include "Route.h"
#include <vector>
#include <string>

using namespace std;

class FileReaderWriter {
private:
    string minibusFile = "minibuses.txt";
    string routeFile = "routes.txt";
    string bufferFile = "buffer.txt";
public:
    void listMinibuses();
    void listRoutes();
    void appendToFile(Minibus minibus);
    void appendToFile(Route route);
    void removeMinibusFromFile(int id);
    void removeRouteFromFile(int id);
    void replaceInFile(Minibus minibus, int id);
    void replaceInFile(Route route, int id);
    vector<int> loadUsedMinibusIDs();
    vector<int> loadUsedRouteIDs();
    bool isAssignedRouteID(int id);
    void updateMinibusesRouteID(int oldRouteID, int newRouteID);
    Minibus getMinibusById(int id);
    Route getRouteById(int id);
};


#endif //COURSEPROJECT_FILEREADERWRITER_H
