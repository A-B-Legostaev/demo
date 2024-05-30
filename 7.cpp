#include <iostream>
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
 * @brief Вывод массива на экран
 * @param rows - число строк массива
 * @param columns -число столбцов массива
*/
void printArray( int **arr, const int rows, const int columns);

/**
 * @brief Копирует массив заданного размера в новый массив
 * @param arr - указатель на массив
 * @param rows - число строк массива
 * @param columns -число столбцов массива
 * @return ссылка на новый массив, являющийся копией исходного
*/
int** copyArray( int** arr, const int rows, const int columns);

/**
* @brief заполняет массив случаными числами
* @param arr указатель на массив
* @param size размерность массива
* @param xmin левая граница диапазона
* @param xmax левая граница диапазона
*/
void fillArrayAuto(int** arr, const int rows, const int columns, const int xmin, const int xmax);

/**
* @brief заполняет массив вручную
* @param arr указатель на массив
* @param size размерность массива
* @param xmin левая граница диапазона
* @param xmax левая граница диапазона
*/
void fillArrayManual(int** arr, const int rows, const int columns, const int xmin, const int xmax);

/**
 * @brief Выделяет память для массива заданного размера
 * @param rows - число строк массива
 * @param columns -число столбцов массива
 * @return ссылка на выделеную память
*/
int** getNewArray(const int rows, const int columns);

/**
 * @brief освобождает память, выделенную для массива
 * @param rows - число строк массива
*/
void deleteArray(int ** arr, const int rows);

/**
* @brief Вставляет после всех столбцов, содержащих нулевой элемент, первый столбец
* @param arr указатель на исходный массив
* @param new_arr указатель на еще один массив
* @param rows количество строк
* @param columns количество столбцов
*/
void taskSecond( int **arr, int** new_arr, const int rows, const int columns);

/**
* @brief Заменяет нечетный элемент каждой строки нулем
* @param arr указатель на исходный массив
* @param rows количество строк
* @param columns количество столбцов
*/
void taskFisrt( int **arr, const int rows, const int columns);

/**
* @brief точка входа в программу
* @return 0
*/
int main() {
    cout << "Введите количство строк: ";
    int n = getValue();
    checkPositive(n);
    cout << "Введите количство столбцов: ";
    int m = getValue();
    checkPositive(n);

    cout << "Как будете заполнять? Введите 0 для ручного ввода, 1 для заполнения случайми числами: ";
    int mode = getValue();
    cout << "Введите диапазон значений для заполнения" << endl;
    cout << "От=";
    int xmin = getValue();
    cout << "До=";
    int xmax = getValue();

    if ((xmin > xmax)) {
        cout << "Некорректная размерность!" << endl;
        abort();
    }

    int** array = getNewArray(n, m);

    switch (mode) {
        case AUTO :
            fillArrayAuto(array, n, m, xmin, xmax);
            break;
        case MANUAL :
            fillArrayManual(array, n, m, xmin, xmax);
            break;
        default :
            cout << "нет такого режима" << endl;
            abort();
    }

    cout << "Массив заполнен: " << endl;
    printArray(array, n, m);
    cout << "1. Заменить нечетный элемент каждой строки нулем" << endl << "Результат: " << endl;
    int **task1 = copyArray(array, n, m);
    taskFisrt(task1, n, m);
    printArray(task1, n, m);
    deleteArray(task1, n);

    cout << "2. Вставить после всех столбцов, содержащих нулевой элемент, первый столбец" << endl << "Результат:" << endl;
    int new_cols = n;
    for (size_t j = 0; j < m; j++) {
        for (size_t i = 0; i < n; i++) {
            if ((i == 0 ) && (j == 0)) continue;
            if (array[i][j] == array[0][0]) {
                new_cols++;
                break;
            }
        }
    }
    if (new_cols == n) {
        printArray(array, n, new_cols);
    } else {
        int** task2 = getNewArray(n, new_cols);
        taskSecond(array, task2, n, m);
        printArray(task2, n, new_cols);
        deleteArray(task2, n);
    }

    deleteArray(array, n);
    return 0;
}

int** copyArray( int** arr, const int rows, const int columns) {
    int** resultArray = getNewArray(rows, columns);
    for (size_t i = 0; i < (size_t)rows; i++)
    {     
        for (size_t j = 0; j < columns; j++)
        {     
            resultArray[i][j] = arr[i][j];
        }     
    }
    return resultArray;
}


int** getNewArray(const int rows, const int columns) {
    int** arr = new int*[rows];
    for (size_t i = 0; i < (size_t)rows; ++i) {
        arr[i] = new int[columns];
    }
    return arr;
}

void deleteArray(int ** arr, const int rows) {
    for (size_t i = 0; i < (size_t)rows; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void taskFisrt( int **arr, const int rows, const int columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            if (abs(arr[i][j]) % 2 == 1) {
                arr[i][j] = 0;
            }
        }
    }
}

void taskSecond( int **arr, int** new_arr, const int rows, const int columns) {
    int elment_0 = arr[0][0];
    bool need_to_insert = false;
    for (size_t j = 0, j_new_arr = 0; j < columns;j++) {
        for (size_t i = 0; i < rows; i++) {
            if (arr[i][j] == elment_0) {
                if  (!((i == 0 ) && (j ==0))) {
                    need_to_insert = true;
                }
            }
            new_arr[i][j_new_arr] = arr[i][j];
        }
        j_new_arr++;
        if (need_to_insert) {
            for (size_t i = 0; i < rows; i++) {
                new_arr[i][j_new_arr] = arr[i][0];
            }
            j_new_arr++;
            need_to_insert = false;
        }
    }
}

void printArray( int **arr, const int rows, const int columns) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void fillArrayAuto(int** arr, const int rows, const int columns, const int xmin, const int xmax) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            arr[i][j] = rand() % (xmax - xmin + 1) + xmin;
        }
    }
}

void fillArrayManual(int** arr, const int rows, const int columns, const int xmin, const int xmax) {
    for (size_t i = 0; i < rows; i++) {
        for (size_t j = 0; j < columns; j++) {
            cout << "array[" << i << "][" << j << "] --> ";
            cin >> arr[i][j];
            if (arr[i][j] < xmin || arr[i][j] > xmax) {
                cout << "Число вне диапазона!" << endl;
                abort();
            }
            cout << endl;
        }
    }
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
        cout<<"Error"<<endl;
        abort();
    }     
}