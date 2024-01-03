#ifndef RECEPTION_H
#define RECEPTION_H

#include <iostream>
#include <vector>
#include "reservationWrapper.h"

class Reception : User {


	std::vector<reservationWrapper*> worker;

public:
	void editReservation(int roomNumber, int task);

	void editWebsite();

	void accesOccupancyRegistry();
};

#endif
