#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class User {

private:
	std::string username;
	std::string password;

public:
	bool login();
};

#endif
