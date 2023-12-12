#ifndef RESERVATION_H
#define RESERVATION_H

class reservation {

private:
	int roomNumber;
	int isParking;
	int wakeUpService;
	int isPaid;
	int isBreakfest;
	int isDinner;
	int roomPrice;
	int discount;
	int isForService;

public:
	void ConfirmReservation();

	void Edit();
};

#endif
