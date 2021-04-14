#include <iostream> 
#include "worker.h"
#include "Programmer.h"

Programmer::Programmer(int id, char* name, double rate, int experience, double skill, bool prize)
	: Worker(id, name)
{
	this->rate = rate;
	this->experience = experience;
	this->skill = skill;
	this->prize = prize;
}

void Programmer::print() {
	std::cout << "Programmer id: " << this->getId() << '\t' <<
		"name: " << this->getName() << '\t' <<
		"rate: " << this->rate << '\t' <<
		"experience: " << this->experience << '\t' <<
		"skill: " << this->skill << '\t' <<
		"prize: " << this->prize;
}

double Programmer::calcSalary(double bonus) {
	int p;
	if (prize == true) { p = bonus; }
	else { p = 0; }
	return ((int)rate + (int)(skill * 1000) + p);
}
