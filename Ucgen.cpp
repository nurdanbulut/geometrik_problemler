#include "Ucgen.h"
#include <cmath>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

Ucgen::Ucgen(const Nokta& nokta1, const Nokta& nokta2, const Nokta& nokta3) : nokta1(nokta1), nokta2(nokta2), nokta3(nokta3) {}

Nokta Ucgen::getNokta1() const {
    return nokta1;
}

Nokta Ucgen::getNokta2() const {
    return nokta2;
}

Nokta Ucgen::getNokta3() const {
    return nokta3;
}

void Ucgen::setNokta1(const Nokta& nokta1) {
    this->nokta1 = nokta1;
}

void Ucgen::setNokta2(const Nokta& nokta2) {
    this->nokta2 = nokta2;
}

void Ucgen::setNokta3(const Nokta& nokta3) {
    this->nokta3 = nokta3;
}

void Ucgen::setNokta1(double x, double y) {
    nokta1.set(x, y);
}

void Ucgen::setNokta2(double x, double y) {
    nokta2.set(x, y);
}

void Ucgen::setNokta3(double x, double y) {
    nokta3.set(x, y);
}

std::string Ucgen::toString() const {
    return "��gen: " + getNokta1().toString() + " - " + getNokta2().toString() + " - " + getNokta3().toString();
}

double Ucgen::alan() const {
    double a = DogruParcasi(nokta1, nokta2).uzunluk();
    double b = DogruParcasi(nokta1, nokta3).uzunluk();
    double c = DogruParcasi(nokta2, nokta3).uzunluk();

    double yari_cevre = (a + b + c) / 2.0;

    return sqrt(yari_cevre * (yari_cevre - a) * (yari_cevre - b) * (yari_cevre - c));
}

double Ucgen::cevre() const {
    double a = DogruParcasi(nokta1, nokta2).uzunluk();
    double b = DogruParcasi(nokta1, nokta3).uzunluk();
    double c = DogruParcasi(nokta2, nokta3).uzunluk();

    return a + b + c;
}

double* Ucgen::acilar() const {
    double a = DogruParcasi(nokta1, nokta2).uzunluk();
    double b = DogruParcasi(nokta1, nokta3).uzunluk();
    double c = DogruParcasi(nokta2, nokta3).uzunluk();

    double A_radyan = acos((b * b + c * c - a * a) / (2 * b * c));
    double B_radyan = acos((c * c + a * a - b * b) / (2 * c * a));
    double C_radyan = acos((a * a + b * b - c * c) / (2 * a * b));

    double A_derece = A_radyan * 180 / M_PI;
    double B_derece = B_radyan * 180 / M_PI;
    double C_derece = C_radyan * 180 / M_PI;

    double* acilar = new double[3];
    acilar[0] = A_derece;
    acilar[1] = B_derece;
    acilar[2] = C_derece;

    return acilar;
}