#ifndef CLIENT_H
#define CLIENT_H

#include "User.h"
#include "MakeReservation.h"
#include "reservation.h"

class Client : public User {


public:
	void AskForReservation();
};

#endif
