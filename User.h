#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "MakeReservation.h"

using namespace std;

class User {

private:
	string username;
	string password;

public:
	bool login(string role);
};

#endif
