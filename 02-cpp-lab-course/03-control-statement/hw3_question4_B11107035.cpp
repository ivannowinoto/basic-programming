//B11107035 - 黃偉智
//homework 3 practice no4

#include <iostream>
using namespace std;

int main()
{
    int a = 0;
    int b, c, d;
    
    cout << "Input a 8-digit number: ";
    cin >> a;
    
    b = a % 10;
    c = a / 10 % 10;
    d = a / 100 % 10;
    
    if (10000000 <= a && a <= 99999999) {
        if (b == 3 && c == 2 && d == 9) {
            cout << "Bingo!";
        }
        else cout << "Nope!";
    }
    else cout << "Number is out of range, please input an 8-digit number";
    
    return 0;
}
