#include <iostream>
#include <iomanip>
#include "matrix_io.h"

void printMatrix(double A[n][n], double b[n]) {
    std::cout << "\nSystem matrix:\n\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << std::setw(8) << A[i][j];
        }
        std::cout << " |" << std::setw(8) << b[i] << std::endl;
    }
    std::cout << std::endl;
}

void inputData(double A[][n], double B[]) {
    std::cout << "Enter matrix A elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << "A[" << i << "][" << j << "]: ";
            std::cin >> A[i][j];
        }
    }
    std::cout << "Enter vector B elements:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "B[" << i << "]: ";
        std::cin >> B[i];
    }
}