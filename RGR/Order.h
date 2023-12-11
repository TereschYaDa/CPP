#pragma once

#include <vector>

#include "Dish.h"

class Order {
    private:
    Dishes dishes;
    float totalPrice;
    unsigned short totalCalorie;
    unsigned short timeOrder;
    unsigned short quantityOfDishes;
    short i;
//    friend vector<Dish> createDishesStore();
//    friend ostream &operator<< (ostream &os, Orders order); // шаманство с выводом
    void invalidateIterator() {
        i = -1;
    }
    
    public:
    Order(){
        totalPrice = 0;
        totalCalorie = 0;
        timeOrder = 0;
        quantityOfDishes = 0;
        // date 
    }
    unsigned short getQuantity() {
        return dishes.size();
    }
    float getTotalPrice() {
        return totalPrice;
    }
    unsigned short getTotalCalorie() {
        return totalCalorie;
    }
    unsigned short getTimeOrder() {
        return timeOrder;
    }
    unsigned short getQuantityOfDishes() {
        return quantityOfDishes;
    }
    Dish getFirstElem() {
        if (!dishes.empty()) {
            i = 0;
            return dishes[0];
        }
        else {
            // cout << "В списке заказа ничего нет.";
		// either use smart pointer instead of object or throw exception
        }
    }
    Dish getNextElem() {
        if (i != -1 && i < getQuantity() - 1) {
            i += 1;
            return dishes[i];
        }
    }
    void addDishInMenu(std::string name, unsigned short time, bool drink, unsigned short calorie, float price) {
        Dish newDish(name, time, drink, calorie, price);
        dishes.push_back(newDish);
        invalidateIterator(); // так вообще можно?
    }
};
