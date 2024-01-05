#ifndef RECEPTION_H
#define RECEPTION_H

#include <iostream>
#include <vector>

#include "User.h"
#include "occupancyRegistry.h"

class Reception : public User {



public:
	void editReservation(int roomNumber);

	void editWebsite();

	void accesOccupancyRegistry();
};

#endif
