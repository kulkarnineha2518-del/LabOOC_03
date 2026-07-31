#include<iostream>
using namespace std;
int main()
{
    int *arr;
    int size;
    cout<<"Enter the size of integer array:";
    cin>>size;
    cout<<"Creating an array of size "<<size<<"..";
    arr = new int[size];
    cout<<"\nDynamic allocation of memory for array arr is successful.";
     int sum = 0;
    cout << "Enter " << size << " numbers:\n";
    for(int i = 0; i < size; i++) 
    {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << "The sum of the entered numbers is: " << sum << "\n";


    delete arr;
    return 0;
}
