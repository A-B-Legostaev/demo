#include <iostream>
#include <cmath>
using namespace std;
/**
* @brief вычисление функции a
* @param x число х
* @param x число y
* @param x число z
* @return результат функции
*/
double f1(const double x, const double y, const double z);

/**
* @brief вычисление функции b
* @param x число х
* @param x число y
* @param x число z
* @return результат функции
*/
double f2(const double x, const double y, const double z);

/**
* @brief точка входа в программу
* @return 0
*/
int main ()
{
    const double x = 0.3;
    const double y = 2.9;
    const double z = 0.5;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    cout << "a = " << f1(x,y,z) << endl;
    cout << "b = " << f2(x,y,z) << endl;

    return 0;
}

double f1(const double x, const double y, const double z)
{
    return ((pow(z, 2.0) * x + exp(-1.0 * x) * cos(y * x)) /
            (y * x - exp(-1.0 * x) * sin(y * x) + 1));
}

double f2(const double x, const double y, const double z)
{
    return (exp(2 * x) * log(z + x) - pow(y, 3 * x) * log(y - x));
}