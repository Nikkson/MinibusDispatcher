//
// Created by Nikkson.
//

#include <string>
#include "Dispatcher.h"

Dispatcher::Dispatcher() {
    usedMinibusIDs=frw.loadUsedMinibusIDs();
    usedRouteIDs=frw.loadUsedRouteIDs();
}

void Dispatcher::addMinibus() {
    int id, productionYear, numOfPassengerSeats, routeId;
    double maxLoad, fuelConsumption;
    string make, model;
    bool idTaken = false;
    while (true) {
        cout<<"Enter new minibus ID: ";
        cin>>id;
        idTaken = false;
        for (int i : usedMinibusIDs) {
            if (id==i) {
                cout<<"This ID is already taken!"<<endl;
                idTaken = true;
                break;
            }
        }
        if (idTaken) continue;
        if (id<=0) {
            cout<<"ID cannot be negative!"<<endl;
            continue;
        }
        break;
    }
    while (true) {
        cout<<"Enter new minibus make: ";
        cin>>make;
        if (make.empty()) {
            cout<<"Make field cannot be empty!"<<endl;
            continue;
        } else break;
    }
    while (true) {
        cout<<"Enter new minibus model: ";
        cin>>model;
        if (model.empty()) {
            cout<<"Model field cannot be empty!"<<endl;
            continue;
        } else break;
    }
    while (true) {
        cout<<"Enter new minibus production year: ";
        cin>>productionYear;
        if (productionYear<=0) {
            cout<<"Invalid year!"<<endl;
            continue;
        } else break;
    }
    while (true) {
        cout<<"Enter number of passenger seats: ";
        cin>>numOfPassengerSeats;
        if (numOfPassengerSeats<=0) {
            cout<<"Invalid number!"<<endl;
            continue;
        } else break;
    }
    while (true) {
        cout<<"Enter new minibus max load value: ";
        cin>>maxLoad;
        if (maxLoad<=0) {
            cout<<"Invalid number!"<<endl;
            continue;
        } else break;
    }
    while (true) {
        cout<<"Enter new minibus fuel consumption (l/100km): ";
        cin>>fuelConsumption;
        if (fuelConsumption<=0) {
            cout<<"Invalid number!"<<endl;
            continue;
        } else break;
    }
    while (true) {
        cout<<"Enter route ID for the new minibus: ";
        cin>>routeId;
        if (routeId<=0) {
            cout<<"ID cannot be negative!"<<endl;
            continue;
        }
        bool validRoute = false;
        for (int i : usedRouteIDs) {
            if (i==routeId) {
                validRoute = true;
                break;
            }
        }
        if (!validRoute) {
            cout<<"There is no route with this ID!"<<endl;
            continue;
        } else break;
    }
    Minibus minibus(id,make,model,productionYear,numOfPassengerSeats,maxLoad,fuelConsumption,routeId);
    frw.appendToFile(minibus);
    usedMinibusIDs.push_back(id);
}

void Dispatcher::addRoute() {
    int id, tours;
    double length;
    string mainPoints;
    bool idTaken;
    while (true) {
        cout<<"Enter new route ID: ";
        cin>>id;
        if (id<=0) {
            cout<<"ID cannot be negative!"<<endl;
            continue;
        }
        idTaken = false;
        for (int i : usedRouteIDs) {
            if (i==id) {
                idTaken = true;
                break;
            }
        }
        if (idTaken) {
            cout<<"This ID is already taken!"<<endl;
            continue;
        } else break;

    }
    while (true) {
        cout<<"Enter length (km): ";
        cin>>length;
        if (length<=0) {
            cout<<"Invalid number!"<<endl;
            continue;
        } else break;
    }
    while (true) {
        cout<<"Enter main points: ";
        cin>>mainPoints;
        if (mainPoints.empty()) {
            cout<<"Main points field cannot be empty!"<<endl;
            continue;
        } else break;
    }
    while (true) {
        cout<<"Enter number of tours: ";
        cin>>tours;
        if (tours<=0) {
            cout<<"Invalid number!"<<endl;
            continue;
        } else break;
    }
    Route route(id,length,mainPoints,tours);
    frw.appendToFile(route);
    usedRouteIDs.push_back(id);
}

