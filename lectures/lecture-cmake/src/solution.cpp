#include <iostream>
#include "parser.h"
#include "solver.h"

int main(int argc, char* argv[]) {
    try {
        auto coefficients = parse_arguments(argc, argv);
        Result result = solve_quadratic(coefficients[0], coefficients[1], coefficients[2]);
        std::cout << "Roots: x1 = " << result.x1 << ", x2 = " << result.x2 << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
