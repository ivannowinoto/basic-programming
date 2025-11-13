//B11107035 - 黃偉智
//homework 3 practice no1

#include <iostream>
using namespace std;

int main()
{
    int t = 0;
    
    cout << "Input temperature in Celcius: ";
    cin >> t;
    
    if (-100 <= t && t <= 100) {
        cout << t << " degree Celcius = " << t * 9 / 5 + 32 << " degree Fahrenheit" << endl;
    }
    
    else {
        cout << "Out of range" << endl;
    }
    
    return 0;
}
