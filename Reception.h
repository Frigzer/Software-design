#ifndef RECEPTION_H
#define RECEPTION_H

#include <iostream>
#include <vector>

#include "User.h"
#include "occupancyRegistry.h"
#include "websiteData.h"
#include "reservation.h"

class Reception : public User {



public:
	void editReservation();

	void editWebsite();

	void accesOccupancyRegistry();
};

#endif
