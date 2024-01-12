#ifndef PREDICTPRICES_H
#define PREDICTPRICES_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <sstream>
#include <iomanip>

static int defaultPrice = 100;
static int weekendPrice = 120;
static int holidayPrice = 150;
static int standardPrice = 100;
static int penthousePrice = 300;
static int luxuryPrice = 500;

// Funkcja wczytuj¹ca daty œwi¹t z pliku
std::vector<std::tm> readHolidays();
// Funkcja sprawdzaj¹ca, czy data jest œwiêtem
bool isHoliday(const std::tm& date, const std::vector<std::tm>& holidays);

//Ustalanie ceny na podstawie podanej daty
int predictPrices(int dateInt, std::string roomType);


#endif
