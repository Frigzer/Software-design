#ifndef RECEPTION_H
#define RECEPTION_H

#include <vector>

#include "User.h"
#include "occupancyRegistry.h"
#include "websiteData.h"

class Reception : public User {



public:
	void editReserv();

	void editWebsite();

	void accesOccupancyRegistry();
};

#endif
