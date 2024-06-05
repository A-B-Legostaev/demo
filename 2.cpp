#include <iostream>
using namespace std;

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
* @brief точка входа в программу
* @return 0
*/
int main() {
    cout << "Программа для расчета пути, пройденного лодкой по течению реки." << endl;

    cout << "Введите скорость лодки в стоячей воде (км/ч)=";
    double boatSpeed = getValue();
    checkPositive(boatSpeed);
    cout << "Введите скорость течения реки (км/ч)=";
    double currentSpeed = getValue();
    checkPositive(currentSpeed);
    cout << "Введите время движения (часы)=";
    double totalTime = getValue();
    checkPositive(totalTime);
    double totalSpeed = boatSpeed + currentSpeed;
    double distance = totalSpeed * totalTime;
    cout << endl << "Путь, пройденный лодкой по течению реки: " << distance << " км";
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
    if (cin.fail()) {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}