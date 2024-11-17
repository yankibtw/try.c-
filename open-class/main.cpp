#include <iomanip>
#include <iostream>
#include <cmath>

// Функция для вычисления значения f(x)
double f(double x) {
    return fabs( exp(2 * x) * sin(2 * x + 3) );
}


// Метод трапеций
double trapezoidal(double a, double b, int n) {
	// Шаг разбиения
    double h = (b - a) / n;
    double result = (f(a) + f(b)) / 2;

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        result += f(x);
    }

    result *= h;
    return result;
}


// Метод симпсона
double simpson(double a, double b, int n) {
	// Шаг разбиения
    double h = (b - a) / n;
    double result = f(a) + f(b);

    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        if (i % 2 == 0) {
            result += 2 * f(x);
        } else {
            result += 4 * f(x);
        }
    }

    result *= h / 3;
    return result;
}

int main() {
    double a, b;
    int n = 10000; // Число разбиений


    std::cout << "Введите границы интегрирования A и B: " << std::endl;
    std::cin >> a;
    std::cin >> b;


    double result = trapezoidal(a, b, n);


	constexpr auto max_precision{std::numeric_limits<long double>::digits10}; 
    std::cout << "Численный результат: " << std::setprecision(max_precision) << result << std::endl;


    return 0;
}
