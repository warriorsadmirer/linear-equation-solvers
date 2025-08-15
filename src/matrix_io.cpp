#include <iostream>
#include <iomanip>
#include "matrix_io.h"

void printMatrix(double A[5][5], double b[5]) {
    std::cout << "\nМатрица системы:\n\n";
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            std::cout << std::setw(8) << A[i][j];
        }
        std::cout << " |" << std::setw(8) << b[i] << std::endl;
    }
    std::cout << std::endl;
}

void inputData(double A[][5], double B[], int n) {
    std::cout << "Введите элементы матрицы A:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> A[i][j];
        }
    }
    std::cout << "Введите элементы вектора B:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "B[" << i << "]: ";
        std::cin >> B[i];
    }
}