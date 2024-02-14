#pragma once
#include <iostream>
#include "Model.h"

class Controller
{
	Model &model;

public:
	Controller(Model &m) : model(m) {}

	bool addDishToOrder() { return false; }
	
	void addOrder(Order order) {
		model.activeOrders().;
		std::cout << "order is added" << std::endl;
	}

	void addDishToMenu(Dish newDish) {
		std::cout << "dish is added" << std::endl;
	}

	void replaceDishInMenu(Dish dish) {
		// удалить по имени старое, добавить новое?
		std::cout << "dish has been change" << std::endl;
	}

	void removeDishFromMenu(std::string name) {
		std::cout << "dish has been removed" << std::endl;
	}

	void removeOrder(int id) {
		std::cout << "order has been removed" << std::endl;
	}
};
