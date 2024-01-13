#include "Client.h"
#include "CEO.h"

int main()
{
	bool backToLoginAsClient = false;
	bool backToChoiceSelectionAsClient = false;

	bool backToLoginAsReception = false;
	bool backToChoiceSelectionAsReception = false;

	bool backToLoginAsMenager = false;
	bool backToChoiceSelectionAsMenager = false;

	bool backToLoginAsCEO = false;
	bool backToChoiceSelectionAsCEO = false;

	int task = 0;
	while (true)
	{
		cout << "Select role\n\n";
		cout << "\t1) Client\n";
		cout << "\t2) Reception\n";
		cout << "\t3) Manager\n";
		cout << "\t4) CEO\n";
		cout << "\n5) Exit program\n";
		cout << "\nYour choice: ";
		if(!backToChoiceSelectionAsClient && !backToLoginAsClient && !backToLoginAsReception && !backToChoiceSelectionAsReception && !backToLoginAsMenager && !backToChoiceSelectionAsMenager && !backToLoginAsCEO && !backToChoiceSelectionAsCEO)
			cin >> task;

		if (task == 1 || backToLoginAsClient || backToChoiceSelectionAsClient)
		{
			task = 0;
			int select;
			backToLoginAsClient = false;
			Client klient;
			system("cls");
			cout << "Logging as client\n\n";
			if (backToChoiceSelectionAsClient || klient.login("Client"))
			{
				backToChoiceSelectionAsClient = false;
				cout << "What do you want to do?\n\n";
				cout << "\t1) Create reservation\n\n";
				cout << "2) Logout\n";
				cout << "\nYour choice: ";
				cin >> select;
				if (select == 1)
				{
					system("cls");
					klient.AskForReservation();
				}		
				else if (select == 2)
				{
					system("cls");
					exit;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Wrong task number!!!, try again\n";
					system("pause");
					backToChoiceSelectionAsClient = true;
				}
			}
			else
			{
				string choice;
				cout << "Do you want to try again? (y or yes)\n";
				cout << "Your choice: ";
				cin >> choice;
				if (choice == "y" || choice =="yes")
				{
					backToLoginAsClient = true;
				}
				else
				{
					system("cls");
					exit;
				}
			}
		}
		else if (task == 2 || backToLoginAsReception || backToChoiceSelectionAsReception)
		{
			task = 0;
			int select;
			backToLoginAsReception = false;
			Reception recepcja;
			system("cls");
			cout << "Logging as reception\n\n";
			if (backToChoiceSelectionAsReception || recepcja.login("Reception"))
			{
				backToChoiceSelectionAsReception = false;
				cout << "What do you want to do?\n\n";
				cout << "\t1) Create or edit reservation\n";
				cout << "\t2) Access occupancy registry\n";
				cout << "\t3) Edit website board\n\n";
				cout << "4) Logout\n";
				cout << "\nYour choice: ";
				cin >> select;
				if (select == 1)
				{
					system("cls");
					backToChoiceSelectionAsReception = true;
					recepcja.editReserv();
				}
				else if (select == 2)
				{
					system("cls");
					backToChoiceSelectionAsReception = true;
					recepcja.accesOccupancyRegistry();
				}
				else if (select == 3)
				{
					system("cls");
					backToChoiceSelectionAsReception = true;
					recepcja.editWebsite();
				}
				else if (select == 4)
				{
					system("cls");
					exit;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Wrong task number!!!, try again\n";
					system("pause");
					backToChoiceSelectionAsReception = true;
				}
			}
			else
			{
				string choice;
				cout << "Do you want to try again? (y or yes)\n";
				cout << "Your choice: ";
				cin >> choice;
				if (choice == "y" || choice == "yes")
				{
					backToLoginAsReception = true;
				}
				else
				{
					system("cls");
					exit;
				}
			}

		}		
		else if (task == 3 || backToLoginAsMenager || backToChoiceSelectionAsMenager)
		{
			task = 0;
			int select;
			backToLoginAsMenager = false;
			Menager manager;
			system("cls");
			cout << "Logging as manager\n\n";
			if (backToChoiceSelectionAsMenager || manager.login("Menager"))
			{
				backToChoiceSelectionAsMenager = false;
				cout << "What do you want to do?\n\n";
				cout << "\t1) Create or edit reservation\n";
				cout << "\t2) Access occupancy registry\n";
				cout << "\t3) Edit website board\n";
				cout << "\t4) Edit hotel info\n";
				cout << "\t5) Manage workers\n\n";
				cout << "6) Logout\n";
				cout << "\nYour choice: ";
				cin >> select;
				if (select == 1)
				{
					system("cls");
					backToChoiceSelectionAsMenager = true;
					manager.editReserv();
				}
				else if (select == 2)
				{
					system("cls");
					backToChoiceSelectionAsMenager = true;
					manager.accesOccupancyRegistry();
				}
				else if (select == 3)
				{
					system("cls");
					backToChoiceSelectionAsMenager = true;
					manager.editWebsite();
				}
				else if (select == 4)
				{
					system("cls");
					backToChoiceSelectionAsMenager = true;
					manager.editWebpage();
				}
				else if (select == 5)
				{
					system("cls");
					backToChoiceSelectionAsMenager = true;
					manager.menageWorkers();
				}
				else if (select == 6)
				{
					system("cls");
					exit;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Wrong task number!!!, try again\n";
					system("pause");
					backToChoiceSelectionAsMenager = true;
				}
			}
			else
			{
				string choice;
				cout << "Do you want to try again? (y or yes)\n";
				cout << "Your choice: ";
				cin >> choice;
				if (choice == "y" || choice == "yes")
				{
					backToLoginAsMenager = true;
				}
				else
				{
					system("cls");
					exit;
				}
			}
		}
		else if (task == 4 || backToLoginAsCEO || backToChoiceSelectionAsCEO)
		{
			task = 0;
			int select;
			backToLoginAsCEO = false;
			CEO dyrektor;
			system("cls");
			cout << "Logging as CEO\n\n";
			if (backToChoiceSelectionAsCEO || dyrektor.login("CEO"))
			{
				backToChoiceSelectionAsCEO = false;
				cout << "What do you want to do?\n\n";
				cout << "\t1) Create or edit reservation\n";
				cout << "\t2) Access occupancy registry\n";
				cout << "\t3) Edit website board\n";
				cout << "\t4) Edit hotel info\n";
				cout << "\t5) Manage workers\n";
				cout << "\t6) Set prices\n\n";
				cout << "7) Logout\n";
				cout << "\nYour choice: ";
				cin >> select;
				if (select == 1)
				{
					system("cls");
					backToChoiceSelectionAsCEO = true;
					dyrektor.editReserv();
				}
				else if (select == 2)
				{
					system("cls");
					backToChoiceSelectionAsCEO = true;
					dyrektor.accesOccupancyRegistry();
				}
				else if (select == 3)
				{
					system("cls");
					backToChoiceSelectionAsCEO = true;
					dyrektor.editWebsite();
				}
				else if (select == 4)
				{
					system("cls");
					backToChoiceSelectionAsCEO = true;
					dyrektor.editWebpage();
				}
				else if (select == 5)
				{
					system("cls");
					backToChoiceSelectionAsCEO = true;
					dyrektor.menageWorkers();
				}
				else if (select == 6)
				{
					system("cls");
					backToChoiceSelectionAsCEO = true;
					dyrektor.setPrices();
				}
				else if (select == 7)
				{
					system("cls");
					exit;
				}
				else
				{
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					cout << "Wrong task number!!!, try again\n";
					system("pause");
					backToChoiceSelectionAsCEO = true;
				}
			}
			else
			{
				string choice;
				cout << "Do you want to try again? (y or yes)\n";
				cout << "Your choice: ";
				cin >> choice;
				if (choice == "y" || choice == "yes")
				{
					backToLoginAsCEO = true;
				}
				else
				{
					system("cls");
					exit;
				}
			}

		}
		else if (task == 5)
			return 0;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Wrong role number!!!, try again\n";
			system("pause");
			system("cls");
		}
			
	}
}