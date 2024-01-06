#ifndef CEO_H
#define CEO_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <sstream>
#include <iomanip>


#include "Menager.h"

class CEO : public Menager {

	// Funkcja wczytuj¹ca daty œwi¹t z pliku
	std::vector<std::tm> readHolidays();
	// Funkcja sprawdzaj¹ca, czy data jest œwiêtem
	bool isHoliday(const std::tm& date, const std::vector<std::tm>& holidays);

public:
	//Ustalanie ceny na podstawie podanej daty
	float setPrices(const std::string& dateStr, char roomType);
};

#endif
