#include "Menager.h"

void Menager::addWorker()
{
	std::string workerName;
	std::string workerRole, workerReview = "";
	int workerSalary = 2000;

	std::cout << "Type name for new worker: "; std::cin >> workerName;
	std::cout << "Select position for new worker: "; std::cin >> workerRole;;
	std::cout << "Write workers review(without using space): "; std::cin >> workerReview;;
	std::cout << "Type salary for new worker: "; std::cin >> workerSalary;

	//std::vector<workers*> worker;
	worker.push_back(new workers(workerName, workerRole, workerReview, true, workerSalary));

}

void Menager::changeWorkerSalary()
{
	std::string workerName;
	std::cout << "Worker name: ";
	std::cin >> workerName;
	for (auto *i : worker)
	{
		int newSalary = 2000;
		std::string isPaid;
		if (i->getWorkerName() == workerName)
		{
			std::cout << "Will be paid this month? "; std::cin >> isPaid;
			if (isPaid == "yes")
				i->changeIfPaid(true);
			else if(isPaid == "no")
				i->changeIfPaid(false);
			std::cout << "New salary: "; std::cin >> newSalary;
			i->setWorkerSalary(newSalary);
		}
	}
}

void Menager::changeWorkerReview()
{
	std::string workerName;
	std::cout << "Worker name: ";
	std::cin >> workerName;
	for (auto* i : worker)
	{
		std::string newReview;
		if (i->getWorkerName() == workerName)
		{
			std::cout << "New worker review:\n"; std::cin >> newReview; std::cout << std::endl;
			i->changeReview(newReview);
		}
	}
}

void Menager::deleteWorker()
{
	std::string workerName;
	std::cout << "Worker name: ";
	std::cin >> workerName;
	for (int i = 0; i < worker.size(); ++i)
	{
		if (worker[i]->getWorkerName() == workerName)
		{
			delete worker[i];
			worker.erase(worker.begin()+i);
		}
	}
}

bool Menager::getFromFile()
{

	// Otwarcie pliku z danymi u�ytkownik�w
	std::ifstream file("workers.txt");

	if (!file.is_open()) {
		std::cout << "ERROR while trying to access database." << std::endl;
		return false;
	}

	// Sprawdzenie, czy u�ytkownik istnieje w pliku
	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::string workerName, workerRole, workerReview, workerIfPaid, workerSalary;

		if (iss >> workerName >> workerRole >> workerReview >> workerIfPaid >> workerSalary) {
			bool isPaid = true;
			if (workerIfPaid == "no")
				isPaid = false;
			worker.push_back(new workers(workerName, workerRole, workerReview, isPaid, stoi(workerSalary)));

		}
	}


	file.close();
	return true;
}

bool Menager::writeToFile()
{
	std::ofstream file("workers.txt");

	if (!file.is_open()) {
		std::cout << "ERROR while trying to access database." << std::endl;
		return false;
	}

	for (auto* i : worker)
	{
		std::string ifPaid = "yes";
		if (!i->getIfPaid())
			ifPaid = "no";
		std::stringstream aa;
		aa << i->getWorkerSalary();
		file << i->getWorkerName() << " " << i->getWorkerRole() << " " << i->getWorkerreview() << " " << ifPaid << " " << aa.str() << "\n";
	}
	file.close();
	return true;
}


Menager::Menager()
{
	getFromFile();
}

Menager::~Menager()
{
	writeToFile();
}

void Menager::menageWorkers()
{
	while (true)
	{
		system("cls");
		int task;
		cout << "What would you like to do?\n\n";
		cout << "\t1) Add new worker\n";
		cout << "\t2) Change workers salary\n";
		cout << "\t3) Change workers review\n";
		cout << "\t4) Delete worker\n\n";
		cout << "5) Return\n";
		cout << "\nInput task number: ";
		cin >> task;
		if (task == 1)
			addWorker();
		else if (task == 2)
			changeWorkerSalary();
		else if (task == 3)
			changeWorkerReview();
		else if (task == 4)
			deleteWorker();
		else if (task == 5)
			break;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong task number, Try again" << std::endl;
			system("pause");		
		}
	}

}

void Menager::editWebpage() {
	int task = 0;
	while (true)
	{
		system("cls");
		if (website.hotelInfo != "")
		{
			cout << "Current hotel info: ";
			cout << website.hotelInfo;
			cout << "\n\n";
		}
		cout << "What do you want to do?\n\n";
		if (website.hotelInfo != "")
			cout << "\t1) Change hotel info\n\n";
		else
			cout << "\t1) Add hotel info\n\n";
		cout << "2) Return\n\n";
		cout << "Your choice: ";
		cin >> task;
		if (task == 1)
		{
			cout << "New hotel info: ";
			cin.ignore();
			getline(cin, website.hotelInfo);
			
		}
		else if (task == 2)
			break;
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Wrong task number, try again\n";
			system("pause");
		}
	}
}
