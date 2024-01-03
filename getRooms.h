#ifndef GETROOMS_H
#define GETROOMS_H
#include <vector>
using namespace std;

vector<rooms> Rooms;

struct rooms {
    int roomNumber;
    int occupants;
    char roomClass;
    bool isForService;

	void getFromFile();
    void modifyRooms();
};

#endif
