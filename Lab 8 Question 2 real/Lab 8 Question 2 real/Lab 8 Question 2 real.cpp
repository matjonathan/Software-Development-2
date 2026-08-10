#include <iostream>
#include <string>
#include <regex>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

// Check if a year is a leap year.
bool isLeapYear(int year) {
    return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

// Check if the date string is in the format DD-MM-YYYY.
bool isValidDateFormat(const string& date) {
    regex datePattern("^\\d{2}-\\d{2}-\\d{4}$");
    return regex_match(date, datePattern);
}

// Validate that the date is a real calendar date.
bool isValidDate(const string& date) {
    if (!isValidDateFormat(date))
        return false;

    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    if (month < 1 || month > 12)
        return false;

    int daysInMonth;
    switch (month) {
    case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        daysInMonth = 31; break;
    case 4: case 6: case 9: case 11:
        daysInMonth = 30; break;
    case 2:
        daysInMonth = isLeapYear(year) ? 29 : 28;
        break;
    default:
        return false;
    }
    return (day >= 1 && day <= daysInMonth);
}

// Check that the student is at least 18 years old.
bool isAtLeast18(const string& date) {
    int day = stoi(date.substr(0, 2));
    int month = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    // Get current local date.
    time_t t = time(0);
    tm now;
#ifdef _MSC_VER
    localtime_s(&now, &t);  // Windows
#else
    localtime_r(&t, &now);  // POSIX systems
#endif

    int currentYear = now.tm_year + 1900;
    int currentMonth = now.tm_mon + 1;
    int currentDay = now.tm_mday;

    int age = currentYear - year;
    if (currentMonth < month || (currentMonth == month && currentDay < day))
        age--;

    return age >= 18;
}

// Validate that the full name contains only alphabetic characters and spaces.
bool isValidName(const string& name) {
    for (char c : name) {
        if (!isalpha(c) && !isspace(c))
            return false;
    }
    return true;
}

// Validate that the telephone number is exactly 11 digits.
bool isValidTelephone(const string& tel) {
    if (tel.length() != 11)
        return false;
    for (char c : tel) {
        if (!isdigit(c))
            return false;
    }
    return true;
}

// Validate the email address with a simple regex.
bool isValidEmail(const string& email) {
    regex emailPattern("^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\\.[A-Za-z]{2,}$");
    return regex_match(email, emailPattern);
}

// Validate that the university student number is 3 letters followed by 6 digits.
bool isValidStudentNumber(const string& stuNum) {
    regex stuPattern("^[A-Za-z]{3}\\d{6}$");
    return regex_match(stuNum, stuPattern);
}

int main() {
    string dob, fullName, telephone, email, studentNumber;

    // Input and validate Date of Birth.
    cout << "Enter date of birth (DD-MM-YYYY): ";
    getline(cin, dob);
    if (!isValidDate(dob)) {
        cout << "Error: Invalid date format or non-existent date." << endl;
        return EXIT_FAILURE;
    }
    if (!isAtLeast18(dob)) {
        cout << "Error: Student must be at least 18 years old." << endl;
        return EXIT_FAILURE;
    }

    // Input and validate Full Name.
    cout << "Enter full name: ";
    getline(cin, fullName);
    if (!isValidName(fullName)) {
        cout << "Error: Name must only contain alphabetic characters and spaces." << endl;
        return EXIT_FAILURE;
    }

    // Input and validate Telephone Number.
    cout << "Enter telephone number (11 digits): ";
    getline(cin, telephone);
    if (!isValidTelephone(telephone)) {
        cout << "Error: Telephone number must be exactly 11 digits." << endl;
        return EXIT_FAILURE;
    }

    // Input and validate Email Address.
    cout << "Enter email address: ";
    getline(cin, email);
    if (!isValidEmail(email)) {
        cout << "Error: Invalid email address format." << endl;
        return EXIT_FAILURE;
    }

    // Input and validate University Student Number.
    cout << "Enter university student number (3 letters followed by 6 digits): ";
    getline(cin, studentNumber);
    if (!isValidStudentNumber(studentNumber)) {
        cout << "Error: Invalid university student number format." << endl;
        return EXIT_FAILURE;
    }

    // Write the validated student data to the file with tab-separated fields.
    ofstream outFile("students.txt", ios::app);
    if (!outFile) {
        cout << "Error: Could not open file for writing." << endl;
        return EXIT_FAILURE;
    }
    outFile << dob << "\t"
        << fullName << "\t"
        << telephone << "\t"
        << email << "\t"
        << studentNumber << "\n";
    outFile.close();

    cout << "\nRegistration successful!\n\n";

    // Read and output each record present in the file.
    ifstream inFile("students.txt");
    if (!inFile) {
        cout << "Error: Could not open file for reading." << endl;
        return EXIT_FAILURE;
    }

    cout << "Registered Students:" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return EXIT_SUCCESS;
}
