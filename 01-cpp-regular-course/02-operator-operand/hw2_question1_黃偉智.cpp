#include <iostream>
using namespace std;

int main()
{
    int a, b = 0;
    cout << "Input value of a: ";
    cin >> a;
    cout << "\nInput value of b:";
    cin >> b;
    
    int c = (a & b);
    int d = (a | b);
    
    cout << (c ^ d);
    
    return 0;
}