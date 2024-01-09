#include "workers.h"

workers::workers()
{

}

workers::workers(std::string newName, std::string newRole, std::string newWorkerReview, bool willBePaid, int newSalary):name(newName), role(newRole), workerReview(newWorkerReview), isPaidThisMonth(willBePaid), salary(newSalary)
{

}

workers::~workers()
{

}

std::string workers::getWorkerName()
{
	return name;
}

std::string workers::getWorkerRole()
{
	return role;
}

std::string workers::getWorkerreview()
{
	return workerReview;
}

bool workers::getIfPaid()
{
	return isPaidThisMonth;
}

int workers::getWorkerSalary()
{
	return salary;
}

void workers::setWorkerSalary(int newSalary)
{
	salary = newSalary;
}

void workers::changeIfPaid(bool willBePaid)
{
	isPaidThisMonth = willBePaid;
}

void workers::changeReview(std::string newReview)
{
	workerReview = newReview;
}
