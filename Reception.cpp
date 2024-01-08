#include "Reception.h"

void Reception::editReservation() {

	int id;
	std::cout << "Choose ID of reservation which you like to edit";
	std::cin >> id;
	for (auto i : RESERVATION)
	{
		if(i==id)
			RESERVATION.editReservation(RESERVATION);
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
