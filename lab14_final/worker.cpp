#include <iostream> 
#include <string>
#include "worker.h"

Worker::Worker(int id, char* name) {
	int i;
	this->name = new char[256] { 0 };
	
	for (i = 0; name[i] != 0; i++) {
		this->name[i] = name[i];
	}

	this->id = id;
	this->next = NULL;
}

Worker::Worker() {
	this->name = new char[256] { 0 };
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

double Worker::calcSalary(double bonus) {
	return 0;
}

Worker::Worker(const Worker& w) {
	id = w.id;
	next = NULL;
	name = new char[256]{ 0 };
	for (size_t i = 0; i < 256; i++) name[i] = w.name[i];
}

Worker& Worker::operator=(const Worker& w) {
	if (&w == this) {
		return *this;
	}
	delete[] name;
	name = new char[256]{ 0 };
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
