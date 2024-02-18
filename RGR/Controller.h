#pragma once
#include <iostream>
#include <fstream>
#include "Model.h"

class Controller
{
	Model &_model;

public:
	Controller(Model &m) : _model(m) {}

	bool addDishToOrder() { return false; }
	
	void addOrder(const Order & order) {
		_model.addOrder(order);
	}

	void addDishToMenu(const Dish & newDish) {
		_model.addDish(newDish);
	}

	void replaceDishInMenu(const Dish & dish) {
		_model.addDish(dish); // test. []-?
	}

	void removeDishFromMenu(const std::string & name) {
		_model.removeDish(name);
	}

	void removeOrder(const int id) {
		_model.removeOrder(id);
	}

	/*void saveToFile(std::string fileName){
		std::ofstream out;
		out.open(fileName);
		if (out.is_open()) {
			_model.serialize(out);
			out.close();
		}
	}

	void loadFromFile(std::string fileName) {
		std::ifstream in(fileName);
		if (in.is_open()) {
			_model.deserialize(in);
		}
		in.close();
	}*/
};
