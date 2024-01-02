#include "Nokta.h"
#include <iostream>
#include <string>

Nokta::Nokta() : x(0), y(0) {}

Nokta::Nokta(double x) : x(x), y(x) {}

Nokta::Nokta(double x, double y) : x(x), y(y) {}

Nokta::Nokta(const Nokta& nokta) : x(nokta.x), y(nokta.y) {}

Nokta::Nokta(const Nokta& nokta, double ofset_x, double ofset_y) : x(nokta.x + ofset_x), y(nokta.y + ofset_y) {}

double Nokta::getX() const {
    return x;
}

double Nokta::getY() const {
    return y;
}

void Nokta::setX(double x) {
    this->x = x;
}

void Nokta::setY(double y) {
    this->y = y;
}

void Nokta::set(double x, double y) {
    setX(x);
    setY(y);
}

std::string Nokta::toString() const {
    return "(" + std::to_string(getX()) + ", " + std::to_string(getY()) + ")";
}

void Nokta::yazdir() const {
    std::cout << toString() << std::endl;
}
