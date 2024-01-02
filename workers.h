#ifndef WORKERS_H
#define WORKERS_H

#include <iostream>

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

	void setWorkerSalary(std::string newName);

	void changeIfPaid(bool willBePaid);

	void changeReview(std::string newReview);
};

#endif
