#ifndef MENAGER_H
#define MENAGER_H

#include <iostream>
#include <vector>
#include "workers.h"

class Menager : Reception {

	std::vector<workers*> worker;

	// Dodawanie nowych pracownik�w, w vectorze bo mo�e by� ich wi�cej ni� 1
	void addWorker(std::string workerName);

	// Zmiana pensji pracownika i ewentualna zmiana czy dostanie pieni�dze w tym miesi�cu
	void changeWorkerSalary(std::string workerName);

	// Zmiana opisu pracownika
	void changeWorkerReview(std::string workerName);

public:
	void menageWorkers(std::string workerName, int task);

	void editWebpage();
};

#endif
