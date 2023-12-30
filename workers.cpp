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

void workers::setWorkerSalary(std::string newName)
{
	name = newName;
}

void workers::changeIfPaid(bool bool willBePaid)
{
	isPaidThisMont = willBePaid;
}

void workers::changeReview(std::string newReview)
{
	workerReview = newReview;
}
