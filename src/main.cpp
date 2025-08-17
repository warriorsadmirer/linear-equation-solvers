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
        std::cout << "\nMenu:\n"
                 << "1. Thomas algorithm\n"
                 << "2. Simple iteration method\n"
                 << "3. Enter data\n"
                 << "4. Show system of equations\n"
                 << "5. Exit\n"
                 << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                thomasAlgorithm(A, b, x);
                std::cout << "\nSolution by Thomas algorithm:\n";
                for (int i = 0; i < n; i++)
                    std::cout << "x" << i + 1 << " = " << x[i] << std::endl;
                break;
            case 2:
                simple_iteration_method(A, b, x, eps, omega);
                std::cout << "\nSolution by simple iteration method:\n";
                for (int i = 0; i < n; i++)
                    std::cout << "x" << i + 1 << " = " << x[i] << std::endl;
                break;
            case 3:
                inputData(A, b);
                break;
            case 4:
                printMatrix(A, b);
                break;
            case 5:
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
        }
    } while (choice != 5);

    return 0;
}