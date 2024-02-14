#pragma once

#include <string>
#include <map>

class Dish {
    std::string _name;
    int _cookingTime;
    int _calorie;
    int _price; // price in kopeykas

    public:
    Dish(std::string name, int time, int calorie, int price) {
        _name = name;
        _cookingTime = time;
        _calorie = calorie;
        _price = price;
    }

    std::string name() const {
        return _name;
    }
    int cookingTime() const {
        return _cookingTime;
    }
    
    int calorie() const {
        return _calorie;
    }
    int price() const {
        return _price;
    }
};

typedef std::vector<Dish> Dishes;
typedef std::map<std::string, Dish> DishesMap;