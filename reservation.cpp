#include "reservation.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <string>

void reservation::writeToFile(reservation r)
{
	occupancy o;
	if (readOneFromFile(r.ID) == NULL)
	{

			fstream file;
			string text;
			text += "\n";
			text += to_string(r.ID);
			text += "\n";
			file.open("RESERVATIONS.txt", ios::app);
			for (int i = 0; i < r.roomNumber.size(); i++)
			{
				text += to_string(r.roomNumber[i]);
				text += "/";
			}
			text += "\n";
			text += to_string(r.checkIn);
			text += "\n";
			text += to_string(r.checkOut);
			text += "\n";
			text += to_string(r.price);
			text += "\n";
			text += to_string(r.discount);
			text += "\n";
			text += to_string(r.wakeUpService);
			text += "\n";
			text += to_string(r.isPaid);
			text += "/";
			text += to_string(r.isBreakfest);
			text += "/";
			text += to_string(r.isDinner);
			text += "/";
			text += to_string(r.isParking);
			text += "\n";
			text += to_string(r.isCanceled);
			text += "\n";
			file << text;
			file.close();
			o.modifyRegistry(r.checkIn, r.checkOut, r.roomNumber, 1);
		
	}
	else
	{
		cout << "Reservation with this ID already exists" << endl;
	}
}

void reservation::Edit(reservation r)
{
	string text;
	reservation* buffer = readOneFromFile(r.ID);
	occupancy o;
	o.modifyRegistry(buffer->checkIn, buffer->checkOut, buffer->roomNumber, 0);
	if (o.checkIfFree(r.checkIn, r.checkOut, r.roomNumber))
	{
		text += readFromFile(r.ID);
		//text += "\n";
		text += to_string(r.ID);
		text += "\n";
		for (int i = 0; i < r.roomNumber.size(); i++)
		{
			text += to_string(roomNumber[i]);
			text += "/";
		}
		text += "\n";
		text += to_string(r.checkIn);
		text += "\n";
		text += to_string(r.checkOut);
		text += "\n";
		text += to_string(r.price);
		text += "\n";
		text += to_string(r.discount);
		text += "\n";
		text += to_string(r.wakeUpService);
		text += "\n";
		text += to_string(r.isPaid);
		text += "/";
		text += to_string(r.isBreakfest);
		text += "/";
		text += to_string(r.isDinner);
		text += "/";
		text += to_string(r.isParking);
		text += "\n";
		text += to_string(r.isCanceled);

		fstream file;
		file.open("RESERVATIONS.txt");
		if (file.is_open())
		{
			file << text;
		}
		file.close();
		o.modifyRegistry(r.checkIn, r.checkOut, r.roomNumber, 1);
	}
	else
	{
		cout << "Selected rooms are already occupied!" << endl;
	}
}
void print1(reservation* r)
{
	cout << r->ID << endl;
	for (int i = 0; i < r->roomNumber.size(); i++)
	{
		cout << r->roomNumber[i] << "/";
	}
	cout <<endl << r->checkIn << endl;
	cout << r->checkOut << endl;
	cout << r->price << endl;
	cout << r->discount << endl;
	cout << r->wakeUpService << endl;
	cout << r->isPaid << "/";
	cout << r->isBreakfest << "/";
	cout << r->isDinner << "/";
	cout << r->isParking << endl;
	cout << r->isCanceled << endl;
}
reservation* reservation::readOneFromFile(int ID)
{
	string contents, line;
	fstream file;

	int switcher = 0;
	int switcher2 = 0;
	file.open("RESERVATIONS.txt");
	if (file.is_open())
	{
		reservation* newNode = new reservation;
		while (getline(file, line))
		{
			string num;
			
			if(isdigit(line[0]))
			{
				if (ID == stoi(line))
				{
					switcher++;
					newNode->ID = ID;
				}
			}
			if (switcher == 2)
			{
				for (int i = 0; i < line.size(); i++)
				{
					if (line[i] == '/')
					{
						newNode->roomNumber.push_back(stoi(num));
						num = "";
					}
					else if (isdigit(line[i]))
					{
						num += line[i];
					}
				}
			}
			else if (switcher == 3)
			{
				newNode->checkIn = stoi(line);
			}
			else if (switcher == 4)
			{
				newNode->checkOut = stoi(line);
			}
			else if (switcher == 5)
			{
				newNode->price = stoi(line);
			}
			else if (switcher == 6)
			{
				newNode->discount = stoi(line);
			}
			else if (switcher == 7)
			{
				newNode->wakeUpService = stoi(line);
			}
			else if (switcher == 8)
			{
				switcher2 = 0;
				for (int i = 0; i < line.size(); i++)
				{
					if (line[i] == '/')
					{
						switcher2++;
					}
					else
					{
						switch (switcher2)
						{
						case 0:
							if (line[i] == '1')
							{
								newNode->isPaid = true;
							}
							else if (line[i] == '0')
							{
								newNode->isPaid = false;

							}
							break;
						case 1:
							if (line[i] == '1')
							{
								newNode->isBreakfest = true;
							}
							else if (line[i] == '0')
							{
								newNode->isBreakfest = false;

							}
							break;
						case 2:
							if (line[i] == '1')
							{
								newNode->isDinner = true;
							}
							else if (line[i] == '0')
							{
								newNode->isDinner = false;
							}
							break;
						case 3:
							if (line[i] == '1')
							{
								newNode->isParking = true;
							}
							else if (line[i] == '0')
							{
								newNode->isParking = false;

							}
						}
					}
				}
			}

			else if (switcher == 9)
			{

				if (line[0] == '1')
				{

					newNode->isCanceled = true;
				}
				else if (line[0] == '0')
				{
					newNode->isCanceled = false;
				}
				print1(newNode);
				return newNode;
			}

			if(switcher >= 1)
			{
				switcher++;
			}


		}
		if (switcher == 0)
		{
			cout << "Reservation with this ID does not exist" << endl;
		}

		return NULL;
	}
	file.close();
}
string reservation::readFromFile(int ID)
{
	string contents, line;
	fstream file;

	int switcher = 0;
	file.open("RESERVATIONS.txt");
	if (file.is_open())
	{
		while (getline(file, line))
		{
			if (isdigit(line[0]))
			{
				if (ID == stoi(line))
				{
					switcher++;
				}
			}
			if (switcher == 0 || switcher == 10)
			{
				contents += line;
				contents += "\n";
			}
			else if (switcher >= 1 && switcher <= 9)
			{
				switcher++;
			}


		}
	}
	file.close();
	return contents;
}
