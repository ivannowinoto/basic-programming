// EE3405301 Lab01 Unit Conversation
// B11107035, 黃偉智
// Sept. 16, 2022

//Transfer the unit to US Customary units

#include <iostream>
using namespace std;

int main()
{
    int cm, ft, in;
    cout << "Input length in centimeter: ";
    cin >> cm;

    //1 ft = 12 in, 1 in = 2.54cm

    ft = cm / (2.54 * 12);
    in = (cm - (ft * 12 * 2.54)) / 2.54;

    cout << "Length in US Customary units: " << ft << " feet " << in << " inches.";

    return 0;
}