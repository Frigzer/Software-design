#include "CEO.h"

// Funkcja wczytuj�ca daty �wi�t z pliku
std::vector<std::tm> CEO::readHolidays() {
    std::vector<std::tm> holidays;
    std::ifstream file("holidays.txt");

    if (!file.is_open()) {
        std::cout << "B��d podczas otwierania pliku z datami �wi�t." << std::endl;
        return holidays;
    }

    std::string dateString;
    while (std::getline(file, dateString)) {
        std::istringstream iss(dateString);
        std::tm holidayDate = {};
        if (!(iss >> std::get_time(&holidayDate, "%Y-%m-%d"))) {
            std::cout << "B��d podczas przetwarzania daty." << std::endl;
            continue; // Pomini�cie b��dnej daty
        }
        holidays.push_back(holidayDate);
    }

    file.close();
    return holidays;
}

// Funkcja sprawdzaj�ca, czy data jest �wi�tem
bool CEO::isHoliday(const std::tm& date, const std::vector<std::tm>& holidays) {
    for (auto i : holidays)
    {
        if (i.tm_year == date.tm_year && i.tm_mday == date.tm_mday && i.tm_mon == date.tm_mon)
            return true;

    }
    return false;
   
}

float CEO::setPrices(const std::string& dateStr, char roomType) {

	// Wczytanie dat �wi�t z pliku
	std::vector<std::tm> holidays = readHolidays();

    std::tm date = {};
    std::istringstream iss(dateStr);
    char delimiter;
    if (!(iss >> date.tm_year >> delimiter >> date.tm_mon >> delimiter >> date.tm_mday) || delimiter != '-') {
        std::cout << "B��d podczas przetwarzania daty." << std::endl;
        return -1.0; // Zwracamy warto�� ujemn� jako sygna� b��du
    }

    // Korekta roku i miesi�ca, poniewa� std::tm oczekuje, �e rok to rok od 1900, a miesi�ce s� numerowane od 0
    date.tm_year -= 1900;
    date.tm_mon--;
    std::mktime(&date);

    // Domy�lne ceny
    float base_price = 100.0;
    float weekend_price = 120.0;
    float holiday_price = 150.0;

    // Sprawdzenie, czy to weekend
    bool is_weekend = false;
    if(date.tm_wday == 0 || date.tm_wday == 6) // Niedziela (0) lub sobota (6)
        is_weekend = true;
    else
        is_weekend = false;

    // Sprawdzenie, czy to �wi�to
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

    switch (roomType) {
    case 'S':
        return price + float(100.0); // Cena za standardowy pok�j
    case 'P':
        return  price + float(300.0); // Cena za penthouse
    case 'L':
        return  price + float(500.0); // Cena za luxury
    default:
        std::cout << "Unknown room type!!!" << std::endl;
        return 0;   // Nieznany typ pokoju
    }
}
