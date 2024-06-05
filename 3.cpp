#include <iostream>
#include <cmath>
using namespace std;

/**
* @brief Проверяет, можно ли разместить два дома на участке
* @param a Длина участка
* @param b Ширина участка
* @param p Длина первого дома
* @param q Ширина первого дома
* @param r Длина второго дома
* @param s Ширина второго дома
* @return true, если возможно разместить оба дома, иначе false
*/
bool canPlaceHouses(const double a, const double b, const double p, const double q, const double r, const double s) {
    return ((a >= p + r && b >= max(q, s)) || (b >= q + s && a >= max(p, r)));
}

/**
* @brief Считывание параметра типа double из stdin
* @return результат считывания
*/
double getValue();

/**
* @brief Проверка на неотрицательное число
* @param value число 
*/
void checkPositive(const double value);

/**
* @brief Точка входа в программу
* @return 0
*/
int main() {
    double sides[6] = {0};
    cout << "Введите размеры участка и размеры двух домов: " << endl;
    cout << "Ширина участка=";
    sides[0] = getValue();
    cout << "Длина участка=";
    sides[1] = getValue();
    cout << "Ширина 1 дома=";
    sides[2] = getValue();
    cout << "Длина 1 дома=";
    sides[3] = getValue();
    cout << "Ширина 2 дома=";
    sides[4] = getValue();
    cout << "Длина 2 дома=";
    sides[5] = getValue();

    for (size_t i = 0; i < 6; i++) {
        checkPositive(sides[i]);
    }

    if (!canPlaceHouses(sides[0], sides[1], sides[2], sides[3], sides[4], sides[5])) {
        cout << "Дома нельзя разместить на данном участке." << endl;
    } else {
        cout << "Дома можно разместить на данном участке." << endl;
    }
    return 0;
}

void checkPositive(const double value) {     
    if (value <= 0) {     
        cout << "value < 0" << endl;
        abort();
    }
}

double getValue() {
    double value;
    cin >> value;
    if (cin.fail() || value <= 0.0) {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}
