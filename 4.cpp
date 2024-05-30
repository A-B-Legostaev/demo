#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

/**
* @brief вычисление функции из нашего примера
* @param x число х
* @return результат функции
*/
double f(const double x);

/**
* @brief Считывание параметра типа double из stdin
* @return результат считывания
*/
double getValue();

/**
* @brief Проверка на неотрицательное число
* @param value число для проверки
*/
void checkPositive(const double value);


/**
* @brief точка входа в программу
* @return 0
*/
int main() {
    double x = 0.0;
    double x_max = 0.0;
    double plus_x = 0.0;

    cout << "х начальный:" << endl;
    x = getValue();
    cout << "х максимальный:" << endl;
    x_max = getValue();
    cout << "Δ:" << endl;
    plus_x = getValue();


    checkPositive(plus_x);
    if (x_max < x) {
        cout << "x_max < x_min" << endl;
        abort();
    }
    for (double i = x; i < x_max + plus_x; i += plus_x) {
        if ((1.0- i) < 0.0 || fabs(cos(i) < 1e-10)) {
            cout <<i<<"=неопределено, (выражение под корнем должно быть больше или равно нулю, а так же тангенс не определен в точках где косинус равен нулю)"<<endl;
        } else {
            cout <<i<<"="<<f(i)<<endl;
        }
    }
    return 0;
}

double f(const double x) {
    return sqrt(1-x)-tan(x);
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

void checkPositive(const double value) {     
    if (value <= 0) {     
        cout << "Error" << endl;
        abort();
    }     
}