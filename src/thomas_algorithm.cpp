#include <algorithm> // для std::copy
#include "thomas_algorithm.h"

void thomasAlgorithm(double A[5][5], double b[5], double x[5]) {
    double A_copy[5][5];
    double b_copy[5];
    std::copy(&A[0][0], &A[0][0] + 25, &A_copy[0][0]);
    std::copy(b, b + 5, b_copy);

    // Прямой ход
    for (int i = 1; i < 5; ++i) {
        double m = A_copy[i][i - 1] / A_copy[i - 1][i - 1];
        A_copy[i][i] -= m * A_copy[i - 1][i];
        b_copy[i] -= m * b_copy[i - 1];
    }

    // Обратный ход
    x[4] = b_copy[4] / A_copy[4][4];
    for (int i = 3; i >= 0; --i) {
        x[i] = (b_copy[i] - A_copy[i][i + 1] * x[i + 1]) / A_copy[i][i];
    }
}