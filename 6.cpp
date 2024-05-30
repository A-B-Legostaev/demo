#include <iostream>
#include <algorithm>
#include <cstdlib>
using namespace std;

/**
* @brief перечисление возможных видов работы по заполения
* @param MANUAL автоматически
* @param AUTO вручную
*/
enum MODE {
    MANUAL,
    AUTO
};

/**
* @brief Выводит массив
* @param arr массив
* @param size размер
*/
void printArr(const int *arr, const int size);

/**
* @brief заполняет массив случаными числами
* @param arr указатель на массив
* @param size размерность массива
* @param xmin левая граница диапазона
* @param xmax левая граница диапазона
*/
void fillArrayAuto(int* arr, const int size, const int xmin, const int xmax);

/**
* @brief заполняет массив вручную
* @param arr указатель на массив
* @param size размерность массива
* @param xmin левая граница диапазона
* @param xmax левая граница диапазона
*/
void fillArrayManual(int* arr, const int size, const int xmin, const int xmax);

/**
* @brief Находит сумму элементов, значения которых состоят из одной цифры
* @param arr указатель на массив
* @param size размерность массива
* @return эта сумма
*/
int firstTask(const int* arr, const int size);

/**
* @brief Заменяет элементы массива между минимальным и максимальным на те же элементы в обратном порядке
* @param arr указатель на массив
* @param size размерность массива
*/
void secondTask(int* arr, const int size);

/**
* @brief Найходит номер последней пары соседних элементов с одинаковыми знаками, произведение которых меньше заданного числа
* @param arr указатель на массив
* @param size размерность массива
* @param number заданное число
* @return Возвращает первый элемент такой пары
*/
int threeTask(const int* arr, const int size, const int number);

/**
* @brief Проверка на неотрицательное число
* @param value число для проверки
*/
void checkPositive(const int value);

/**
* @brief Считывает число с проверкой
* @return возвращает считанное число
*/
int getValue();

/**
* @brief точка входа в программу
* @return 0
*/
int main() {
    cout << "Введите размерность: ";
    int n = getValue();
    checkPositive(n);
    cout << "Введите число для задания 3: ";
    int number = getValue();
    cout << "Как будете заполнять? Введите 0 для ручного ввода, 1 для заполнения случайми числами: ";
    int mode = getValue();

    cout << "Введите диапазон значений для заполнения" << endl;
    cout << "От=";
    int xmin = getValue();
    cout << "До=";
    int xmax = getValue();

    if (xmin > xmax) {
        cout << "Некорректная размерность!" << endl;
        abort();
    }


    int* array = new int[n]();

    switch (mode) {
        case AUTO :
            fillArrayAuto(array, n, xmin, xmax);
            break;
        case MANUAL :
            fillArrayManual(array, n, xmin, xmax);
            break;
        default :
            cout << "нет такого режима" << endl;
            return 1;
    }

    cout << "Массив заполнен: " << endl;
    printArr(array, n);
    cout << endl << "1. Найти сумму элементов, значения которых состоят из одной цифры" << "\n" << "Результат: " << firstTask(array, n) << endl;
    cout << "2. Заменить элементы массива между минимальным и максимальным на те же элементы в обратном порядке" << "\n" << "Результат: " << endl;
    secondTask(array, n);
    printArr(array, n);
    cout << "3. Найти номер последней пары соседних элементов с одинаковыми знаками, произведение которых меньше заданного числа" << "\n" << "Результат: ";
    int res = threeTask(array, n, number);
    if (res != -1) {
        cout << "Есть, это: arr["<< res << "]=" << array[res] << " arr["<<res+1<< "]="<<array[res+1]<< endl;
    } else {
        cout << "Таких пар нет!" << endl;
    }
    delete[] array;
    return 0;
}

int getValue() {
    int value;
    cin >> value;
    if (cin.fail()) {
        cout << "Некорректное значение" << endl;
        abort();
    }
    return value;
}

void checkPositive(const int value) {     
    if (value <= 0) {     
        cout << "Error" << endl;
        abort();
    }     
}

void printArr(const int *arr, const int size) {
    for (size_t i = 0; i < size; i++) {
        cout << "Index(" << i << ")=" << arr[i] << endl;
    }
}

void fillArrayAuto(int* arr, const int size, const int xmin, const int xmax) {
    for (size_t i = 0; i < size; i++) {
        arr[i] = rand() % (xmax - xmin + 1) + xmin;
    }
}

void fillArrayManual(int* arr, const int size, const int xmin, const int xmax) {
    for (size_t i = 0; i < size; i++) {
        cout << "array[" << i << "] --> ";
        cin >> arr[i];
        if (arr[i] < xmin || arr[i] > xmax) {
            cout << "Число вне диапазона!" << endl;
            abort();
        }
        cout << endl;
    }
}

int firstTask(const int* arr, const int size) {
    int res = 0;
    for (size_t i = 0; i < size; i++) {
        if (abs(arr[i]) < 10) {
            res += arr[i];
        }
    }
    return res;
}

void secondTask(int* arr, const int size) {
    int *max_elem = std::max_element(arr, arr + size);
    int *min_elem = std::min_element(arr, arr + size);
    int t = *max_elem;
    *max_elem = *min_elem;
    *min_elem = t;
}

int threeTask(const int* arr, const int size, const int number) {
    int id_pair = -1;
    for (size_t i = 1; i < size; i++) {
        if ((arr[i-1] >= 0 && arr[i] >= 0) || (arr[i-1] < 0 && arr[i] < 0)) {
            if (arr[i-1] * arr[i] < number) {
                id_pair = i - 1;
            }
        }
    }
    return id_pair;
}

