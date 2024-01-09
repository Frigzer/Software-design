#include "getRooms.h"
#include "occupancyRegistry.h"
#include "reservation.h
#include "makeReservation.h
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>



int generateID(int roomNum, int checkIn)
{
	int ID;
	ID = (roomNum * 1000000) + (checkIn % 1000000);
	return ID;
}




vector<rooms*> getFreeRooms(int checkIn, int checkOut)
{
	rooms r;
	r.getFromFile();

	occupancy o;

	o.readFromFile();

	vector<rooms*> freeRooms;
	int index=0;
	for (int i = 0; i < OCCUPANCY.size(); i++)
	{
		if (OCCUPANCY[i]->date == checkIn)
		{
			index = i;
		}
	}

	for (int j = 0; j < OCCUPANCY[index]->roomNumber.size(); j++)
	{
		if (o.checkIfFree(checkIn, checkOut, { OCCUPANCY[index]->roomNumber[j] }))
		{
			for (int i = 0; i < Rooms.size(); i++)
			{
				if (Rooms[i]->roomNumber == OCCUPANCY[index]->roomNumber[j])
				{
					freeRooms.push_back(Rooms[i]);
				}
			}
		}
	}
	return freeRooms;
	
}

int guestsNumber(vector<rooms*> roomNumbers)
{
	int num=0;
	for (int i = 0; i < roomNumbers.size(); i++)
	{
				num += Rooms[i]->occupants;		
	}
	return num;
}

void allAccesibleDates(int checkIn, int checkOut, int numOfGuests)
{
	occupancy o;
	o.readFromFile();
	int index = 0;

	for (int i = 0; i < OCCUPANCY.size(); i++)
	{
		if (OCCUPANCY[i]->date == checkIn)
		{
			index = i;
		}
	}

	cout << index << " : index" << endl;

	int num = o.numOfDays(checkIn, checkOut);
	int index2 = num + index;

	for (int j = index - 7; j < index2 + 7; j++)
	{
		if (j >= 0 && j + num < OCCUPANCY.size())
		{
			if (guestsNumber(getFreeRooms(OCCUPANCY[j]->date, OCCUPANCY[j + num]->date)) >= numOfGuests)
			{
				cout << OCCUPANCY[j]->date << " - " << OCCUPANCY[j + num]->date << endl;
			}
		}
	}
}

