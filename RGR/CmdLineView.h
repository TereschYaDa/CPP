#pragma once

#include <iostream>

#include "Model.h"

class CmdLineView
{
	const Model &model;
	std::ostream &console;

public:
	CmdLineView(const Model &m, std::ostream &out) : model(m), console(out) {}

	void printDishesList()
	{
//		console << "pdl (" << model.KnownDishes().size() << ")" << std::endl;
		for (std::vector<Dish>::const_iterator it = model.KnownDishes().begin(); it != model.KnownDishes().end(); it++)
		{
//			console << "dish" << std::endl;
			console << it->getNameOfDish() << std::endl;
		}
	}
};
