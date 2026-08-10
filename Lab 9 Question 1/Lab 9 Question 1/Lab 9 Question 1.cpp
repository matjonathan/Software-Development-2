#include <iostream>

int divide(int numeratoe, int denominator) {
	int* ptr = new int(10);

	int result = numerator / denominator;

	return result;
}

int main() {
	int numerator, denominator;

	std::cout << "Enter numerator" ";
		std::cin >> nummerator;

	std::cout << "Enter denominator: ";
	std::cin >> denominator;

	int result = divide(numerator, denominator);

	std::cout << "Result: " << result << std::endl;
	return 0;
}