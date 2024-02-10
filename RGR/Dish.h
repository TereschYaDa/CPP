#pragma once

#include <string>

class Dish {
    std::string nameOfDish;
    int cookingTime;
    bool drink;
    int calorieOfDish;
    float priceOfDish; // warning

    public:
    Dish(std::string name, int time, bool drink, int calorie, float price) {
        nameOfDish = name;
        cookingTime = time;
        this->drink = drink;
        calorieOfDish = calorie;
        priceOfDish = price;
    }
    std::string getNameOfDish() const {
        return nameOfDish;
    }
    int getTime() const {
        return cookingTime;
    }
    bool getDrink() const {
        return drink;
    }
    int getCalorie() const {
        return calorieOfDish;
    }
    float getPrice() const {
        return priceOfDish;
    }
};

typedef std::vector<Dish> Dishes;
