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

	// Tylko pingujemy "stronê" i sprawdzamy czy jest po³¹czenie
	int x = system("ping 127.0.0.1");
	if (x == 0) {
		std::cout << "success";
	}
	else {
		std::cout << "failed";
	}
}

void Reception::accesOccupancyRegistry() {

	occupancyRegistry registry;

	int task;
	std::cout << "What would you like to do? \nDisplay reservation calendar - 1 \nShow occupancy percentage - 2\nCheck if free space - 3" << std::endl;
	std::cin >> task;
	if (task == 1)
		throw "Not yet implemented";//Zwiazne ze zmienna reservationCalendar??
	else if (task == 2)
		throw "Not yet implemented";//Zwiazane ze zmienna occupancyPercentage??
	else if (task == 3)
		registry.CheckIfFree();
	else
		std::cout << "Wrong task number" << std::endl;
	

}
