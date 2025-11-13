#include <iostream>
using namespace std;

int main ()
{
    int a, b;
    
    cout << "Enter two numbers: ";
    cin >> a >> b;
    
    int c = a;
    int d = b;
    
    while (a % b != 0)
    {
        int i = a % b;
        a = b;
        b = i;
    }
    
    cout << "Greatest Common Divisor: " << b << endl;
    
    c = c / b;
    d = d / b;
    int lcm = b * c * d;
    
    cout << "Least Common Multiplier: " << lcm << endl;
}