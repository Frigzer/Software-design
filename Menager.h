#ifndef MENAGER_H
#define MENAGER_H

#include <iostream>
#include <vector>
#include "workers.h"

class Menager : Reception {

	std::vector<workers*> worker;

	// Dodawanie nowych pracowników, w vectorze bo mo¿e byæ ich wiêcej ni¿ 1
	void addWorker(std::string workerName);

	// Zmiana pensji pracownika i ewentualna zmiana czy dostanie pieni¹dze w tym miesi¹cu
	void changeWorkerSalary(std::string workerName);

	// Zmiana opisu pracownika
	void changeWorkerReview(std::string workerName);

public:
	void menageWorkers(std::string workerName, int task);

	void editWebpage();
};

#endif
