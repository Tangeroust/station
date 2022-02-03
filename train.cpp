#include "train.h"

char Train::designation = 'A';
RailwayStation Train::placeArrival = RailwayStation();

Train::Train() : symbol(designation++) {

    while(true)
    {
        cout << "\nHow many seconds will train \"" << symbol << "\" be on the way? ";
        cin >> travelTime;

        if(cin.good()) break;

        cin.ignore(10, '\n');
        cin.clear();

        cout << "\nError: wrong time. Try again!";
    }
}

Train::~Train(){
    road->join();
    delete road;
}

void Train::traffic(){

    std::this_thread::sleep_for(std::chrono::seconds(travelTime));

    if(placeArrival.stationBusy())
        cout << "\nTrain \"" << symbol << "\" waiting for a free seat at the station.\n";
    else placeArrival.unblockStation();


    placeArrival.blockStation();
        cout << "\n\nTrain \"" << symbol << "\" arrived at the station.";
        departure();
    placeArrival.unblockStation();
}

void Train::start() {
    road = new thread(&Train::traffic, this);
}

void Train::departure() {

    string answer;

    while(true)
    {
        cout << "\nThe train is waiting for the departure command: ";
        cin >> answer;

        if(answer == "depart") break;

        cout << "\nError: incorrect command.";
    }
    cout << "Train \"" << symbol << "\" departs from the station.";
}