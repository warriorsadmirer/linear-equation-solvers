#include <iostream>
#include "matrix_io.h"
#include "thomas_algorithm.h"
#include "simple_iteration.h"
#include "constants.h"

int main() {
    double A[n][n] = {
        {-3.83, 1, 0, 0, 0},
        {1, -2, 1, 0, 0},
        {0, 1, -2, 1, 0},
        {0, 0, 1, -2, 1},
        {0, 0, 0, 1, -3.83}
    };
    double b[n] = {0, -6, -6, -6, 0};
    double x[n] = {0};
    int choice;

    do {
        std::cout << "\nМеню:\n"
                 << "1. Метод прогонки\n"
                 << "2. Метод простой итерации\n"
                 << "3. Ввод данных\n"
                 << "4. Показать систему уравнений\n"
                 << "5. Выход\n"
                 << "Введите ваш выбор: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                thomasAlgorithm(A, b, x);
                std::cout << "\nРешение методом прогонки:\n";
                for (int i = 0; i < n; i++)
                    std::cout << "x" << i + 1 << "=" << x[i] << " " << std::endl;
                break;
            case 2:
                simple_iteration_method(A, b, n, x, eps, omega);
                std::cout << "\nРешение методом простой итерации:\n";
                for (int i = 0; i < n; i++)
                    std::cout << "x" << i + 1 << "=" << x[i] << " " << std::endl;
                break;
            case 3:
                inputData(A, b, n);
                break;
            case 4:
                printMatrix(A, b);
                break;
            case 5:
                break;
            default:
                std::cout << "Некорректный выбор." << std::endl;
        }
    } while (choice != 5);

    return 0;
}