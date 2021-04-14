#include "worker.h"
#ifndef E_H
#define E_H

class Employee : public Worker {
private:
	int copies;
	double percent;
	double price;
	char* title;
public:
	Employee(int id, char* name, int copies, double percent, double price, char* title);
	double calcSalary(double bonus) final override;
	void print() final override;
	Employee(const Employee& w);
	Employee& operator=(const Employee& w);
	~Employee();
};

#endif
