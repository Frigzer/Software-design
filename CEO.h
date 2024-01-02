#ifndef CEO_H
#define CEO_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>

class CEO : Menager {

	// Funkcja wczytuj¹ca daty œwi¹t z pliku
	std::vector<std::tm> readHolidays(const std::string& filename);
	// Funkcja sprawdzaj¹ca, czy data jest œwiêtem
	bool isHoliday(const std::tm& date, const std::vector<std::tm>& holidays);

public:
	//Ustalanie ceny na podstawie podanej daty
	float setPrices(const std::tm& date);
};

#endif
