#include "parser.h"
#include <stdexcept>
#include <sstream>

std::vector<double> parse_arguments(int argc, char* argv[]) {
    if (argc != 4) {
        throw std::invalid_argument("Expected 3 arguments for coefficients.");
    }
    std::vector<double> coefficients;
    for (int i = 1; i < argc; ++i) {
        std::istringstream iss(argv[i]);
        double coef;
        if (!(iss >> coef)) {
            throw std::invalid_argument("Invalid argument. Expected a number.");
        }
        coefficients.push_back(coef);
    }
    return coefficients;
}
