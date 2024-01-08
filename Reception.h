#ifndef RECEPTION_H
#define RECEPTION_H

#include <iostream>
#include <vector>

#include "User.h"
#include "occupancyRegistry.h"
#include "websiteData.h"

class Reception : public User {



public:
	void editReservation(int roomNumber);

	void editWebsite();

	void accesOccupancyRegistry();
};

#endif
