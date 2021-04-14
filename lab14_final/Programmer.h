#include "worker.h"
#ifndef P_H
#define P_H

class Programmer : public Worker {
private:
	double rate;
	int experience;
	double skill;
	bool prize;

public:
	Programmer(int id, char* name, double rate, int experience, double skill, bool prize);
	void print() final override;
	double calcSalary(double bonus) final override;
};

#endif
