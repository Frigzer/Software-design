#ifndef MAKERESERVATION_H
#define MAKERESERVATION_H
#include <vector>
#include <string>

#include "getRooms.h"
#include "predictPrices.h"

using namespace std;
int generateID(int roomNum, int checkIn);
vector<rooms*> getFreeRooms(int checkIn, int checkOut);
int guestsNumber(vector<rooms*> roomNumbers);
void allAccesibleDates(int checkIn, int checkOut, int numOfGuests);
void makeReservation();
void editReservation();

#endif