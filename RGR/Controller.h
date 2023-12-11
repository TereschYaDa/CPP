#pragma once

#include "Model.h"

class Controller
{
	Model &model;

public:
	Controller(Model &m) : model(m) {}

	bool addDishToOrder() { return false; }
	// ...
};
