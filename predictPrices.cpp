#include "predictPrices.h"

// Funkcja wczytuj¹ca daty œwi¹t z pliku
std::vector<std::tm> readHolidays() {
    std::vector<std::tm> holidays;
    std::ifstream file("holidays.txt");

    if (!file.is_open()) {
        std::cout << "B³¹d podczas otwierania pliku z datami œwi¹t." << std::endl;
        return holidays;
    }

    std::string dateString;
    while (std::getline(file, dateString)) {
        std::istringstream iss(dateString);
        std::tm holidayDate = {};
        if (!(iss >> std::get_time(&holidayDate, "%Y-%m-%d"))) {
            std::cout << "B³¹d podczas przetwarzania daty." << std::endl;
            continue; // Pominiêcie b³êdnej daty
        }
        holidays.push_back(holidayDate);
    }

    file.close();
    return holidays;
}

// Funkcja sprawdzaj¹ca, czy data jest œwiêtem
bool isHoliday(const std::tm& date, const std::vector<std::tm>& holidays) {
    for (auto i : holidays)
    {
        if (i.tm_year == date.tm_year && i.tm_mday == date.tm_mday && i.tm_mon == date.tm_mon)
            return true;

    }
    return false;

}


int predictPrices(int dateInt, std::string roomType) {

    std::string dateStr="0000-00-00";
    std::string test;
    test = std::to_string(dateInt);
    dateStr[0] = test[0];
    dateStr[1] = test[1];
    dateStr[2] = test[2];
    dateStr[3] = test[3];
    dateStr[4] = '-';
    dateStr[5] = test[4];
    dateStr[6] = test[5];
    dateStr[7] = '-';
    dateStr[8] = test[6];
    dateStr[9] = test[7];

    std::cout << dateStr << std::endl;

    // Wczytanie dat œwi¹t z pliku
    std::vector<std::tm> holidays = readHolidays();

    std::tm date = {};
    std::istringstream iss(dateStr);
    char delimiter;
    if (!(iss >> date.tm_year >> delimiter >> date.tm_mon >> delimiter >> date.tm_mday) || delimiter != '-') {
        std::cout << "B³¹d podczas przetwarzania daty." << std::endl;
        return -1; // Zwracamy wartoœæ ujemn¹ jako sygna³ b³êdu
    }

    // Korekta roku i miesi¹ca, poniewa¿ std::tm oczekuje, ¿e rok to rok od 1900, a miesi¹ce s¹ numerowane od 0
    date.tm_year -= 1900;
    date.tm_mon--;
    std::mktime(&date);

    // Domyœlne ceny
    int base_price = defaultPrice;
    int weekend_price = weekendPrice;
    int holiday_price = holidayPrice;

    // Sprawdzenie, czy to weekend
    bool is_weekend = false;
    if (date.tm_wday == 0 || date.tm_wday == 6) // Niedziela (0) lub sobota (6)
        is_weekend = true;
    else
        is_weekend = false;

    // Sprawdzenie, czy to œwiêto
    bool is_holiday = isHoliday(date, holidays);

    // Ustalanie ceny na podstawie dnia tygodnia
    int price;
    if (is_holiday) {
        price = holiday_price;
    }
    else if (is_weekend) {
        price = weekend_price;
    }
    else {
        price = base_price;
    }

    if (roomType == "S")
         return price + standardPrice; // Cena za standardowy pokój
    else if (roomType == "P")
         return price + penthousePrice; // Cena za penthouse
    else if (roomType == "L")
        return price + luxuryPrice; // Cena za luxury
    else
    {
        std::cout << "Unknown room type!!!" << std::endl;
        return 0;   // Nieznany typ pokoju
    }


}
