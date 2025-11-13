#include <iostream>
using namespace std;

int main()
{
    int id, data1, data2, packet;
    cout << "Input ID: ";
    cin >> id;
    cout << "\nInput data1: ";
    cin >> data1;
    cout << "\nInput data2: ";
    cin >> data2;
    
    id = id << 15;
    data1 = data1 << 7;
    
    packet = id + data1 + data2;
    
    cout << packet;
}