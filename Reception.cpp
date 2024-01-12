#include "Reception.h"

void Reception::editReserv() {

	int task;
	while (true)
	{
		cout << "What do you want to do?\n\n";
		cout << "\t1) Make new reservation\n";
		cout << "\t2) Edit existing reservation\n\n";
		cout << "3) Return\n\n";
		cout << "Your choice: ";
		cin >> task;
		if (task == 1)
			makeReservation();
		else if (task == 2)
			editReservation();
		else if (task == 3)
			break;
		else
			cout << "Wrong task number";
	}
}

void Reception::editWebsite() {
	std::string newEvent;
	std::cout << "Adding new event: ";

	website.eventCalendar.push_back(newEvent);

	// Tylko pingujemy "stronê" i sprawdzamy czy jest po³¹czenie
	/*
	int x = system("ping 127.0.0.1");
	if (x == 0) {
		std::cout << "success";
	}
	else {
		std::cout << "failed";
	}*/
}

void Reception::accesOccupancyRegistry() {

	
	for (int i = 0; i < OCCUPANCY.size(); i++)
	{
		for (int j = 0; j < OCCUPANCY[i]->roomNumber.size(); j++)
		{
			if (OCCUPANCY[i]->isOccupied[j] == true)
			{
				cout << "!";
			}
			cout << OCCUPANCY[i]->roomNumber[j] << "/";
		}
		cout << "|" << OCCUPANCY[i]->date << endl;
	}
}
