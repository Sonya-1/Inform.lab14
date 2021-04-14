#ifndef W_H
#define W_H

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
	virtual double calcSalary(double bonus);
	virtual void print();
	Worker(const Worker& w);
	virtual Worker& operator=(const Worker& w);
	virtual ~Worker();
};

#endif