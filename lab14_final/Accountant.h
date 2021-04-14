#include "worker.h"
#ifndef A_H
#define A_H

class Accountant : public Worker {
private:
	double salary;
public:
	Accountant(int id, char* name, double salary);
	double calcSalary(double bonus) final override;
	void print() final override;
};

#endif
