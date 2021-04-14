#include <iostream>
#include "input.h"
#include "WorkerBase.h"

void menu(WorkerBase* wb) {
	double bonus = 0;
	int j = 0;
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

void checkInput() {
	if (std::cin.fail()) {
		std::cout << "Incorrect value\n";
		std::exit(1);
	}
}