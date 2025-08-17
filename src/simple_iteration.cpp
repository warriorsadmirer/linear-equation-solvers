#include <iostream>
#include <cmath>
#include "simple_iteration.h"

void simple_iteration_method(
    double A[][n], double B[], double x[],
    double eps, double omega
) {
    double x0[n] = {0};
    double E[n] = {0};
    double max = 0;
    int counter = 0;

    for (int i = 0; i < n; i++)
        x0[i] = B[i];

    do {
        max = 0;
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < n; j++) {
                if (i != j)
                    sum += A[i][j] * x0[j];
            }
            x[i] = (1 - omega) * x0[i] + omega * (B[i] - sum) / A[i][i];
            E[i] = fabs(x[i] - x0[i]);
            if (max < E[i])
                max = E[i];
        }
        for (int i = 0; i < n; i++)
            x0[i] = x[i];
        counter++;
    } while (max > eps);

    std::cout << "\nIterations count: " << counter;
}