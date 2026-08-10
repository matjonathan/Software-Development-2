#include <iostream>
#include <cmath>
using namespace std;

// Class that encapsulates shape calculations and demonstrates method overloading.
class ShapeCalculator {
public:
    // ----- Square Methods -----
    // Overloaded methods for square area.
    int squareArea(int a, int b) {
        return a * b;
    }
    float squareArea(float a, float b) {
        return a * b;
    }
    // Overloaded methods for square perimeter.
    int squarePerimeter(int a, int b) {
        return 2 * (a + b);
    }
    float squarePerimeter(float a, float b) {
        return 2 * (a + b);
    }

    // ----- Rectangle Methods -----
    // Overloaded methods for rectangle area.
    int rectangleArea(int length, int width) {
        return length * width;
    }
    float rectangleArea(float length, float width) {
        return length * width;
    }
    // Overloaded methods for rectangle perimeter.
    int rectanglePerimeter(int length, int width) {
        return 2 * (length + width);
    }
    float rectanglePerimeter(float length, float width) {
        return 2 * (length + width);
    }

    // ----- Triangle Methods (Right-Angled) -----
    // Overloaded methods for triangle area.
    int triangleArea(int base, int height) {
        return (base * height) / 2;
    }
    float triangleArea(float base, float height) {
        return 0.5f * base * height;
    }
    // Overloaded methods for triangle perimeter.
    // For the integer version, the hypotenuse is truncated.
    int trianglePerimeter(int base, int height) {
        int hypotenuse = static_cast<int>(sqrt(base * base + height * height));
        return base + height + hypotenuse;
    }
    float trianglePerimeter(float base, float height) {
        float hypotenuse = sqrt(base * base + height * height);
        return base + height + hypotenuse;
    }
};

int main() {
    ShapeCalculator calc;

    // Variables for integer input.
    int intA, intB, intLength, intWidth, intBase, intHeight;
    // Variables for float input.
    float floatA, floatB, floatLength, floatWidth, floatBase, floatHeight;

    // ----- Square Calculations -----
    cout << "Square (Integer):" << endl;
    cout << "Enter two integer sides for the square: ";
    cin >> intA >> intB;
    cout << "Square area (int): " << calc.squareArea(intA, intB) << endl;
    cout << "Square perimeter (int): " << calc.squarePerimeter(intA, intB) << endl;

    cout << "\nSquare (Float):" << endl;
    cout << "Enter two float sides for the square: ";
    cin >> floatA >> floatB;
    cout << "Square area (float): " << calc.squareArea(floatA, floatB) << endl;
    cout << "Square perimeter (float): " << calc.squarePerimeter(floatA, floatB) << endl;

    // ----- Rectangle Calculations -----
    cout << "\nRectangle (Integer):" << endl;
    cout << "Enter length and width as integers: ";
    cin >> intLength >> intWidth;
    cout << "Rectangle area (int): " << calc.rectangleArea(intLength, intWidth) << endl;
    cout << "Rectangle perimeter (int): " << calc.rectanglePerimeter(intLength, intWidth) << endl;

    cout << "\nRectangle (Float):" << endl;
    cout << "Enter length and width as floats: ";
    cin >> floatLength >> floatWidth;
    cout << "Rectangle area (float): " << calc.rectangleArea(floatLength, floatWidth) << endl;
    cout << "Rectangle perimeter (float): " << calc.rectanglePerimeter(floatLength, floatWidth) << endl;

    // ----- Right Triangle Calculations -----
    cout << "\nRight Triangle (Integer):" << endl;
    cout << "Enter base and height as integers: ";
    cin >> intBase >> intHeight;
    cout << "Triangle area (int): " << calc.triangleArea(intBase, intHeight) << endl;
    cout << "Triangle perimeter (int): " << calc.trianglePerimeter(intBase, intHeight) << endl;

    cout << "\nRight Triangle (Float):" << endl;
    cout << "Enter base and height as floats: ";
    cin >> floatBase >> floatHeight;
    cout << "Triangle area (float): " << calc.triangleArea(floatBase, floatHeight) << endl;
    cout << "Triangle perimeter (float): " << calc.trianglePerimeter(floatBase, floatHeight) << endl;

    return 0;
}
