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
		s.erase(remove_if(s.begin(), s.end(), [](char c) { return std::isspace(c); }), s.end());
	} while (s.empty());

	return s;
}

string readDishName() {
	cout << "Enter dish name:" << endl;

	return readInput();
}

int readOrderId() {
	int id;
	cout << "Enter order id:" << endl;
	while (true) {
		string s = readInput();
		try {
			id = stoi(s);
			break;
		}
		catch (invalid_argument& e) {}
	}

	return id;
}

Dish readDish() { // наверное сделать отдельную функцию проверки на число
	std::string name;
	int calorie, price, time;
	cout << "Enter dish details (name, time, calorie, price):" << endl;
	name = readInput();
	while (true) {
		string s = readInput();
		try {
			calorie = stoi(s);
			break;
		}
		catch (invalid_argument& e) {}
	}
	while (true) {
		string s = readInput();
		try {
			price = stoi(s);
			break;
		}
		catch (invalid_argument& e) {}
	}
	
	while (true) {
		string s = readInput();
		try {
			time = stoi(s);
			break;
		}
		catch (invalid_argument& e) {}
	}

	return Dish(name, time, calorie, price);
}

Order readOrder() {
	bool flag = true;
	int id;
	cout << "Enter order id:" << endl;
	while (true) {
		string s = readInput();
		try {
			id = stoi(s);
			break;
		}
		catch (invalid_argument& e) {}
	}

	Order newOrder = Order(id);
	while (flag) {
		cout << "Add dish? (y/n)";
		string answ = readInput();
		if (answ == "y" || answ == "Y") {
			Dish newDish = readDish();
			newOrder.addDish(newDish); // тут с ссылками че как мудрить?
		}
		else if (answ == "n" || answ == "N") {
			flag = false;
		}
	}

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

bool processReaction(Controller &controller, CmdLineView &view) // исключение для stoi
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
	} catch (invalid_argument & e) { // почитать че такое try....
		return true;
	}
		/*view.printDishesList();*/

	// call appropriate Controller method

	return true;
}

int main() {
//    cout << createDishesStore();

	Model model;
	Controller controller(model);
	CmdLineView view(model, cout);


	cout << "Welcome to cafe!" << endl;
	do
		printMenu();
	while (processReaction(controller, view));

	return 0;
}
