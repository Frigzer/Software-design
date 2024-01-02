#include "reservation.h"
#include "occupancyRegistry.h"
#include <iostream>
#include <vector>
#define numberOfRooms 5
using namespace std;

vector<bool*> occupancy;

bool day1[numberOfRooms] = {1,0,1,0,1,};
bool day2[numberOfRooms] = {1,1,0,1,1,};
bool day3[numberOfRooms] = {1,0,1,0,0,};


void makeReservation()
{
     int numberOfGuests;
    cout << "How many guests will be staying with us: ";
    cin >> numberOfGuests;
    cout << endl;

    bool avaiableRooms[numberOfRooms];
    occupancy.push_back(day1);
    occupancy.push_back(day2);
    occupancy.push_back(day3);
    int checkIn, checkOut;
    cout << "Select the check in and check out dates: ";
    //slm window for accesible dates
    cin >> checkIn;
    cout << endl;
    cin >> checkOut;
    
    for (int i = checkIn; i <= checkOut; i++)
    {
        for (int j = 0; j < numberOfRooms; j++)
        {
            if (i == checkIn)
            {
                avaiableRooms[j] = occupancy[i][j];
            }
            else
            {
                if (occupancy[i][j] == 0)
                {
                    avaiableRooms[j] = 0;
                }
            }
        }
    }
    int avaiableGuests;
    for (int i = 0; i < numberOfRooms; i++)
    {
        if (avaiableRooms[i] == 1)
        {
            avaiableGuests += 2;
            //avaiableGuests += rooms[i].ocuupants;
        }
    }
    while(avaiableGuests<numberOfGuests)
    {
    cout << "Not enough rooms are avaiable at that time please select diffrent check in and check out dates: ";
    //slm window for accesible dates
    cin >> checkIn;
    cout << endl;
    cin >> checkOut;
    
    for (int i = checkIn; i <= checkOut; i++)
    {
        for (int j = 0; j < numberOfRooms; j++)
        {
            if (i == checkIn)
            {
                avaiableRooms[j] = occupancy[i][j];
            }
            else
            {
                if (occupancy[i][j] == 0)
                {
                    avaiableRooms[j] = 0;
                }
            }
        }
    }
    for (int i = 0; i < numberOfRooms; i++)
    {
        if (avaiableRooms[i] == 1)
        {
            avaiableGuests += 2;
            //avaiableGuests += rooms[i].ocuupants;
        }
    }
    }
}