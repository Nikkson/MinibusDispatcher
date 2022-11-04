//
// Created by Nikkson.
//

#include "FileReaderWriter.h"
#include <fstream>

using namespace std;

void FileReaderWriter::listMinibuses() {
    ifstream infile(minibusFile, ios::in);
    Minibus minibus;
    while (infile>>minibus) {
        minibus.printInfo();
        cout<<"---------------------------------"<<endl;
    }
    infile.close();
}

void FileReaderWriter::listRoutes() {
    ifstream infile(routeFile, ios::in);
    Route route;
    while (infile>>route) {
        route.printInfo();
        cout<<"---------------------------------"<<endl;
    }
    infile.close();
}

void FileReaderWriter::appendToFile(Minibus minibus) {
    ofstream outfile(minibusFile, ios::app);
    outfile<<minibus;
    cout<<"Minibus added successfully!"<<endl;
    outfile.close();
}

void FileReaderWriter::appendToFile(Route route) {
    ofstream outfile(routeFile, ios::app);
    outfile<<route;
    cout<<"Route added successfully!"<<endl;
    outfile.close();
}
void FileReaderWriter::removeMinibusFromFile(int id) {
    ifstream infile(minibusFile, ios::in);
    ofstream outfile(bufferFile, ios::app);
    Minibus temp;
    bool removed = false;
    while (infile>>temp) {
        if (id!=temp.getId()) {
            outfile<<temp;
        } else {
            removed = true;
            continue;
        }
    }
    if (removed) {
        cout<<"Bus removed successfully!"<<endl;
    } else {
        cout<<"ID not found. Nothing to remove."<<endl;
    }
    infile.close();
    outfile.close();
    remove(minibusFile.c_str());
    rename(bufferFile.c_str(),minibusFile.c_str());
}

void FileReaderWriter::removeRouteFromFile(int id) {
    ifstream infile(routeFile, ios::in);
    ofstream outfile(bufferFile, ios::app);
    Route temp;
    bool removed = false;
    while (infile>>temp) {
        if (id!=temp.getId()) {
            outfile<<temp;
        }
        else {
            removed = true;
            continue;
        }
    }
    if (removed) {
        cout<<"Route removed successfully!"<<endl;
    } else {
        cout<<"ID not found. Nothing to remove."<<endl;
    }
    infile.close();
    outfile.close();
    remove(routeFile.c_str());
    rename(bufferFile.c_str(),routeFile.c_str());
}

void FileReaderWriter::replaceInFile(Minibus minibus, int id) {
    ifstream infile(minibusFile, ios::in);
    ofstream outfile(bufferFile, ios::app);
    Minibus temp;
    while (infile>>temp) {
        if (id!=temp.getId()) {
            outfile<<temp;
        } else {
            outfile<<minibus;
        }
    }
    infile.close();
    outfile.close();
    remove(minibusFile.c_str());
    rename(bufferFile.c_str(),minibusFile.c_str());
}

void FileReaderWriter::replaceInFile(Route route, int id) {
    ifstream infile(routeFile, ios::in);
    ofstream outfile(bufferFile, ios::app);
    Route temp;
    while (infile>>temp) {
        if (id!=temp.getId()) {
            outfile<<temp;
        } else {
            outfile<<route;
        }
    }
    infile.close();
    outfile.close();
    remove(routeFile.c_str());
    rename(bufferFile.c_str(),routeFile.c_str());
}

vector<int> FileReaderWriter::loadUsedMinibusIDs() {
    vector<int> usedIDs;
    ifstream infile(minibusFile, ios::in);
    Minibus minibus;
    while (infile>>minibus) {
        usedIDs.push_back(minibus.getId());
    }
    infile.close();
    return usedIDs;
}

vector<int> FileReaderWriter::loadUsedRouteIDs() {
    vector<int> usedIDs;
    ifstream infile(routeFile, ios::in);
    Route route;
    while (infile>>route) {
        usedIDs.push_back(route.getId());
    }
    infile.close();
    return usedIDs;
}

bool FileReaderWriter::isAssignedRouteID(int id) {
    Minibus minibus;
    ifstream infile(minibusFile, ios::in);
    while (infile>>minibus) {
        if (minibus.getRouteId()==id) {
            infile.close();
            return true;
        }
    }
    infile.close();
    return false;
}

void FileReaderWriter::updateMinibusesRouteID(int oldRouteID, int newRouteID) {
    ifstream infile(minibusFile, ios::in);
    ofstream outfile(bufferFile, ios::app);
    Minibus minibus;
    while (infile>>minibus) {
        if (minibus.getRouteId()==oldRouteID) {
            minibus.setRouteId(newRouteID);
            outfile<<minibus;
        } else {
            outfile<<minibus;
        }
    }
    infile.close();
    outfile.close();
    remove(minibusFile.c_str());
    rename(bufferFile.c_str(), minibusFile.c_str());
}

Minibus FileReaderWriter::getMinibusById(int id) {
    ifstream infile(minibusFile, ios::in);
    Minibus minibus;
    while (infile>>minibus) {
        if (id==minibus.getId()) {
            infile.close();
            return minibus;
        }
    }
    infile.close();
    minibus.setId(-1);
    return minibus;
}

Route FileReaderWriter::getRouteById(int id) {
    ifstream infile(routeFile, ios::in);
    Route route;
    while (infile>>route) {
        if (id==route.getId()) {
            infile.close();
            return route;
        }
    }
    infile.close();
    route.setId(-1);
    return route;
}