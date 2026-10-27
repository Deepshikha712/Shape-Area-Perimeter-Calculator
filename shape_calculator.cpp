#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
using namespace std;
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape() {}
};
class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) {
        radius = r;
    }
    double area() const override {
        return 3.14159 * radius * radius;
    }
    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
};
class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double l, double w) {
        length = l;
        width = w;
    }
    double area() const override {
        return length * width;
    }
    double perimeter() const override {
        return 2 * (length + width);
    }
};
class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double x, double y, double z) {
        a = x;
        b = y;
        c = z;
    }
    double perimeter() const override {
        return a + b + c;
    }
    double area() const override {
        double s = perimeter() / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};
double readPositiveValue(const char prompt[]) {
    double value;
    while (true) {
        cout << prompt;
        if (cin >> value && value > 0) {
            return value;
        }
        cout << "Invalid input! Enter a number greater than zero.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}
int main() {
    int choice;
    Shape* shape = nullptr;
    cout << fixed << setprecision(2);
    do {
        cout << "\n===== SHAPE AREA & PERIMETER CALCULATOR =====\n";
        cout << "1. Circle\n";
        cout << "2. Rectangle\n";
        cout << "3. Triangle\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cout << "Invalid choice! Please enter a number from 1 to 4.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        switch (choice) {
            case 1: {
                double r = readPositiveValue("Enter radius: ");
                shape = new Circle(r);
                break;
            }
            case 2: {
                double l = readPositiveValue("Enter length: ");
                double w = readPositiveValue("Enter width: ");
                shape = new Rectangle(l, w);
                break;
            }
            case 3: {
                double a = readPositiveValue("Enter first side: ");
                double b = readPositiveValue("Enter second side: ");
                double c = readPositiveValue("Enter third side: ");

                if (a + b <= c || a + c <= b || b + c <= a) {
                    cout << "Invalid triangle! The sum of any two sides "
                         << "must be greater than the third side.\n";
                    continue;
                }
                shape = new Triangle(a, b, c);
                break;
            }
            case 4:
                cout << "Thank you for using the calculator!\n";
                break;
            default:
                cout << "Invalid choice! Please select 1, 2, 3 or 4.\n";
                continue;
        }
        if (shape != nullptr) {
            cout << "\nArea: " << shape->area() << endl;
            cout << "Perimeter: " << shape->perimeter() << endl;
            delete shape;
            shape = nullptr;
        }
    } while (choice != 4);
    return 0;
}