void makeReservation()
{
	occupancy o;
	reservation newReservation;
	//generate id
	int numberOfGuests;
	cout << "How many guests will be staying with us: ";
	cin >> numberOfGuests;
	cout << endl;
	int checkIn, checkOut;
	cout << "Select the check in date: ";
	cin >> checkIn;
	cout << endl;
	cout << "Select the check out date: ";
	cin >> checkOut;
	cout << endl;
	int avaiableGuests = guestsNumber(getFreeRooms(checkIn, checkOut));


	while (avaiableGuests < numberOfGuests)
	{
		cout << "Not enough rooms are avaiable at that time please select diffrent check in and check out dates" << endl;
		cout << "Here is a list of dates a week before and a week after when we will have enough free rooms";
		allAccesibleDates(checkIn, checkOut, numberOfGuests);
		cout << "Select the check in date: ";
		cin >> checkIn;
		cout << endl;
		cout << "Select the check out date: ";
		cin >> checkOut;
		cout << endl;
		avaiableGuests = guestsNumber(getFreeRooms(checkIn, checkOut));
	}
	int selectedGuests = 0;
	rooms r1;

	r1.getFromFile();
	int ut1=0;

	newReservation.checkIn = checkIn;
	newReservation.checkOut = checkOut;
		cout << endl << "Here are all the avaiable rooms:" << endl;
		vector<rooms*> r = getFreeRooms(checkIn, checkOut);
		for (int i = 0; i < r.size(); i++)
		{
				cout << endl << "Room number " << r[i]->roomNumber << ":" << endl;
				cout << "Maximum number of guests in the room: " << r[i]->occupants << endl;
				cout << "Room's standard: ";
				if(r[i]->roomClass == "S")
						{
							cout << "Standard";
						}
				else if (r[i]->roomClass == "P")
						{
							cout << "Penthouse";
						}
				else if (r[i]->roomClass == "L")
						{
							cout << "Luxury";
						}
				cout << endl;
				int price = 100;
				//int price = predictPrices
				// tutaj dodaj predict price zeby pokazało cenę
				cout << "Price: " << price << endl;

		}
		while (selectedGuests < numberOfGuests)
		{
			bool flag=false;
			int num;
			cout << endl << "Number of guests to alocate: " << numberOfGuests - selectedGuests;
			cout << endl << "Type in the number of room that you want: ";
			cin >> num;
			cout << endl;
			for (int i = 0; i < r.size(); i++)
			{
				if (num == r[i]->roomNumber)
				{
					ut1 = num;
					newReservation.roomNumber.push_back(num);
					newReservation.price += 100;//tutaj tez zeby ta cena nie była zawsze taka sama
					flag = true;
					selectedGuests += r[i]->occupants;
					r.erase(r.begin() + i);

				}
			}
			if (flag == true)
			{
				cout << endl << "Added room number " << num <<endl;
			}
			else
			{
				cout << endl << "You mistyped the number or the room is already added" << endl;
			}
		}
		cout << endl <<  "Do you want a breakfest, (50PLN per person per day): Y/N ";
		char s1;

		bool f1 = false;
		while(f1 == false)
		{
			cout << endl;
			cin >> s1;
			if (s1 == 'Y' || s1 == 'y')
			{
				newReservation.isBreakfest = true;
				newReservation.price += (50 * numberOfGuests * o.numOfDays(checkIn, checkOut));
				f1 = true;
			}
			else if (s1 == 'N' || s1 == 'n')
			{
				newReservation.isBreakfest = false;
				f1 = true;
			}
			else
			{
				cout << "Please select Y for yes or N for no";
			}
		}
		cout << endl <<  "Do you want a dinner table: Y/N ";
		char s2;

		bool f2 = false;
		while (f2 == false)
		{
			cin >> s2;
			if (s2 == 'Y' || s2 == 'y')
			{
				newReservation.isDinner = true;

				f2 = true;
			}
			else if (s2 == 'N' || s2 == 'n')
			{
				newReservation.isDinner = false;
				f2 = true;
			}
			else
			{
				cout << "Please select Y for yes or N for no";
			}
		}
		cout << endl << "Do you want a free parking spot for every room: Y/N ";

		f2 = false;
		while (f2 == false)
		{
			cout << endl;
			cin >> s2;
			if (s2 == 'Y' || s2 == 'y')
			{
				newReservation.isParking = true;
				f2 = true;
			}
			else if (s2 == 'N' || s2 == 'n')
			{
				newReservation.isParking = false;
				f2 = true;
			}
			else
			{
				cout << "Please select Y for yes or N for no";
			}
		}
		int time = 0;
		cout << endl << "Would ypu like a wake up call? if so please specify an hour in military format(7:00 == 700): ";
		f2 = false;
		while (f2 == false)
		{
			cin >> time;
			if (time == 0)
			{
				newReservation.wakeUpService = false;

				f2 = true;
			}
			else 
			{
				newReservation.wakeUpService = time;
				f2 = true;
			}
		}
		cout << endl << "Reservation is saved, you will be able to pay with a money transfer or at the reception desk, see you soon!" <<  endl;
		newReservation.isCanceled = false;
		newReservation.isPaid = false;
		newReservation.discount = 0;
		reservation res;
		newReservation.ID = 0;
		cout << "\ngenerated ID\n";
		newReservation.ID = (generateID(ut1, checkIn));

		res.writeToFile(newReservation);
}

