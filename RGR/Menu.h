#pragma once

#include <map>

#include "Dish.h"

class Menu
{
	DishesMap _dishes;

public:
	Menu() { addDish(Dish("cat", 100, 10000, 1234)); }

	void addDish(const Dish& dish) {
		_dishes.insert(DishesMap::value_type(dish.name(), dish)); 
	}

	void removeDish(const std::string & name) {
		_dishes.erase(_dishes.find(name));
	}

	int quantity() const {
		return _dishes.size();
	}

	const DishesMap & allDishes() const {
		return _dishes;
	}
};
