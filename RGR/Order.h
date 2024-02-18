#pragma once

#include <map>

#include "Dish.h"

class Order {
    Dishes _dishes;
    int _id;

    public:
    Order() : _id(-1) {}
    Order(int id) : _id(id) {}

    size_t quantity() const {
        return _dishes.size();
    }

    int id() const {
        return _id;
    }

    int totalPrice() const {
        int totalPrice = 0;
        for (Dishes::const_iterator cit = _dishes.begin(); cit != _dishes.end(); ++cit) {
            totalPrice += cit->price();
        }

        return totalPrice;
    }

    int totalCalorie() const {
        int totalCalorie = 0;
        for (Dishes::const_iterator cit = _dishes.begin(); cit != _dishes.end(); ++cit) {
            totalCalorie += cit->calorie();
        }
        
        return totalCalorie;
    }

    int timeOrder() const {
        int maxCookingTime = 0;
        for (Dishes::const_iterator cit = _dishes.begin(); cit != _dishes.end(); ++cit) {          
            maxCookingTime = (maxCookingTime <= cit->cookingTime()) ? cit->cookingTime() : maxCookingTime;
        }

        return maxCookingTime; 
    }

    void addDish(const Dish &dish) {
        _dishes.push_back(dish);
    }

    const Dishes& dishes() const {
        return _dishes;
    }
};

typedef std::map<int, Order> Orders;
