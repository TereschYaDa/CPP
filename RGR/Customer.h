#pragma once

#include <string>

class Customer
{
	std::string name;
	int totalSpending;
	time_t lastVisit;

public:
	Customer(std::string customerName) : name(customerName), totalSpending(0), lastVisit(0) {}
};
