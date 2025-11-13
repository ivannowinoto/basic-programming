#include <iostream>
using namespace std;

int main()
{
    int A, B;
    cout << "Input value of A: ";
    cin >> A;
    cout << "\nInput value of B: ";
    cin >> B;
    
    A = (A ^ B);
    B = (A ^ B);
    A = (A ^ B);
    
    cout << "A = " << A << endl;
    cout << "B = " << B;
}