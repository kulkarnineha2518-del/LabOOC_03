#include <iostream> 
using namespace std; 

class Time { 
    private: 
    int hours;
    int minutes; 
    
    public: 
    // Simple constructor
    Time(int h = 0, int m = 0) {
        hours = h;
        minutes = m;
        
        // If minutes are 60 or more, convert them into hours
        if (minutes >= 60) {
            hours = hours + 1;
            minutes = minutes - 60;
        }
    } 
    
    // Simple add function
    Time add(const Time &t) { 
        int total_hours = hours + t.hours;
        int total_minutes = minutes + t.minutes;
        
        return Time(total_hours, total_minutes); 
    } 
    
    // Simple subtract function
    Time subtract(const Time &t) { 
        int total_minutes1 = (hours * 60) + minutes;
        int total_minutes2 = (t.hours * 60) + t.minutes;
        
        int difference_minutes = total_minutes1 - total_minutes2;
        
        // Convert total remaining minutes back into hours and minutes
        int final_hours = difference_minutes / 60;
        int final_minutes = difference_minutes % 60;
        
        return Time(final_hours, final_minutes); 
    } 
    
    // Simple display function
    void display() const { 
        cout << hours << " Hours and " << minutes << " Minutes" << endl; 
    } 
}; 

int main() { 
    // Using simple values where t1 is smaller and t2 is larger
    Time t1(4, 20); 
    Time t2(7, 10); 
    
    Time sum = t1.add(t2); 
    Time diff = t2.subtract(t1); 
    
    cout << "First Time: "; 
    t1.display(); 
    
    cout << "Second Time: "; 
    t2.display(); 
    
    cout << "Addition: "; 
    sum.display(); 
    
    cout << "Subtraction: "; 
    diff.display(); 
    
    return 0; 
}
