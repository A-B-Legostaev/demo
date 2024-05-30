#include <iostream>
#include <cmath>
using namespace std;

/**
* @brief вычисляет суммму ряда до k
* @param k размерность
* @return сумма ряда
*/
double common_sum(const int k);

/**
* @brief вычисляет суммму ряда до k элементов не меньших e
* @param e число e
* @return сумма ряда
*/
double more_e_sum(const double e);

/**
* @brief вычисление реккурентного слагаемого
* @param cur текущий член ряда
* @param k порядковый номер слагаемого
* @return элемент ряда
*/
double recurrent(const double cur, const int k);

/**
* @brief Считывание переменной
* @return результат
*/
double getValue();

/**
* @brief Считывание переменной
* @return результат 
*/
int getValueInt();


/**
* @brief точка входа в программу
* @return 0 
*/
int main() {
    cout << "Введите k: ";
    int k = getValueInt();
    cout << "Введите e: ";
    double e = getValue();
    int fisrt = 1;

    if (e > fisrt) {
        cout << "Некорректный ввод!";
        abort();
    }

    cout << endl;
    
    cout << "a)" << endl << common_sum(k) << endl;
    cout << "b)=" << more_e_sum(e) << endl;
    return 0;
}

double getValue() {
    double value;
    cin >> value;
    if (cin.fail() || value <= 0.0 ) {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

int getValueInt() {
    int value;
    cin >> value;
    if (cin.fail() || value < 0) {
        cout << "Некорректное значение" << endl;
        abort();
    }
    
    return value;
}

double common_sum(const int k) {
    double res = 0.0;
    double current = 1.0;
    for (int i = 0; i < k; ++i) {
        cout<<"<"<<i<< "> " <<current<<" sum="<< res;
        res += current;
        current = recurrent(current, i);
    }
    cout << endl;
    return res;
}

double more_e_sum(const double e) {
    double ress = 0.0;
    double current = 1.0;
    int i = 0;
    while (true) { 
        ress += current;
	    current = recurrent(current, i);
        if (fabs(current) < e) {
            break;
        }
        ++i;
    }
    return ress;
}

double recurrent(const double cur, const int k) {
    return cur * (-1) * ((2 + k)/pow(k + 1, 2));
}