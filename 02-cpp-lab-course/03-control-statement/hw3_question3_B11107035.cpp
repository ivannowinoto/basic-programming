//B11107035 - 黃偉智
//homework 3 practice no3

#include <iostream>
using namespace std;

int main()
{
    int a, b, c = 0;
    
    cout << "Input the side lengths of a triangle (3 numbers): ";
    cin >> a >> b >> c;
    
    if (a + b > c && a + c > b && b + c > a) {
        cout << "Three sides can form a triangle";
    }
    else cout << "Three sides cannot form a triangle";
    
    return 0;
}
