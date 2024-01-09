#ifndef RESERVATIONWRAPPER_H
#define RESERVATIONWRAPPER_H

class reservationWrapper {

private:
	int roomNumber;
	bool isParking;
	int wakeUpService;
	bool isPaid;
	bool isBreakfest;
	bool isDinner;
	int roomPrice;

public:
	void ConfirmReservation();
};

#endif
