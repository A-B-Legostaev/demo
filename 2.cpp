#include <iostream>
using namespace std;

/**
* @brief Считывание параметра типа double из stdin
* @return результат считывания
*/
double getValue();

/**
* @brief точка входа в программу
* @return 0
*/
int main() {
    cout << "Программа для расчета пути, пройденного лодкой по течению реки." << endl;

    cout << "Введите скорость лодки в стоячей воде (км/ч)=";
    double boatSpeed = getValue();
    cout << "Введите скорость течения реки (км/ч)=";
    double currentSpeed = getValue();
    cout << "Введите время движения (часы)=";
    double time = getValue();
    double totalSpeed = boatSpeed + currentSpeed;
    double distance = totalSpeed * time;
    cout << endl << "Путь, пройденный лодкой по течению реки: " << distance << " км";
    return 0;
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
