#include "CEO.h"

// Funkcja wczytuj�ca daty �wi�t z pliku
std::vector<std::tm> CEO::readHolidays(const std::string& filename = "holidays.txt") {
    std::vector<std::tm> holidays;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "B��d podczas otwierania pliku z datami �wi�t." << std::endl;
        return holidays;
    }

    std::tm holidayDate;
    char delimiter;

    while (file >> std::get_time(&holidayDate, "%Y-%m-%d") >> delimiter) {
        holidays.push_back(holidayDate);
    }

    file.close();
    return holidays;
}

// Funkcja sprawdzaj�ca, czy data jest �wi�tem
bool CEO::isHoliday(const std::tm& date, const std::vector<std::tm>& holidays) {
    auto it = std::find(holidays.begin(), holidays.end(), date);
    return it != holidays.end();
}

float CEO::setPrices(const std::tm& date) {

	// Wczytanie dat �wi�t z pliku
	std::vector<std::tm> holidays = readHolidays("holidays.txt");

	//Domy�lne ceny
	float base_price = 100.0;
	float weekend_price = 120.0;
	float holiday_price = 150.0;

	//Sprawdzenie, czy jest to weekend
	bool is_weekend = (date.tm_wday == 0 || date.tm_wday==6);

	bool is_holiday = isHoliday(date, holidays);

	// Ustalanie ceny na podstawie dnia tygodnia
	float price;
	if (is_holiday) {
		price = holiday_price;
	}
	else if (is_weekend) {
		price = weekend_price;
	}
	else {
		price = base_price;
	}

	return price;
}