void Dispatcher::removeUsedMinibusID(int id) {
    for (int i=0; i<usedMinibusIDs.size(); i++) {
        if (usedMinibusIDs[i]==id) {
            usedMinibusIDs.erase(usedMinibusIDs.begin()+i);
        }
    }
}

void Dispatcher::removeUsedRouteID(int id) {
    for (int i=0; i<usedRouteIDs.size(); i++) {
        if (usedRouteIDs[i]==id) {
            usedRouteIDs.erase(usedRouteIDs.begin()+i);
        }
    }
}

void Dispatcher::removeMinibus() {
    int id;
    bool idAccepted = false;
    while (true) {
        cout<<"Enter minibus ID to be removed (0 for BACK): ";
        cin>>id;
        if (id == 0) {
            break;
        }
        for (int usedID : usedMinibusIDs) {
            if (id == usedID) {
                idAccepted = true;
                break;
            }
        }
        if (idAccepted) {
            removeUsedMinibusID(id);
            frw.removeMinibusFromFile(id);
            cout<<"Minibus removed successfully!"<<endl;
            break;
        } else {
            cout<<"There is no minibus with ID:"<<id<<"!"<<endl;
        }
    }
}

void Dispatcher::removeRoute() {
    int id;
    bool idAccepted = false;
    bool isAssignedRoute;
    while (true) {
        cout<<"Enter route ID to be removed (0 for BACK): ";
        cin>>id;
        if (id == 0) {
            break;
        }
        for (int usedID : usedRouteIDs) {
            if (id == usedID) {
                idAccepted = true;
                break;
            }
        }
        isAssignedRoute = frw.isAssignedRouteID(id);
        if (idAccepted) {
            if (!isAssignedRoute) {
                removeUsedRouteID(id);
                frw.removeRouteFromFile(id);
                cout<<"Route successfully removed!"<<endl;
                break;
            } else {
                cout<<"Route with ID:"<<id<<" cannot be deleted - it is assigned to one or more minibuses!"<<endl;
            }
        } else {
            cout<<"There is no route with ID:"<<id<<"!"<<endl;
        }
    }
}

