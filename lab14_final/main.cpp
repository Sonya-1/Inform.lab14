#include <iostream> 
#include "worker.h"

int main() {

	WorkerBase* wb = new WorkerBase();
	menu(wb);
	wb->print();
	std::cout << "Total salary: " << wb->calcTotalSalary() << '\n';
	wb->erase();
	delete wb;

	return 0;
}