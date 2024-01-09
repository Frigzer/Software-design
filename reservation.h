#ifndef RESERVATION_H
#define RESERVATION_H
#include <vector>
#include <string>

using namespace std;

struct reservation {
	int ID;
	std::vector<int>roomNumber;
	int checkIn;
	int checkOut;
	bool isParking;
	int wakeUpService;
	bool isPaid;
	bool isBreakfest;
	bool isDinner;
	int price;
	int discount;
	bool isCanceled;
	reservation* readOneFromFile(int);
	void writeToFile(reservation);

	std::string readFromFile(int);

	reservation()
	{};

	void ConfirmReservation();

	void Edit(reservation);
};

std::vector <reservation*> RESERVATION;

#endif

