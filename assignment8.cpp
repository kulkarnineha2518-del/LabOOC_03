#include <iostream>
using namespace std;

class Distance {
private:
    int feet;
    int inches;

public:
    // Default Constructor
    Distance() {
        feet = 0;
        inches = 0;
    }

    // Parameterized Constructor
    Distance(int f, int i) {
        feet = f;
        inches = i;
        adjustDistance();
    }

    // Helper function to normalize inches (12 inches = 1 foot)
    void adjustDistance() {
        if (inches >= 12) {
            feet += inches / 12;
            inches = inches % 12;
        }
    }

    // 1. Overloading UNARY Operator (Prefix Decrement --)
    Distance operator--() {
        --feet;
        --inches;
        if (inches < 0) {
            inches += 12;
            --feet;
        }
        return Distance(feet, inches);
    }

    // 2. Overloading BINARY Operator (+)
    Distance operator+(const Distance& d) {
        int totalFeet = feet + d.feet;
        int totalInches = inches + d.inches;
        return Distance(totalFeet, totalInches);
    }

    // 3. Overloading RELATIONAL Operator (<)
    bool operator<(const Distance& d) {
        if (feet < d.feet) {
            return true;
        }
        if (feet == d.feet && inches < d.inches) {
            return true;
        }
        return false;
    }

    // Function to display the distance
    void display() const {
        cout << feet << " feet, " << inches << " inches" << endl;
    }
};

int main() {
    cout << "=== Operator Overloading Demonstration ===" << endl;

    // Creating initial objects
    Distance d1(5, 9);
    Distance d2(3, 7);

    cout << "Distance 1: ";
    d1.display();
    cout << "Distance 2: ";
    d2.display();

    // 1. Binary Operator (+) Testing
    Distance d3 = d1 + d2;
    cout << "\n[Binary +] Total Distance (d1 + d2): ";
    d3.display();

    // 2. Unary Operator (--) Testing
    cout << "\n[Unary --] Applying prefix decrement on Distance 1..." << endl;
    --d1;
    cout << "New Distance 1: ";
    d1.display();

    // 3. Relational Operator (<) Testing
    cout << "\n[Relational <] Comparing Distance 1 and Distance 2..." << endl;
    if (d1 < d2) {
        cout << "Result: Distance 1 is shorter than Distance 2." << endl;
    } else {
        cout << "Result: Distance 1 is NOT shorter than Distance 2." << endl;
    }

    return 0;
}

