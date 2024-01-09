#include "Reception.h"

void Reception::editReserv() {

	int task;
	std::cout << "What do you want to do? 1 - Make new reservation, 2 - Edit existing reservation: ";
	std::cin >> task;
	if (task == 1)
		makeReservation();
	else if (task == 2)
		editReservation();
	else
		std::cout << "Wrong task number";
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
