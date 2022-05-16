#include <cmath>

double f(double x) {
    return pow(sin(2 * x) + 4 * pow(x, 2) + 3 * x, 2);
}

double x(double s, double xInicial, double xFinal) {
    return (xFinal + xInicial) / 2.0 + ((xFinal - xInicial) / 2.0) * s;
}

double integracao(double xInicial, double xFinal, int n, double* raizes, double* w) { // n é o número de pontos na aplicação fórmula
    double result = 0.0;

    for(int i = 0; i < n; i++) {
       result += f(x(xInicial, xFinal, raizes[i])) * w[i];
    }
    return result;
}

double gauss_legendre_2(double xInicial, double xFinal) { // 2 pontos
    double s = sqrt(1.0/3.0);
    double raizes[2] = {-s, s};
    double w[2] = {1, 1};
    return integracao(xInicial, xFinal, 2, raizes, w);
}

double gauss_legendre_3(double xInicial, double xFinal) { // 3 pontos
    double s = sqrt(3.0/5.0);
    double raizes[3] = {-s, 0, s};
    double w[3] = {5.0/9.0, 8.0/9.0, 5.0/9.0};
    return integracao(xInicial, xFinal, 3, raizes, w);
}

double gauss_legendre_4(double xInicial, double xFinal) { // 4 pontos
    double s = sqrt(1.0/8.0);
    double raizes[4] = {-0.8611, -0.3399, 0.3399, 0.8611};
    double w[4] = {0.3478, 0.6521, 0.6521, 0.3478};
    return integracao(xInicial, xFinal, 4, raizes, w);
}

