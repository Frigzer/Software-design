#include "User.h"

void User::login() {

	// Logowanie do systemu na podstawie podanej nazwy
	std::cout << "Type your name: "; std::cin >> username;
    std::cout << "Type your password: "; std::cin >> password;
	

    // Otwarcie pliku z danymi u¿ytkowników
    std::ifstream file("users.txt");

    if (!file.is_open()) {
        std::cout << "ERROR while trying to access database." << std::endl;
        return false;
    }

    // Sprawdzenie, czy u¿ytkownik istnieje w pliku
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string stored_username, stored_password;

        if (iss >> stored_username >> stored_password) {
            if (stored_username == username && stored_password == password) {
                std::cout << "Succes" << std::endl;
                file.close();

                return true;
            }
        }
    }

    std::cout << "Failure into finding user" << std::endl;
    file.close();
    return false;
}
