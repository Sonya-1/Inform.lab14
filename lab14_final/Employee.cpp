#include <iostream> 
#include "worker.h"
#include "Employee.h"

Employee::Employee(int id, char* name, int copies, double percent, double price, char* title)
	: Worker(id, name)
{
	int i;
	this->title = new char[256]{ 0 };

	for (i = 0; title[i] != 0; i++) {
		this->title[i] = title[i];
	}

	this->copies = copies;
	this->percent = percent;
	this->price = price;
}

double Employee::calcSalary(double bonus) {
	return (percent * copies * price);
}

void Employee::print() {
	std::cout << "Sales Manager id: " << this->getId() << '\t' <<
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
	title = new char[256]{ 0 };
	for (size_t i = 0; i < 256; i++) title[i] = w.title[i];

}

Employee& Employee::operator=(const Employee& w) {
	if (&w == this) {
		return *this;
	}
	delete[] title;
	title = new char[256]{ 0 };
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
