#include <iostream>
#include <fstream>

int readFileAndSum(const char* filename) {
	std::ifstream file(filename);
	int sum = 0, number;

	while ((file >> number) {
		sum += number;
	}

	return sum:
}

int main() {
	const char* filename = "numbers.txt";

	int sum = readFileAndSum(filename);

	std::cout << "Total Sum: " << sum << std::endl;
	return 0;
}