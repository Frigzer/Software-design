#include "Reception.h"

void Reception::editReservation(int roomNumber) {

	int task;
	std::cout << "What would you like to do? \nCreate new reservation - 1 \nEdit reservation - 2" << std::endl;
	//if (task == 1)
		//Create reservation
	//else if (task == 2)
		//Edit existing one
	//else
		//std::cout << "Wrong task number\n";
	throw "Not yet implemented";
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
			std::cout << OCCUPANCY[i]->roomNumber[j] << "/";
		}
		std::cout << "|" << OCCUPANCY[i]->date << std::endl;
	}
}
