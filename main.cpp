#include <iostream>
#include <cstdlib>
#include <string>
#include "Minibus.h"
#include "Route.h"
#include "FileReaderWriter.h"
#include "Dispatcher.h"

#define DELIM '|'

using namespace std;

ostream& operator<<(ostream& os, const Minibus& minibus) {
    os<<minibus.id<<DELIM<<minibus.make<<DELIM<<minibus.model<<DELIM<<minibus.productionYear<<DELIM<<
    minibus.numOfPassengerSeats<<DELIM<<minibus.maxLoad<<DELIM<<minibus.fuelConsumption<<DELIM<<minibus.routeID<<DELIM;
    return os;
}

istream& operator>>(istream &is, Minibus &minibus) {
    string str;
    int intVal;
    double doubleVal;

    getline(is,str, DELIM);
    intVal=atoi(str.c_str());
    minibus.setId(intVal);
    getline(is,str,DELIM);
    minibus.setMake(str);
    getline(is,str,DELIM);
    minibus.setModel(str);
    getline(is,str,DELIM);
    intVal=atoi(str.c_str());
    minibus.setProductionYear(intVal);
    getline(is,str,DELIM);
    intVal=atoi(str.c_str());
    minibus.setNumOfPassengerSeats(intVal);
    getline(is,str,DELIM);
    doubleVal=atof(str.c_str());
    minibus.setMaxLoad(doubleVal);
    getline(is,str,DELIM);
    doubleVal=atof(str.c_str());
    minibus.setFuelConsumption(doubleVal);
    getline(is,str,DELIM);
    intVal=atoi(str.c_str());
    minibus.setRouteId(intVal);

    return is;
}

ostream& operator<<(ostream& os, const Route& route) {
    os<<route.id<<DELIM<<route.length<<DELIM<<route.mainPoints<<DELIM<<route.tours<<DELIM;
    return os;
}

istream& operator>>(istream &is, Route &route) {
    string str;
    int intVal;
    double doubleVal;

    getline(is,str,DELIM);
    intVal=atoi(str.c_str());
    route.setId(intVal);
    getline(is,str,DELIM);
    doubleVal=atof(str.c_str());
    route.setLength(doubleVal);
    getline(is,str,DELIM);
    route.setMainPoints(str);
    getline(is,str,DELIM);
    intVal=atoi(str.c_str());
    route.setTours(intVal);

    return is;
}

int main() {

    Dispatcher dispatcher;
    int choice;
    while (true) {
        cout<<"###-----MAIN MENU-----###"<<endl
        <<"1.List all minibuses"<<endl
        <<"2.List all routes"<<endl
        <<"3.Add minibus"<<endl
        <<"4.Add route"<<endl
        <<"5.Check minibus fuel requirement"<<endl
        <<"6.Edit minibus"<<endl
        <<"7.Edit route"<<endl
        <<"8.Remove minibus"<<endl
        <<"9.Remove route"<<endl
        <<"0.Exit program"<<endl
        <<">>";
        cin>>choice;

        switch (choice) {
            case 1:
                dispatcher.listAllMinibuses();
                break;
            case 2:
                dispatcher.listAllRoutes();
                break;
            case 3:
                dispatcher.addMinibus();
                break;
            case 4:
                dispatcher.addRoute();
                break;
            case 5:
                dispatcher.getMinibusFuelInfo();
                break;
            case 6:
                dispatcher.editMinibus();
                break;
            case 7:
                dispatcher.editRoute();
                break;
            case 8:
                dispatcher.removeMinibus();
                break;
            case 9:
                dispatcher.removeRoute();
                break;
            case 0:
                cout<<"Exiting program!"<<endl;
                exit(0);
            default:
                cout<<"No such option!"<<endl;
        }
    }
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
