#include <iostream>
#include <vector>
#include <algorithm>

#include "Model.h"
#include "Controller.h"
#include "CmdLineView.h"

using namespace std;

// model view controller
/*
vector<Dish> createDishesStore() {
    Orders order = Orders();
    Dish dog("Dog", 40, false, 1000, 1400);
    Dish cat("Cat", 20, false, 1000, 900);
    Dish duck("Duck", 15, false, 1200, 1300);
    order.dishes.push_back(dog);               // нужны ли здесь ссылки (linkOnDishes вместо dishes)?
    order.dishes.push_back(cat);
    order.dishes.push_back(duck);
    return order.dishes;
};
*/
// controller




// view:
void printMenu() {
    cout << "Выберете команду:\n1) Добавить блюдо к заказу\n2) Удалить блюдо из заказа\n3) Инфо о блюде\n4) Редактирование пользователя\n5) Добавить новое блюдо в МЕНЮ\n6) Удалить блюдо из МЕНЮ";
}

void processAddDishInMenu() {
    string name;
    unsigned short time;
    bool drink;
    unsigned short calorie;
    float price;
    bool correct = false;
    cin >> name;
    while (correct != true) {
        cin >> time; // эээ ну тут обработка ошибки некорректного ввода (типа данных) должна быть, но я хз как это сделать
    }
}

ostream &operator<< (ostream &os, Order order) {
//    os << order.dishes;
    return os;
}

void PrintMenu()
{
	cout << "..." << endl;
}

bool ProcessReaction(Controller &controller, CmdLineView &view)
{
	string s;
	std::getline(cin, s);

	std::remove_if(s.begin(), s.end(), [](char c) { return std::isspace(c); });

	if (s.empty())
		return false;

	if (s == "p")
		view.printDishesList();

	// call appropriate Controller method

	return true;
}

int main() {
//    cout << createDishesStore();

	Model model;
	Controller controller(model);
	CmdLineView view(model, cout);

	cout << "Welcome to cafe management!" << endl;
	do
		PrintMenu();
	while (ProcessReaction(controller, view));

	return 0;
}


// void printDishes(Orders &order) {
//     for (size_t i = 0; i != dishes.size(); ++i) {
//         order.totalPrice += dishes[i].price;
//         totalCalorie += dishes[i].calorie;
//         if (timeOrder < dishes[i].time) {
//             timeOrder = dishes[i].time;
//         };
//     };
// };

