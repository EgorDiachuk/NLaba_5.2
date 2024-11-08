#include <iostream>
#include <locale>
#include <windows.h>

using namespace std;

int main() {
    // Встановлюємо кодування UTF-8 для виведення
    SetConsoleCP(65001); // Установка кодування для вводу
    SetConsoleOutputCP(65001); // Установка кодування для виводу
    setlocale(LC_ALL, ""); // Встановлення локалі для правильного відображення символів

    int rows, cols;

    // Введення кількості рядків та стовпців
    cout << "Введіть кількість рядків: ";
    cin >> rows;
    cout << "Введіть кількість стовпців: ";
    cin >> cols;

    // Створення двовимірного динамічного масиву через вказівники
    int** arr = new int* [rows]; // Виділяємо пам'ять для рядків
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols]; // Виділяємо пам'ять для кожного рядка (масив стовпців)
    }

    // Заповнення масиву користувачем
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }

    // Виведення масиву на екран
    cout << "Виведений масив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Знаходження суми від'ємних елементів
    int negativeSum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < 0) {
                negativeSum += arr[i][j];
            }
        }
    }

    // Виведення суми від'ємних елементів
    cout << "Сума всіх від'ємних елементів матриці: " << negativeSum << endl;

    // Звільнення пам'яті
    for (int i = 0; i < rows; i++) {
        delete[] arr[i]; // Звільняємо пам'ять для кожного рядка
    }
    delete[] arr; // Звільняємо пам'ять для масиву вказівників на рядки

    return 0;
}
