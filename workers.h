#ifndef WORKERS_H
#define WORKERS_H

#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>

class workers {

private:
	std::string name;
	std::string role;
	std::string workerReview;
	bool isPaidThisMonth;
	int salary;

public:
	workers();
	workers(std::string newName, std::string newRole, std::string newWorkerReview, bool willBePaid, int newSalary);
	~workers();

	std::string getWorkerName();

	std::string getWorkerRole();

	std::string getWorkerreview();

	bool getIfPaid();

	int getWorkerSalary();

	void setWorkerSalary(int newSalary);

	void changeIfPaid(bool willBePaid);

	void changeReview(std::string newReview);
};

#endif
