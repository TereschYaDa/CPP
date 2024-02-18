#include <iostream>
#include <vector>
#include <algorithm>

#include "Model.h"
#include "Dish.h"
#include "Controller.h"
#include "CmdLineView.h"

using namespace std;

string readInput()
{
	string s;
	do {
		getline(cin, s);
		s.erase(remove_if(s.begin(), s.end(), [](char c) { return isspace(c); }), s.end());
	} while (s.empty());

	return s;
}

int readInt() {
	int integer;
	while (true) {
		string s = readInput();
		try {
			integer = stoi(s);
			break;
		}
		catch (invalid_argument& e) { cout << "Incorrect input. Try again:" << endl; }
	}

	return integer;
}

string readDishName() {
	cout << "Enter dish name:" << endl;

	return readInput();
}

int readOrderId() {
	int id;
	cout << "Enter order id:" << endl;
	id = readInt();

	return id;
}

Dish readDish() {
	std::string name;
	int calorie, price, time;
	cout << "Enter dish details (name, time, calorie, price):" << endl;
	name = readInput();
	calorie = readInt();
	price = readInt();
	time = readInt();

	return Dish(name, time, calorie, price);
}

Order readOrder() {
	int id;
	cout << "Enter order id:" << endl;
	id = readInt();

	Order newOrder(id);
	string answ;
	do {
		cout << "Add dish? (y/n)" << endl;
		answ = readInput();
		if (answ == "y" || answ == "Y") {
			Dish newDish = readDish();
			newOrder.addDish(newDish);
		}
	} while (answ != "n" && answ != "N");

	return newOrder;
}

void printMenu()
{
	cout << "Select an action:" << endl;
	cout << "1) View menu" << endl;
	cout << "2) View dish details" << endl;
	cout << "3) View orders" << endl;
	cout << "4) Add order" << endl;
	cout << "5) Add dish to menu" << endl;
	cout << "6) Edit dish details" << endl;
	cout << "7) Remove dish from menu" << endl;
	cout << "8) Remove order" << endl;
	cout << "9) Exit program" << endl;
}

bool processReaction(Controller &controller, CmdLineView &view)
{
	try {
		switch (stoi(readInput())) {
		case 1:
			view.printMenu();
			break;
		case 2:
			while (!view.printDish(readDishName())) ;
			break;
		case 3:
			view.printOrders();
			break;
		case 4:
			controller.addOrder(readOrder());
			break;
		case 5:
			controller.addDishToMenu(readDish());
			break;
		case 6:
			view.printDish(readDishName());
			cout << "Please enter corrected dish details" << endl;
			controller.replaceDishInMenu(readDish());
			break;
		case 7:
			controller.removeDishFromMenu(readDishName());
			break;
		case 8:
			controller.removeOrder(readOrderId());
			break;
		case 9:
			return false;
		}
	} catch (invalid_argument & e) {
		return true;
	}

	return true;
}

int main() {
	Model model;
	Controller controller(model);
	CmdLineView view(model, cout);

	cout << "Welcome to cafe!" << endl;
	do {
		printMenu();
	} while (processReaction(controller, view));

	return 0;
}
