#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
private:
    string name;
    int rollNo;
    string subjectNames[4];
    float marks[4];
    float total;
    float average;
    const float PASS_MARK = 40.0; // Minimum marks required to pass a subject

public:
    void inputDetails() {
        cout << "Enter Student Name: ";
        getline(cin >> ws, name);
        cout << "Enter Roll Number: ";
        cin >> rollNo;

        total = 0;
        for (int i = 0; i < 4; i++) {
            cout << "\nEnter Name for Subject " << (i + 1) << ": ";
            getline(cin >> ws, subjectNames[i]);
            cout << "Enter marks for " << subjectNames[i] << ": ";
            cin >> marks[i];
            total += marks[i];
        }
        average = total / 4.0;
    }

    void displayMarksheet() const {
        bool hasFailed = false;

        cout << "\n========================================";
        cout << "\n          STUDENT MARKSHEET             ";
        cout << "\n========================================";
        cout << "\nName      : " << name;
        cout << "\nRoll No.  : " << rollNo;
        cout << "\n----------------------------------------";
        cout << "\n" << left << setw(18) << "Subject" 
             << right << setw(7) << "Marks" 
             << setw(12) << "Result";
        cout << "\n----------------------------------------";
        
        for (int i = 0; i < 4; i++) {
            cout << "\n" << left << setw(18) << subjectNames[i] 
                 << right << setw(7) << fixed << setprecision(1) << marks[i] 
                 << right << setw(12);
            
            if (marks[i] >= PASS_MARK) {
                cout << "PASS";
            } else {
                cout << "FAIL";
                hasFailed = true;
            }
        }

        cout << "\n----------------------------------------";
        cout << fixed << setprecision(2);
        cout << "\nTotal Marks    : " << total << "/400";
        cout << "\nAverage Marks  : " << average;
        
        cout << "\nFinal Status   : ";
        if (hasFailed) {
            cout << "FAIL (Failed in one or more subjects)";
        } else {
            cout << "PASS";
        }
        cout << "\n========================================\n";
    }
};

int main() {
    Student s;
    s.inputDetails();
    s.displayMarksheet();
    return 0;
}
