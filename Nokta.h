#pragma once
#ifndef NOKTA_H
#define NOKTA_H

#include <iostream>
#include <string>

class Nokta {
private:
    double x;
    double y;
public:
    Nokta();
    Nokta(double x);
    Nokta(double x, double y);
    Nokta(const Nokta& nokta);
    Nokta(const Nokta& nokta, double ofset_x, double ofset_y);

    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    void set(double x, double y);

    std::string toString() const;
    void yazdir() const;
};

#endif // NOKTA_H
