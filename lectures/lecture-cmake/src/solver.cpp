#include "solver.h"

#include <cmath>
#include <stdexcept>

#ifdef USE_DOUBLE_PRECISION
using PointType = double;
#else
using PointType = float;
#endif

Result solve_quadratic(double a, double b, double c) {
    PointType discriminant = b * b - 4 * a * c;
    if (discriminant < 0) {
        throw std::runtime_error("No real roots.");
    }
    PointType sqrt_d = std::sqrt(discriminant);
    const PointType x1 = (-b + sqrt_d) / (2 * a);
    const PointType x2 = (-b - sqrt_d) / (2 * a);
    return { x1, x2 };
}
