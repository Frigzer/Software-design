#ifndef MENAGER_H
#define MENAGER_H

#include <iostream>
#include <vector>
#include "workers.h"

#include "Reception.h"

class Menager : public Reception {

private:
	std::vector<workers*> worker;
	// Dodawanie nowych pracowników, w vectorze bo mo¿e byæ ich wiêcej ni¿ 1
	void addWorker();

	// Zmiana pensji pracownika i ewentualna zmiana czy dostanie pieni¹dze w tym miesi¹cu
	void changeWorkerSalary();

	// Zmiana opisu pracownika
	void changeWorkerReview();

	bool getFromFile();

	bool writeToFile();

public:
	Menager();
	~Menager();
	void menageWorkers();

	void editWebpage();
};

#endif
