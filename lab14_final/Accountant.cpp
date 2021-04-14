#include <iostream> 
#include "worker.h"
#include "Accountant.h"

Accountant::Accountant(int id, char* name, double salary) : Worker(id, name) {
	this->salary = salary;
}

double Accountant::calcSalary(double bonus) {
	return (salary + bonus);
}

void Accountant::print() {
	std::cout << "Accountant id: " << this->getId() << '\t' <<
		"name: " << this->getName() << '\t' <<
		"fixed salary: " << this->salary;
}
