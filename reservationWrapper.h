#ifndef RESERVATIONWRAPPER_H
#define RESERVATIONWRAPPER_H

class reservationWrapper {

private:
	int roomNumber;
	int isParking;
	int wakeUpService;
	int isPaid;
	int isBreakfest;
	int isDinner;
	int roomPrice;

public:
	void ConfirmReservation();
};

#endif
