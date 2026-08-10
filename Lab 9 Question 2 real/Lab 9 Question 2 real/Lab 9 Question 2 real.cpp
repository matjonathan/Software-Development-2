#include <iostream>
#include <fstream>
#include <exception>

// Function to create and write numbers to file
void createNumberFile(const char* filename) {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Unable to create file.");
    }
    outFile << "10 20 30 40";
    outFile.close();
}

// Function to read file and calculate sum with EOF handling
int readFileAndSum(const char* filename) {
    std::ifstream file(filename);
    if (!file) {
        throw std::runtime_error("Unable to open file.");
    }

    int sum = 0, number;

    while (file >> number) {
        sum += number;
    }

    if (!file.eof()) {
        throw std::runtime_error("File read error occurred.");
    }

    file.close();
    return sum;
}

int main() {
    const char* filename = "numbers.txt";

    try {
        // Create the file with numbers
        createNumberFile(filename);

        // Calculate sum of numbers from file
        int sum = readFileAndSum(filename);

        std::cout << "Total Sum: " << sum << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}