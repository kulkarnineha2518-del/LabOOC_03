#include <iostream>
#include <string>
using namespace std;

class Employee {
    public:
    int employeeId;
    string branch;
    string designation;
    float basicSalary;
    float grossSalary;

    void inputData() {
        cout << "Enter Employee ID: ";
        cin >> employeeId;
        
        cout << "Enter Branch Name: ";
        getline(cin >> ws, branch);
        
        cout << "Enter Designation: ";
        getline(cin, designation);
        
        cout << "Enter Basic Salary: ";
        cin >> basicSalary;
        
        grossSalary = basicSalary + (0.20f * basicSalary) + (0.10f * basicSalary);
    }

    void displayData() const {
        cout << "\n       Employee Details       \n";
        cout << "==============================\n";
        cout << "Employee ID  : " << employeeId << endl;
        cout << "Branch       : " << branch << endl;
        cout << "Designation  : " << designation << endl;
        cout << "Basic Salary : $" << basicSalary << endl;
        cout << "Gross Salary : $" << grossSalary << endl;
    }
};

int main() {
    Employee emp;
    emp.inputData();
    emp.displayData();
    return 0;
}
