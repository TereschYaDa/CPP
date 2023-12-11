#pragma once

#include <string>

class Dish {
    private:
    std::string nameOfDish;
    unsigned short time;
    bool drink;
    unsigned short calorie;
    float price;

    public:
    Dish(std::string name, unsigned short time, bool drink, unsigned short calorie, float price) {
        nameOfDish = name;
        this->time = time;
        this->drink = drink;
        this->calorie = calorie;
        this->price = price;
    }
    std::string getNameOfDishe() const {
        return nameOfDish;
    }
    unsigned short getTime() {
        return time;
    }
    bool getDrink() {
        return drink;
    }
    unsigned short getCalorie() {
        return calorie;
    }
    float getPrice() {
        return price;
    }
};

typedef std::vector<Dish> Dishes;
