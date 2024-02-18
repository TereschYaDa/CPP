#pragma once

#include <vector>
#include <map>
#include "Dish.h"
#include "Order.h"
#include "Customer.h"
#include "Menu.h"

class Model {
	Menu _currentMenu;
	Orders _activeOrders;

public:
	Model() {}
	const Orders & activeOrders() const { return _activeOrders; }
	const Menu & currentMenu() const { return _currentMenu; }

	void addOrder(const Order & order) {
		_activeOrders[order.id()] = order;
	}

	void removeOrder(const int id) {
		_activeOrders.erase(_activeOrders.find(id));
	}

	Order & returnOrder(const int id) {
		_activeOrders.find(id);
	}

	void addDish(const Dish & dish) {
		_currentMenu.addDish(dish);
	}

	void removeDish(const std::string & name) {
		_currentMenu.removeDish(name);
	}

	/*void serialize(std::ofstream& out) const {
		_currentMenu.serialize(out);
		out << _activeOrders.size() << std::endl;
		for (Orders::const_iterator cit = _activeOrders.begin(); cit != _activeOrders.end(); ++cit) {
			const Order& order = cit->second;
			order.serialize(out);
		}
	}

	void deserialize(std::ifstream& in) {
		_currentMenu.deserialize(in);
		int lenght;
		in >> lenght;
		for (int i = 0; i < lenght; ++i) {
			Order order;
			_activeOrders[order.id()] = order;
		}
	}*/
};
