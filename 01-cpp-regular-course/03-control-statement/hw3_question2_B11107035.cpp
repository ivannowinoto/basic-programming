//B11107035 - 黃偉智
//homework 3 practice no2

#include <iostream>
using namespace std;

int main()
{
    float h, w, bmi = 0;
    
    cout << "Input height in metres: ";
    cin >> h;
    
    if (1.0 <= h && h <= 2.20) {
        cout << "Input weight in kilograms: ";
        cin >> w;
        if (30.0 <= w && w <= 200.0) {
            cout << "\nBMI: " << w / (h * h);
        }
        else cout << "Weight is out of range";
    }
    else cout << "Height is out of range";
    
    return 0;
}
