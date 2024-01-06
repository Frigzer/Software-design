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

	// Funkcja wczytuj�ca daty �wi�t z pliku
	std::vector<std::tm> readHolidays();
	// Funkcja sprawdzaj�ca, czy data jest �wi�tem
	bool isHoliday(const std::tm& date, const std::vector<std::tm>& holidays);

public:
	//Ustalanie ceny na podstawie podanej daty
	float setPrices(const std::string& dateStr, char roomType);
};

#endif
