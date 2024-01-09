#include "predictPrices.h"

int predictPrices(int date, std::string roomClass) {

	std::istringstream iss(date);

	std::string newDate="0000-00-00";

	iss >> newDate[8] >> newDate[9] >> newDate[5] >> newDate[6] >> newDate[0] >> newDate[1] >> newDate[2] >> newDate[3];

	return ceo.setPrices(newDate, roomClass);
}