void Dispatcher::editMinibus() {
    int id;
    bool idAccepted = false;
    while (true) {
        cout<<"Enter ID of the minibus that you wish to edit (0 for BACK): ";
        cin>>id;
        if (id==0) {
            return;
        }
        if (id<0) {
            cout<<"ID cannot be negative!"<<endl;
            continue;
        }
        for (int usedID : usedMinibusIDs) {
            if (id == usedID) {
                idAccepted = true;
                break;
            }
        }
        if (idAccepted) {
            currentMinibus=frw.getMinibusById(id);
            cout<<"Selected minibus:"<<endl;
            currentMinibus.printInfo();
            cout<<"---------------------------------"<<endl;
            break;
        } else {
            cout<<"There is no minibus with ID:"<<id<<"!"<<endl;
        }
    }
    int oldID = currentMinibus.getId();
    int choice;
    while (true) {
        cout<<"Edit:"<<endl
        <<"1.ID"<<endl
        <<"2.Make"<<endl
        <<"3.Model"<<endl
        <<"4.Production year"<<endl
        <<"5.Passenger seats"<<endl
        <<"6.Max load"<<endl
        <<"7.Fuel consumption"<<endl
        <<"8.Route ID"<<endl
        <<"9.SAVE"<<endl
        <<"0.BACK"<<endl
        <<">> ";
        cin>>choice;
        string newMake, newModel;

        switch (choice) {
            case 1:
                int newID;
                cout<<"Enter new minibus ID: ";
                cin>>newID;
                bool idTaken;
                idTaken = false;
                for (int i : usedMinibusIDs) {
                    if (newID==i) {
                        idTaken = true;
                        break;
                    }
                }
                if (idTaken) {
                    cout<<"This ID is already taken!"<<endl;
                } else if (newID<=0) {
                    cout<<"ID cannot be negative!"<<endl;
                } else {
                    currentMinibus.setId(newID);
                }
                break;
            case 2:
                cout<<"Enter new minibus make: ";
                cin>>newMake;
                currentMinibus.setMake(newMake);
                break;
            case 3:
                cout<<"Enter new minibus model: ";
                cin>>newModel;
                currentMinibus.setModel(newModel);
                break;
            case 4:
                int newProductionYear;
                cout<<"Enter new production year: ";
                cin>>newProductionYear;
                if (newProductionYear<=0) {
                    cout<<"Production year cannot be negative!"<<endl;
                } else {
                    currentMinibus.setProductionYear(newProductionYear);
                }
                break;
            case 5:
                int newNumOfPassengerSeats;
                cout<<"Enter new number of passenger seats: ";
                cin>>newNumOfPassengerSeats;
                if (newNumOfPassengerSeats<=0) {
                    cout<<"Number of passenger seats cannot be negative!"<<endl;
                } else {
                    currentMinibus.setNumOfPassengerSeats(newNumOfPassengerSeats);
                }
                break;
            case 6:
                double newMaxLoad;
                cout<<"Enter new value for max load: ";
                cin>>newMaxLoad;
                if (newMaxLoad<=0) {
                    cout<<"Max load cannot be negative!"<<endl;
                } else {
                    currentMinibus.setMaxLoad(newMaxLoad);
                }
                break;
            case 7:
                double newFuelConsumption;
                cout<<"Enter new value for fuel consumption (l/100km): ";
                cin>>newFuelConsumption;
                if (newFuelConsumption<=0) {
                    cout<<"Fuel consumption cannot be negative!"<<endl;
                } else {
                    currentMinibus.setFuelConsumption(newFuelConsumption);
                }
                break;
            case 8:
                int newRouteID;
                bool validRoute;
                validRoute = false;
                cout<<"Enter new route ID for this minibus: ";
                cin>>newRouteID;
                for (int usedID : usedRouteIDs) {
                    if (newRouteID==usedID) {
                        validRoute = true;
                        break;
                    }
                }
                if (!validRoute) {
                    cout<<"There is no route with this ID!"<<endl;
                } else if (newRouteID<=0) {
                    cout<<"Route cannot be negative!"<<endl;
                } else {
                    currentMinibus.setRouteId(newRouteID);
                }
                break;
            case 9:
                frw.replaceInFile(currentMinibus,oldID);
                if (currentMinibus.getId()!=oldID) {
                    for (int i=0; i<usedMinibusIDs.size(); i++) {
                        if (usedMinibusIDs[i]==oldID) {
                            usedMinibusIDs[i]=currentMinibus.getId();
                        }
                    }
                }
                return;
                break;
            case 0:
                return;
            default:
                cout<<"No such option!"<<endl;
        }
    }
}

