#pragma once

#include <map>

#include "Dish.h"

class Menu
{
	std::map<std::string, Dish> dishes; // почему меню это словарь?
	time_t actualSince; // что за actualSince и нафига здесь time_t

public:
	Menu() : actualSince(0) {}
};
