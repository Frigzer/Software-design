#include "Menager.h"

void Menager::addWorker(std::string workerName)
{
	std::string workerRole, workerReview = "";
	int workerSalary = 2000;

	std::cout << "Select position for new worker: "; std::cin >> workerRole; std::cout << std::endl;
	std::cout << "Type salary for new worker: "; std::cin >> workerSalary; std::cout << std::endl;

	//std::vector<workers*> worker;
	worker.push_back(new workers(workerName, workerRole, workerReview, true, workerSalary);
}

void Menager::changeWorkerSalary(std::string workerName)
{
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

void Menager::changeWorkerReview(std::string workerName)
{
	
	for (auto* i : worker)
	{
		std::string newReview;
		if (i->getWorkerName() == workerName)
		{
			std::cout << "New worker review:\n"; std::cin >> newReview; std::cout << endl;
			i->changeReview(newReview);
		}
	}
}

void Menager::menageWorkers(std::string workerName, int task) 
{
	std::cout << "What would you like to do? \nAdd new worker - 1 \nChange workers salary - 2 \nChange workers review - 3" << std::endl;
	if (task == 1)
		addWorker(workerName);
	else if (task == 2)
		changeWorkerSalary(workerName);
	else if (task == 3)
		changeWorkerReview(workerName);
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
