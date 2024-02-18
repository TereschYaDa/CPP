#pragma once

#include <iostream>

#include "Model.h"

class CmdLineView
{
	const Model & _model;
	std::ostream& _console;

public:
	CmdLineView(const Model& m, std::ostream& out) : _model(m), _console(out) {}

	void printMenu() const {
		_console << "Menu:" << std::endl;
		const Menu& menu = _model.currentMenu();
		const DishesMap& dishes = menu.allDishes();

		for (DishesMap::const_iterator cit = dishes.begin(); cit != dishes.end(); ++cit) {
			_console << cit->first << "\t" << cit->second.price() / 100 << "," << cit->second.price() % 100 << std::endl;
		}
	}

	bool printDish(std::string name) const {
		const Menu& menu = _model.currentMenu();
		const DishesMap& dishes = menu.allDishes();
		DishesMap::const_iterator cit = dishes.find(name);

		if (cit == dishes.end()) {
			_console << "unknown dish name" << std::endl;

			return false;
		}
		const Dish& dish = cit->second;
		printDish(dish);

		return true;
	}

	void printOrders() const {
		_console << "Orders:" << std::endl;
		const Orders& orders = _model.activeOrders();

		for (Orders::const_iterator cit = orders.begin(); cit != orders.end(); ++cit) {
			const Order& order = cit->second;
			printOrder(order);
		
		}
	}

private:
	void printOrder(const Order& order) const
	{
		_console << order.id() << "\t" << order.timeOrder() << "\t" << order.totalCalorie() << "\t" << order.totalPrice() / 100 << "," << order.totalPrice() % 100 << std::endl;
		_console << "Dishes list:" << std::endl;

		for (Dishes::const_iterator cit = order.dishes().begin(); cit != order.dishes().end(); ++cit) {
			printDish(*cit);
		}
	}

	void printDish(const Dish& dish) const
	{
		_console << dish.name() << "\t" << dish.cookingTime() << "\t" << dish.calorie() << "\t" << dish.price() / 100 << "," << dish.price() % 100 << std::endl;
	}
};
