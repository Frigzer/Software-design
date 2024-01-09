#ifndef GETROOMS_H
#define GETROOMS_H
#include <iostream>
#include <vector>
using namespace std;


struct rooms {
	int roomNumber;
	int occupants;
	string roomClass;
	bool isForService;

	void getFromFile();
	void writeToFile();
	void modifyRooms();

};
bool compareRooms(const rooms*, const rooms*);

static vector<rooms*> Rooms;

#endif