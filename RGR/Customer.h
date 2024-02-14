#pragma once

#include <string>

class Customer
{
	std::string _name;
	int _totalSpending;

public:
	Customer(std::string customerName) : _name(customerName), _totalSpending(0) {}
};