void editReservation()
{
	{
		occupancy o;
		reservation newReservation;
		cout << "Insert reservation ID: ";
		cin >> newReservation.ID;
		reservation* buffer = readOneFromFile(newReservation.ID);
		occupancy o;
		o.modifyRegistry(buffer->checkIn, buffer->checkOut, buffer->roomNumber, 0);
		
		cout << endl;

		//generate id
		int numberOfGuests;
		cout << "How many guests will be staying with us: ";
		cin >> numberOfGuests;
		cout << endl;
		int checkIn, checkOut;
		cout << "Select the check in date: ";
		cin >> checkIn;
		cout << endl;
		cout << "Select the check out date: ";
		cin >> checkOut;
		cout << endl;
		int avaiableGuests = guestsNumber(getFreeRooms(checkIn, checkOut));


		while (avaiableGuests < numberOfGuests)
		{
			cout << "Not enough rooms are avaiable at that time please select diffrent check in and check out dates" << endl;
			cout << "Here is a list of dates a week before and a week after when we will have enough free rooms";
			allAccesibleDates(checkIn, checkOut, numberOfGuests);
			cout << "Select the check in date: ";
			cin >> checkIn;
			cout << endl;
			cout << "Select the check out date: ";
			cin >> checkOut;
			cout << endl;
			avaiableGuests = guestsNumber(getFreeRooms(checkIn, checkOut));
		}
		int selectedGuests = 0;
		rooms r1;

		r1.getFromFile();
		int ut1 = 0;

		newReservation.checkIn = checkIn;
		newReservation.checkOut = checkOut;
		cout << endl << "Here are all the avaiable rooms:" << endl;
		vector<rooms*> r = getFreeRooms(checkIn, checkOut);
		for (int i = 0; i < r.size(); i++)
		{
			cout << endl << "Room number " << r[i]->roomNumber << ":" << endl;
			cout << "Maximum number of guests in the room: " << r[i]->occupants << endl;
			cout << "Room's standard: ";
			if (r[i]->roomClass == "S")
			{
				cout << "Standard";
			}
			else if (r[i]->roomClass == "P")
			{
				cout << "Penthouse";
			}
			else if (r[i]->roomClass == "L")
			{
				cout << "Luxury";
			}
			cout << endl;
			int price = 100;
			//int price = predictPrices
			// tutaj dodaj predict price zeby pokazało cenę
			cout << "Price: " << price << endl;

		}
		while (selectedGuests < numberOfGuests)
		{
			bool flag = false;
			int num;
			cout << endl << "Number of guests to alocate: " << numberOfGuests - selectedGuests;
			cout << endl << "Type in the number of room that you want: ";
			cin >> num;
			cout << endl;
			for (int i = 0; i < r.size(); i++)
			{
				if (num == r[i]->roomNumber)
				{
					ut1 = num;
					newReservation.roomNumber.push_back(num);
					newReservation.price += 100;//tutaj tez zeby ta cena nie była zawsze taka sama
					flag = true;
					selectedGuests += r[i]->occupants;
					r.erase(r.begin() + i);

				}
			}
			if (flag == true)
			{
				cout << endl << "Added room number " << num << endl;
			}
			else
			{
				cout << endl << "You mistyped the number or the room is already added" << endl;
			}
		}
		cout << endl << "Do you want a breakfest, (50PLN per person per day): Y/N ";
		char s1;

		bool f1 = false;
		while (f1 == false)
		{
			cout << endl;
			cin >> s1;
			if (s1 == 'Y' || s1 == 'y')
			{
				newReservation.isBreakfest = true;
				newReservation.price += (50 * numberOfGuests * o.numOfDays(checkIn, checkOut));
				f1 = true;
			}
			else if (s1 == 'N' || s1 == 'n')
			{
				newReservation.isBreakfest = false;
				f1 = true;
			}
			else
			{
				cout << "Please select Y for yes or N for no";
			}
		}
		cout << endl << "Do you want a dinner table: Y/N ";
		char s2;

		bool f2 = false;
		while (f2 == false)
		{
			cin >> s2;
			if (s2 == 'Y' || s2 == 'y')
			{
				newReservation.isDinner = true;

				f2 = true;
			}
			else if (s2 == 'N' || s2 == 'n')
			{
				newReservation.isDinner = false;
				f2 = true;
			}
			else
			{
				cout << "Please select Y for yes or N for no";
			}
		}
		cout << endl << "Do you want a free parking spot for every room: Y/N ";

		f2 = false;
		while (f2 == false)
		{
			cout << endl;
			cin >> s2;
			if (s2 == 'Y' || s2 == 'y')
			{
				newReservation.isParking = true;
				f2 = true;
			}
			else if (s2 == 'N' || s2 == 'n')
			{
				newReservation.isParking = false;
				f2 = true;
			}
			else
			{
				cout << "Please select Y for yes or N for no";
			}
		}
		int time = 0;
		cout << endl << "Would ypu like a wake up call? if so please specify an hour in military format(7:00 == 700): ";
		f2 = false;
		while (f2 == false)
		{
			cin >> time;
			if (time == 0)
			{
				newReservation.wakeUpService = false;

				f2 = true;
			}
			else
			{
				newReservation.wakeUpService = time;
				f2 = true;
			}
		}
		cout << endl << "Reservation is saved, you will be able to pay with a money transfer or at the reception desk, see you soon!" << endl;
		newReservation.isCanceled = false;
		newReservation.isPaid = false;
		newReservation.discount = 0;
		reservation res;
		newReservation.ID = 0;
		cout << "\ngenerated ID\n";

		res.Edit(newReservation);
	}
}


