#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    // Data members
    int productId;
    int quantity;
    double price;
    string productName;

public:
    // Method to accept user input
    void inputDetails() {
        cout << "Enter Product ID: ";
        cin >> productId;
        cin.ignore(); // Clears input buffer before reading string
        
        cout << "Enter Product Name: ";
        getline(cin, productName);
        
        cout << "Enter Quantity: ";
        cin >> quantity;
        
        cout << "Enter Price per unit: ";
        cin >> price;
    }

    // Method to calculate total bill amount
    double calculateBill() {
        return quantity * price;
    }

    // Method to display all product information
    void displayDetails() {
        cout << "\n===============================" << endl;
        cout << "        PRODUCT INVOICE        " << endl;
        cout << "===============================" << endl;
        cout << "Product ID   : " << productId << endl;
        cout << "Product Name : " << productName << endl;
        cout << "Price per Unit: " << price << endl;
        cout << "Quantity     : " << quantity << endl;
        cout << "-------------------------------" << endl;
        cout << "Total Amount : " << calculateBill() << endl;
        cout << "===============================" << endl;
    }
};

int main() {
    Product p;

    // Input data
    cout << "--- Enter Product Details ---" << endl;
    p.inputDetails();

    // Display data and final bill
    p.displayDetails();

    return 0;
}