void Dispatcher::editRoute() {
    int id;
    bool idAccepted = false;
    while (true) {
        cout<<"Enter the ID of the route you wish to edit (0 for BACK): ";
        cin>>id;
        if (id==0) {
            return;
        }
        if (id<0) {
            cout<<"ID cannot be negative!"<<endl;
            continue;
        }
        for (int usedID : usedRouteIDs) {
            if (id==usedID) {
                idAccepted = true;
                break;
            }
        }
        if (idAccepted) {
            currentRoute=frw.getRouteById(id);
            cout<<"Selected route:"<<endl;
            currentRoute.printInfo();
            cout<<"---------------------------------"<<endl;
            break;
        } else {
            cout<<"There is no route with ID:"<<id<<"!"<<endl;
        }
    }
    int oldID=currentRoute.getId();
    int choice;
    while (true) {
        cout<<"Edit:"<<endl
        <<"1.ID"<<endl
        <<"2.Length"<<endl
        <<"3.Main points"<<endl
        <<"4.Tours"<<endl
        <<"5.SAVE"<<endl
        <<"0.BACK"<<endl
        <<">>";
        cin>>choice;
        string newMainPoints;
        switch (choice) {
            case 1:
                int newID;
                cout<<"Enter new route ID: ";
                cin>>newID;
                bool idTaken;
                idTaken = false;
                for (int i : usedRouteIDs) {
                    if (newID==i) {
                        idTaken = true;
                        break;
                    }
                }
                if (idTaken) {
                    cout<<"This ID is already taken!"<<endl;
                } else if (newID<=0) {
                    cout<<"ID cannot be negative!"<<endl;
                } else {
                    currentRoute.setId(newID);
                }
                break;
            case 2:
                double newLength;
                cout<<"Enter new route length: ";
                cin>>newLength;
                if (newLength<=0) {
                    cout<<"Route length cannot be negative!"<<endl;
                } else {
                    currentRoute.setLength(newLength);
                }
                break;
            case 3:
                cout<<"Enter new route main points: ";
                cin>>newMainPoints;
                currentRoute.setMainPoints(newMainPoints);
                break;
            case 4:
                int newTours;
                cout<<"Enter new number of tours for this route: ";
                cin>>newTours;
                if (newTours<=0) {
                    cout<<"Number of tours cannot be negative!"<<endl;
                } else {
                    currentRoute.setTours(newTours);
                }
                break;
            case 5:
                frw.replaceInFile(currentRoute, oldID);
                if (currentRoute.getId()!=oldID) {
                    frw.updateMinibusesRouteID(oldID, currentRoute.getId());
                    for (int i=0; i<usedRouteIDs.size(); i++) {
                        if (usedRouteIDs[i]==oldID) {
                            usedRouteIDs[i]=currentRoute.getId();
                        }
                    }
                }
                cout<<"Saved!"<<endl;
                return;
                break;
            case 0:
                return;
            default:
                cout<<"No such option!"<<endl;
        }
    }
}

void Dispatcher::getMinibusFuelInfo() {
    double fuel;
    int minibusID;
    bool idAccepted = false;
    while (true) {
        cout<<"Enter minibus ID to check fuel needed (0 for BACK): ";
        cin>>minibusID;
        if (minibusID==0) {
            return;
        } else if (minibusID<0) {
            cout<<"ID cannot be negative!"<<endl;
        } else {
            for (int usedMinibusID : usedMinibusIDs) {
                if (usedMinibusID==minibusID) {
                    idAccepted = true;
                    break;
                }
            }
        }
        if (!idAccepted) {
            cout<<"There is no bus with id:"<<minibusID<<"!"<<endl;
            continue;
        } else {
            bool validRouteID = false;
            currentMinibus=frw.getMinibusById(minibusID);
            for (int usedRouteID : usedRouteIDs) {
                if (currentMinibus.getRouteId()==usedRouteID) {
                    validRouteID = true;
                    break;
                }
            }
            if (!validRouteID) {
                cout<<"Critical error occurred! Minibus is assigned an unknown route ID!"<<endl;
                return;
            } else {
                currentRoute=frw.getRouteById(currentMinibus.getRouteId());
            }
        }
        fuel = (currentMinibus.getFuelConsumption()/100)*currentRoute.getLength()*currentRoute.getTours();
        cout<<"Minibus with ID:"<<currentMinibus.getId()<<" requires "<<fuel<<"l of fuel for its currently assigned route."<<endl;
        break;
    }
}

void Dispatcher::listAllMinibuses() {
    frw.listMinibuses();
}

void Dispatcher::listAllRoutes() {
    frw.listRoutes();
}