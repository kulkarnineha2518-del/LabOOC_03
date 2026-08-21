#include <iostream>
using namespace std;

class Time {
    public:
    int hours;
    int minutes;
    
    // Simple constructor
    Time(int h = 0, int m = 0) {
        hours = h;
        minutes = m;
    }
    
    // Simple add function
    Time add(Time t) { 
        int total_h = hours + t.hours;
        int total_m = minutes + t.minutes;
        
        // If minutes cross 60, change them to 1 hour
        if (total_m >= 60) {
            total_h = total_h + 1;
            total_m = total_m - 60;
        }
        
        return Time(total_h, total_m); 
    }
    
    // Simple display function
    void display() { 
        cout << hours << " Hours and " << minutes << " Minutes" << endl; 
    }
};

int main() {
    int h1, m1, h2, m2;
    
    // Taking input for Time 1
    cout << "Enter Time 1 Hours: ";
    cin >> h1;
    cout << "Enter Time 1 Minutes: ";
    cin >> m1;
    
    // Taking input for Time 2
    cout << "Enter Time 2 Hours: ";
    cin >> h2;
    cout << "Enter Time 2 Minutes: ";
    cin >> m2;
    
    // Creating the Time objects with user inputs
    Time t1(h1, m1);
    Time t2(h2, m2);
    
    // Adding and showing the result
    Time result = t1.add(t2);
    
    cout << "\nTotal Combined Time: ";
    result.display();
    
    return 0;
}
