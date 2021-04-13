#ifndef A_H
#define A_H

class Worker {
private:
	char* name;
	int id;
public:
	Worker* next;
	Worker();
	Worker(int id, char* name);
	void setName(char* name);
	int getId();
	char* getName();
	virtual int calcSalary(int bonus);
	virtual void print();
	Worker(const Worker& w);
	Worker& operator=(const Worker& w);
	~Worker();
};

class Accountant : public Worker {
private:
	int salary;
public:
	Accountant(int id, char* name, int salary);
	int calcSalary(int bonus);
	void print();
};

class Employee : public Worker {
private:
	int copies;
	int percent;
	int price;
	char* title;
public:
	Employee(int id, char* name, int copies, int percent, int price, char* title);
	int calcSalary(int bonus);
	void print();
	Employee(const Employee& w);
	Employee& operator=(const Employee& w);
	~Employee();
};

class Programmer : public Worker {
private:
	int rate;
	int experience;
	double skill;
	bool prize;

public:
	Programmer(int id, char* name, int rate, int experience, double skill, bool prize);
	void print();
	int calcSalary(int bonus);
};

class WorkerBase {
private: 
	Worker* head;
	int max_id;
	int bonus;
public:
	int addNode(Worker* node);
	void delNode(Worker* node);
	int next_id();
	Worker* getLast();
	WorkerBase(Worker* head, int max_id, int bonus);
	WorkerBase();
	void set_bonus(int bonus);
	int get_bonus();
	Accountant* addAcc(char* name, int salary);
	void fillAcc();
	Programmer* addProgr(char* name, int rate, int experience, double skill, bool prize);
	void fillProgr();
	Employee* addEm(char* name, int copies, int percent, int price, char* title);
	void fillEm();
	int calcTotalSalary();
	Worker* find(int id);
	void erase();
	void print();
};
void menu(WorkerBase* wb);

#endif