#include "Reception.h"

void Reception::editReservation(int roomNumber, int task) {

	std::cout << "What would you like to do? \nCreate new reservation - 1 \nEdit reservation - 2" << std::endl;
	if (task == 1)
		//Create reservation
	else if (task == 2)
		//Edit existing one
	else
		std::cout << "Wrong task number\n";
	throw "Not yet implemented";
}

void Reception::editWebsite() {

	// TODO - implement Reception::editWebsite
	throw "Not yet implemented";
}

void Reception::accesOccupancyRegistry() {
	// TODO - implement Reception::accesOccupancyRegistry
	throw "Not yet implemented";
}
