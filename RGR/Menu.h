#pragma once

#include <map>

#include "Dish.h"

class Menu
{
	std::map<std::string, Dish> dishes; // ������ ���� ��� �������?
	time_t actualSince; // ��� �� actualSince � ������ ����� time_t

public:
	Menu() : actualSince(0) {}
};
