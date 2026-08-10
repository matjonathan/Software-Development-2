#include <iostream>
using namespace std;

int main() {
    double hours, wage, pay;

    cout << "Enter hours worked: ";
    cin >> hours;

    cout << "Enter hourly wage: ";
    cin >> wage;

    if (hours <= 40)
        pay = hours * wage;
    else
        pay = 40 * wage + (hours - 40) * wage * 1.5;

    cout << "Weekly pay: $" << pay << endl;
    return 0;
}