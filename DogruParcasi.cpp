#include "DogruParcasi.h"
#include <cmath>

DogruParcasi::DogruParcasi(const Nokta& nokta1, const Nokta& nokta2) : nokta1(nokta1), nokta2(nokta2) {}

DogruParcasi::DogruParcasi(const DogruParcasi& dogruParcasi) : nokta1(dogruParcasi.nokta1), nokta2(dogruParcasi.nokta2) {}

DogruParcasi::DogruParcasi(const Nokta& ortaNokta, double uzunluk, double egim) {
    double x1 = ortaNokta.getX() - uzunluk / 2;
    double y1 = ortaNokta.getY() - uzunluk / 2 * egim;
    double x2 = ortaNokta.getX() + uzunluk / 2;
    double y2 = ortaNokta.getY() + uzunluk / 2 * egim;
    setP1(x1, y1);
    setP2(x2, y2);
}

Nokta DogruParcasi::getP1() const {
    return nokta1;
}

Nokta DogruParcasi::getP2() const {
    return nokta2;
}

void DogruParcasi::setP1(const Nokta& nokta1) {
    this->nokta1 = nokta1;
}

void DogruParcasi::setP2(const Nokta& nokta2) {
    this->nokta2 = nokta2;
}

void DogruParcasi::setP1(double x, double y) {
    nokta1.set(x, y);
}

void DogruParcasi::setP2(double x, double y) {
    nokta2.set(x, y);
}

double DogruParcasi::uzunluk() const {
    return sqrt(pow(getP1().getX() - getP2().getX(), 2) + pow(getP1().getY() - getP2().getY(), 2));
}

Nokta DogruParcasi::kesisimNoktasi(const Nokta& nokta) const {
    double m1 = (getP1().getY() - getP2().getY()) / (getP1().getX() - getP2().getX());

    if (std::isinf(m1)) {
        double x = getP1().getX();
        double y = m1 * (x - getP1().getX()) + getP1().getY();
        return Nokta(x, y);
    }

    double m2 = -1.0 / m1;

    double x = (m1 * getP1().getX() - m2 * nokta.getX() + nokta.getY() - getP1().getY()) / (m1 - m2);
    double y = m1 * (x - getP1().getX()) + getP1().getY();

    return Nokta(x, y);
}

Nokta DogruParcasi::ortaNokta() const {
    double x = (getP1().getX() + getP2().getX()) / 2.0;
    double y = (getP1().getY() + getP2().getY()) / 2.0;
    return Nokta(x, y);
}

std::string DogruParcasi::toString() const {
    return getP1().toString() + " - " + getP2().toString();
}

void DogruParcasi::yazdir() const {
    std::cout << toString() << std::endl;
}
