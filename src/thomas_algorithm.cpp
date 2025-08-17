#include <algorithm>
#include "thomas_algorithm.h"

void thomasAlgorithm(double A[n][n], double b[n], double x[n]) {
    double A_copy[n][n];
    double b_copy[n];
    std::copy(&A[0][0], &A[0][0] + n * n, &A_copy[0][0]);
    std::copy(b, b + n, b_copy);

    // Forward sweep
    for (int i = 1; i < n; ++i) {
        double m = A_copy[i][i - 1] / A_copy[i - 1][i - 1];
        A_copy[i][i] -= m * A_copy[i - 1][i];
        b_copy[i] -= m * b_copy[i - 1];
    }

    // Backward substitution
    x[n-1] = b_copy[n-1] / A_copy[n-1][n-1];
    for (int i = n - 2; i >= 0; --i) {
        x[i] = (b_copy[i] - A_copy[i][i + 1] * x[i + 1]) / A_copy[i][i];
    }
}