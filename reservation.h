#ifndef RESERVATION_H
#define RESERVATION_H

class reservation {

private:
	int roomNumber;
	bool isParking;
	int wakeUpService;
	bool isPaid;
	bool isBreakfest;
	bool isDinner;
	int roomPrice;
	int discount;
	bool isForService;

public:
	reservation()
	{};

	void ConfirmReservation();

	void Edit();
};

#endif
