#include "Menager.h"

void Menager::addWorker()
{
	std::string workerName;
	std::string workerRole, workerReview = "";
	int workerSalary = 2000;

	std::cout << "Type name for new worker: "; std::cin >> workerName; std::cout << std::endl;
	std::cout << "Select position for new worker: "; std::cin >> workerRole; std::cout << std::endl;
	std::cout << "Write workers review(without using space): "; std::cin >> workerReview; std::cout << std::endl;
	std::cout << "Type salary for new worker: "; std::cin >> workerSalary; std::cout << std::endl;

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
			std::cout << "Will be paid this month? "; std::cin >> isPaid; std::cout << std::endl;
			if (isPaid == "yes")
				i->changeIfPaid(true);
			else if(isPaid == "no")
				i->changeIfPaid(false);
			std::cout << "New salary: "; std::cin >> newSalary; std::cout << std::endl;
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

bool Menager::getFromFile()
{

	// Otwarcie pliku z danymi u¿ytkowników
	std::ifstream file("workers.txt");

	if (!file.is_open()) {
		std::cout << "ERROR while trying to access database." << std::endl;
		return false;
	}

	// Sprawdzenie, czy u¿ytkownik istnieje w pliku
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
	/*// Otwarcie pliku z danymi pracowników
	std::ofstream file("workers.txt", std::ios::app);

	if (!file.is_open()) {
		std::cout << "ERROR while trying to access database." << std::endl;
		return false;
	}

	// Sprawdzenie, czy u¿ytkownik istnieje w pliku
	std::string line;
	if (file.is_open()) {
		file << newName << " " << newRole << " " << newReview << " " << ifPaid << " " << newSalary << "\n";
		file.close();

		return true;
	}

	std::cout << "ERROR while trying to access database" << std::endl;
	file.close();
	return false;*/

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
	
	int task;
	std::cout << "What would you like to do? \nAdd new worker - 1 \nChange workers salary - 2 \nChange workers review - 3" << std::endl;
	std::cin >> task;
	if (task == 1)
		addWorker();
	else if (task == 2)
		changeWorkerSalary();
	else if (task == 3)
		changeWorkerReview();
	else
		std::cout << "Wrong task number" << std::endl;
	
}

void Menager::editWebpage() {

	// Tylko pingujemy "stronê" i sprawdzamy czy jest po³¹czenie
	int x = system("ping -c1 -s1 8.8.8.8  > /dev/null 2>&1");
	if (x == 0) {
		std::cout << "success";
	}
	else {
		std::cout << "failed";
	}
}
