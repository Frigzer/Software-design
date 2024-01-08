#ifndef OCCUPANCYREGISTRY_H
#define OCCUPANCYREGISTRY_H
#include <vector>
using namespace std;

struct occupancy {
	vector<bool> isOccupied;
	vector<int> roomNumber;
	int date;
	void readFromFile();
	void writeToFile();
	void modifyRegistry(int, int, vector<int>, bool);
	bool checkIfFree(int, int, vector<int>);
};

static vector<occupancy*> OCCUPANCY;

#endif