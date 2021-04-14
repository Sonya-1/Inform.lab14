#include <iostream> 
#include "worker.h"
#include "WorkerBase.h"
#include "Accountant.h"
#include "Programmer.h"
#include "Employee.h"
#include "input.h"

int WorkerBase::next_id() {
	return ++this->max_id;
}

Worker* WorkerBase::getLast() {
	Worker* node = this->head;

	for (;;) {
		if (node->next == NULL) {
			return node;
		}
		node = node->next;
	}
}

int WorkerBase::addNode(Worker* node) {
	int id = this->max_id;

	if (this->head == NULL) {
		this->head = node;
	}
	else {
		this->getLast()->next = node;
	}
	return id;
}

void WorkerBase::delNode(Worker* node) {
	Worker* prevNode = this->head;

	if (this->head == node) {
		this->head = node->next;
		delete node;
		return;
	}

	for (; prevNode != NULL; ) {
		if (prevNode->next == node) {
			prevNode->next = node->next;
			delete node;
			break;
		}
		prevNode = prevNode->next;
	}
}


Worker* WorkerBase::find(int id) {
	Worker* node = this->head;

	for (; node != NULL;) {
		if (node->getId() == id) {
			return node;
		}
		node = node->next;
	}
	return NULL;
}

void WorkerBase::erase() {
	Worker* node = this->head;
	Worker* next;

	for (; node != NULL;) {
		next = node->next;
		delete node;
		node = next;
	}
}

WorkerBase::WorkerBase(Worker* head, int max_id, double bonus) {
	this->head = head;
	this->max_id = max_id;
	this->bonus = bonus;
}

WorkerBase::WorkerBase() {
	this->head = NULL;
	this->max_id = 0;
	this->bonus = 0;
}

void WorkerBase::set_bonus(double bonus) {
	this->bonus = bonus;
}

double WorkerBase::get_bonus() {
	return this->bonus;
}

Accountant* WorkerBase::addAcc(char* name, double salary) {
	int id = this->next_id();
	Accountant* acc = new Accountant(id, name, salary);
	this->addNode(acc);
	return acc;
}

void  WorkerBase::fillAcc() {
	char* name = new char[256];
	double salary;
	std::cout << "name: ";
	std::cin >> name;
	checkInput();
	std::cout << "salary: ";
	std::cin >> salary;
	checkInput();
	std::cout << "\n";
	this->addAcc(name, salary);
}

Employee* WorkerBase::addEm(char* name, int copies, double percent, double price, char* title) {
	int id = this->next_id();
	Employee* em = new Employee(id, name, copies, percent, price, title);
	this->addNode(em);
	return em;
}

void WorkerBase::fillEm() {
	char* name = new char[256];
	int copies;
	double percent, price;
	char* title = new char[256];

	std::cout << "name: ";
	std::cin >> name;
	checkInput();
	std::cout << "copies: ";
	std::cin >> copies;
	checkInput();
	std::cout << "percent: ";
	std::cin >> percent;
	checkInput();
	if (percent > 100 || percent < 0) {
		std::cout << "Incorrect percent\n";
		std::exit(1);
	}
	std::cout << "price: ";
	std::cin >> price;
	checkInput();
	std::cout << "title: ";
	std::cin >> title;
	checkInput();
	std::cout << "\n";
	this->addEm(name, copies, percent, price, title);
}

Programmer* WorkerBase::addProgr(char* name, double rate, int experience, double skill, bool prize) {
	int id = this->next_id();
	Programmer* prog = new Programmer(id, name, rate, experience, skill, prize);
	this->addNode(prog);
	return prog;
}

void  WorkerBase::fillProgr() {
	char* name = new char[256];
	int experience;
	double skill, rate;
	bool prize;

	std::cout << "name: ";
	std::cin >> name;
	checkInput();
	std::cout << "rate: ";
	std::cin >> rate;
	checkInput();
	if (rate < 0 || rate > 1) {
		std::cout << "Incorrect rate\n";
		std::exit(1);
	}
	std::cout << "experience: ";
	std::cin >> experience;
	checkInput();
	std::cout << "skill (from 1 to 2): ";
	std::cin >> skill;
	checkInput();
	if (skill < 1 || skill > 2) {
		std::cout << "Incorrect skill\n";
		std::exit(1);
	}
	std::cout << "prize (bool): ";
	std::cin >> prize;
	checkInput();
	std::cout << "\n";
	this->addProgr(name, rate, experience, skill, prize);
}

int WorkerBase::calcTotalSalary() {
	Worker* node = this->head;
	int total = 0;

	for (; node != NULL;) {
		total += (int)node->calcSalary(this->bonus);
		node = node->next;
	}
	return total;
}

void WorkerBase::print() {
	Worker* n = this->head;
	for (; n != NULL;) {

		n->print();
		std::cout << '\n';
		n = n->next;
	}
}
