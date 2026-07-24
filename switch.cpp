int main() 
void add();
void sub();
void mult();
void division();




{
    int num1, num2;
    
    
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
   

    
    for (int  i = 1; i <= 4; i++)
    {
        switch (i) 
        {
            case 1:
                mult(num1, num2);
                break;
                
            case 2:
                division(num1, num2);
                break;

            case 3:
               add(num1, num2);
                break;

            case 4:
                sub(num1, num2);
                break;
        }
    }

    return 0;
}