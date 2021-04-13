#include <iostream> 
#include <string>
#include "worker.h"

Worker::Worker(int id, char* name) {
	int i;
	this->name = new char[256];

	for (i = 0; i < 256; i++) {
		this->name[i] = 0;
	}

	for (i = 0; name[i] != 0; i++) {
		this->name[i] = name[i];
	}

	this->id = id;
	this->next = NULL;
}

Worker::Worker() {
	int i;
	this->name = new char[256] ;
	
	for (i = 0; i < 256; i++) {
		this->name[i] = 0;
	}
	this->id = 0;
	this->next = NULL;
}

void Worker::setName(char* name) {
	int i;

	for (i = 0; i < 256; i++) {
		this->name[i] = 0;
	}
	for (i = 0; name[i] != 0; i++) {
		this->name[i] = name[i];
	}
}

char* Worker::getName() {
	return this->name;
}

int Worker::getId() {
	return this->id;
}

int Worker::calcSalary(int bonus) {
	return 0;
}

Worker::Worker(const Worker& w) {
	id = w.id;
	next = NULL;
	name = new char[256];
	for (int i = 0; i < 256; i++) {
		this->name[i] = 0;
	}
	for (size_t i = 0; i < 256; i++) name[i] = w.name[i];

}

Worker& Worker::operator=(const Worker& w) {
	if (&w == this) {
		return *this;
	}
	delete[] name;
	name = new char[256];
	for (int j = 0; j < 256; j++) {
		this->name[j] = 0;
	}
	for (int i = 0; i < 256; i++) {
		name[i] = w.name[i];
	}
	id = w.id;
	return *this;
}

Worker::~Worker() {
	delete[] this->name;
}

void Worker::print() {
	std::cout << this->id << '\t' << this->name;
}

Accountant::Accountant(int id, char* name, int salary) : Worker(id, name) {
	this->salary = salary;
}

int Accountant::calcSalary(int bonus) {
	return (salary + bonus);
}

void Accountant::print() {
	std::cout << "Accountant id: " << this->getId() << '\t' <<
		"name: " << this->getName() << '\t' <<
		"fixed salary: " << this->salary;
}

Employee::Employee(int id, char* name, int copies, int percent, int price, char* title)
	: Worker(id, name)
{
	int i;
	this->title = new char[256];

	for (i = 0; i < 256; i++) {
		this->title[i] = 0;
	}

	for (i = 0; title[i] != 0; i++) {
		this->title[i] = title[i];
	}

	this->copies = copies;
	this->percent = percent;
	this->price = price;
}

int Employee::calcSalary(int bonus) {
	return (percent * copies * price);
}

void Employee::print() {
	std::cout << "Sales Manager id: " << this->getId() << '\t' << '\t' <<
		"name: " << this->getName() << '\t' <<
		"copies sale: " << this->copies << '\t' <<
		"percent: " << this->percent << '\t' <<
		"price: " << this->price << '\t' <<
		"branch name: " << this->title;
}

Employee::Employee(const Employee& w) {
	copies = w.copies;
	percent = w.percent;
	price = w.price;
	title = new char[256];
	for (int i = 0; i < 256; i++) {
		this->title[i] = 0;
	}
	for (size_t i = 0; i < 256; i++) title[i] = w.title[i];

}

Employee& Employee::operator=(const Employee& w) {
	if (&w == this) {
		return *this;
	}
	delete[] title;
	title = new char[256];
	for (int j = 0; j < 256; j++) {
		this->title[j] = 0;
	}
	for (int i = 0; i < 256; i++) {
		title[i] = w.title[i];
	}
	copies = w.copies;
	percent = w.percent;
	price = w.price;
	return *this;
}

Employee::~Employee() {
	delete[] this->title;
}

Programmer::Programmer(int id, char* name, int rate, int experience, double skill, bool prize)
	: Worker(id, name)
{
	this->rate = rate;
	this->experience = experience;
	this->skill = skill;
	this->prize = prize;
}

void Programmer::print() {
	std::cout << "Programmer id: " << this->getId() <<  '\t' << 
		"name: " << this->getName() << '\t' <<
		"rate: " << this->rate << '\t' <<
		"experience: " << this->experience << '\t' <<
		"skill: " << this->skill << '\t' <<
		"prize: " << this->prize;
}

int Programmer::calcSalary(int bonus) {
	int p;
	if (prize == true) { p = bonus; }
	else { p = 0; }
	return (rate + (int)(skill * 1000) + p);
}

void checkInput() {
	if (std::cin.fail()) {
		std::cout << "Incorrect value\n";
		std::exit(1);
	}
}

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

WorkerBase::WorkerBase(Worker* head, int max_id, int bonus) {
	this->head = head;
	this->max_id = max_id;
	this->bonus = bonus;
}

WorkerBase::WorkerBase() {
	this->head = NULL;
	this->max_id = 0;
	this->bonus = 0;
}

void WorkerBase::set_bonus(int bonus) {
	this->bonus = bonus;
}

int WorkerBase::get_bonus() {
	return this->bonus;
}

Accountant* WorkerBase::addAcc(char* name, int salary) {
	int id = this->next_id();
	Accountant* acc = new Accountant(id, name, salary);
	this->addNode(acc);
	return acc;
}

void  WorkerBase::fillAcc() {
	char* name = new char[256];
	int salary;
	std::cout << "name: ";
	std::cin >> name;
	checkInput();
	std::cout << "salary: ";
	std::cin >> salary;
	checkInput();
	std::cout << "\n";
	this->addAcc(name, salary);
}

Employee* WorkerBase::addEm(char* name, int copies, int percent, int price, char* title) {
	int id = this->next_id();
	Employee* em = new Employee(id, name, copies, percent, price, title);
	this->addNode(em);
	return em;
}

void WorkerBase::fillEm(){
	char* name = new char[256];
	int copies, percent, price;
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
	if (percent > 100) {
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

Programmer* WorkerBase::addProgr(char* name, int rate, int experience, double skill, bool prize) {
	int id = this->next_id();
	Programmer* prog = new Programmer(id, name, rate, experience, skill, prize);
	this->addNode(prog);
	return prog;
}

void  WorkerBase::fillProgr() {
	char* name = new char[256];
	int rate, experience;
	double skill;
	bool prize;

	std::cout << "name: ";
	std::cin >> name;
	checkInput();
	std::cout << "rate: ";
	std::cin >> rate;
	checkInput();
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
		total += node->calcSalary(this->bonus);
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

void menu(WorkerBase* wb) {
	int bonus = 0, j = 0;
	bool useBonus = false;

	while (true) {
		std::cout << "[1] to add an Accountant\n" <<
			"[2] to add a Sales Manager\n" <<
			"[3] to add a Programmer\n" <<
			"[0] to print all staff and exit: ";
		std::cin >> j;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (j == 0) {
			break;
		}
		else if (j == 1) {
			useBonus = true;
			wb->fillAcc();
		}
		else if (j == 2) {
			wb->fillEm();
		}
		else if (j == 3) {
			useBonus = true;
			wb->fillProgr();
		}
	}
	if (useBonus) {
		std::cout << "\n";
		std::cout << "Input bonus: ";
		std::cin >> bonus;
		if (bonus < 0 || std::cin.fail()) {
			std::cout << "Incorrect value\n";
			std::exit(1);
		}
		std::cout << "\n";

		wb->set_bonus(bonus);
	}
}