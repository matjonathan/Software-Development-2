#include <iostream>
#include <stdexcept>

int divide(int numerator, int denominator) {
    if (denominator == 0)
        throw std::invalid_argument("Error: Division by zero is undefined.");

    return numerator / denominator;
}

int main() {
    int numerator, denominator;

    try {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;

        if (std::cin.fail())
            throw std::runtime_error("Invalid input for numerator.");

        std::cout << "Enter denominator: ";
        std::cin >> denominator;

        if (std::cin.fail())
            throw std::runtime_error("Invalid input for denominator.");

        int result = divide(numerator, denominator);

        std::cout << "Result: " << result << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unexpected error has occurred." << std::endl;
    }

    return 0;
}
