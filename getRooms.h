#ifndef GETROOMS_H
#define GETROOMS_H
#include <vector>
using namespace std;

struct rooms {
    int roomNumber;
    int occupants;
    char roomClass;
    bool isForService;

    void getFromFile();
    void modifyRooms();
};

vector<rooms*> Rooms;

#endif