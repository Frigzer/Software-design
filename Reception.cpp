#include "Reception.h"

void Reception::editReserv() {

	string task;
	while (true)
	{
		cout << "What do you want to do?\n\n";
		cout << "\t1) Make new reservation\n";
		cout << "\t2) Edit existing reservation\n\n";
		cout << "3) Return\n\n";
		cout << "Your choice: ";
		cin >> task;
		if (task == "1")
			makeReservation();
		else if (task == "2")
			editReservation();
		else if (task == "3")
			break;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Wrong task number, try again" << endl;
			system("pause");
		}
			
	}
}

void Reception::editWebsite() {
	string newEvent;
	int task;
	while (true)
	{
		system("cls");
		cout << "Event list:\n";
		for (int i = 0; i < website.eventCalendar.size(); i++)
		{
			cout << "\t" << website.eventCalendar[i] << endl;
		}
		cout << endl;
		
		cout << "\t1) Add new event\n\n ";
		cout << "2) Return\n\n";
		cout << "Your choice: ";
		cin >> task;
		if (task == 1)
		{
			cout << "Enter event content: ";
			cin.ignore();
			getline(cin, newEvent);
			website.eventCalendar.push_back(newEvent);
		}
		else if (task == 2)
			break;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Wrong task number, try again" << endl;
			system("pause");
			continue;
		}
	}
}

void Reception::accesOccupancyRegistry() {

	
	for (int i = 0; i < OCCUPANCY.size(); i++)
	{
		for (int j = 0; j < OCCUPANCY[i]->roomNumber.size(); j++)
		{
			if (OCCUPANCY[i]->isOccupied[j] == true)
			{
				cout << "!";
			}
			cout << OCCUPANCY[i]->roomNumber[j] << "/";
		}
		cout << "|" << OCCUPANCY[i]->date << endl;
	}
	cout << "\n\n";
	system("pause");
}
