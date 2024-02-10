#pragma once

#include <vector>

#include "Dish.h"

class Order {
    Dishes dishes;
    float orderPrice; // warning
    int orderTotalCalorie;
    int orderCookingTime;
    int quantityOfDishes;
    int i;

    void invalidateIterator() {
        i = -1;
    }
    
    public:
    Order(): orderPrice(0), orderCookingTime(0), orderTotalCalorie(0), quantityOfDishes(0){}

    int getQuantity() const {
        return dishes.size();
    }
    float getTotalPrice() const {
        return orderPrice;
    }
    int getTotalCalorie() const {
        return orderTotalCalorie;
    }
    int getTimeOrder() const {
        return orderCookingTime;
    }
    int getQuantityOfDishes() const {
        return quantityOfDishes;
    }
    Dish getFirstElem() {
        if (!dishes.empty()) {
            i = 0;
            return dishes[0];
        }
        else {
		// either use smart pointer instead of object or throw exception
        }
    }
    Dish getNextElem() {
        if (i != -1 && i < getQuantity() - 1) {
            i += 1;
            return dishes[i];
        }
    }
    void addDishInMenu(std::string name, int time, bool drink, int calorie, float price) { // warning
        Dish newDish(name, time, drink, calorie, price);
        dishes.push_back(newDish);
        invalidateIterator();
    }
};
