#pragma once

#include <vector>

#include "Dish.h"
#include "Order.h"
#include "Customer.h"
#include "Menu.h"

class Model
{
	std::vector<Dish> knownDishes;
	Menu currentMenu;
	std::vector<Order> activeOrders;
	std::vector<Customer> knownCustomers;

public:
	Model() { knownDishes.push_back(Dish("Cat", 40, false, 1000, 900)); }
	// some kind of an interface
	std::vector<Order> & ActiveOrders() { return activeOrders; } // че это значит
	const Dishes & KnownDishes() const { return knownDishes; }
};
