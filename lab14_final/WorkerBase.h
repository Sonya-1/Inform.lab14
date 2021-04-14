#include "Accountant.h"
#include "Programmer.h"
#include "Employee.h"

#ifndef WB_H
#define WB_H

class WorkerBase {
private:
	Worker* head;
	int max_id;
	double bonus;
public:
	int addNode(Worker* node);
	void delNode(Worker* node);
	int next_id();
	Worker* getLast();
	WorkerBase(Worker* head, int max_id, double bonus);
	WorkerBase();
	void set_bonus(double bonus);
	double get_bonus();
	Accountant* addAcc(char* name, double salary);
	void fillAcc();
	Programmer* addProgr(char* name, double rate, int experience, double skill, bool prize);
	void fillProgr();
	Employee* addEm(char* name, int copies, double percent, double price, char* title);
	void fillEm();
	int calcTotalSalary();
	Worker* find(int id);
	void erase();
	void print();
};
#endif
