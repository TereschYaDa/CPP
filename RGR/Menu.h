#pragma once

#include <map>

#include "Dish.h"

class Menu
{
	std::map<std::string, Dish> dishes;
	time_t actualSince;

public:
	Menu() : actualSince(0) {}
};
