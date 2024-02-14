#pragma once

#include <vector>
#include <map>
#include "Dish.h"
#include "Order.h"
#include "Customer.h"
#include "Menu.h"

class Model
{
	Menu _currentMenu;
	Orders _activeOrders;

public:
	Model() {}
	const Orders & activeOrders() const { return _activeOrders; }
	const Menu & currentMenu() const { return _currentMenu; }
	void addOrderInOrders(Order & order) {
		_activeOrders.insert(order); // error
	}
};
