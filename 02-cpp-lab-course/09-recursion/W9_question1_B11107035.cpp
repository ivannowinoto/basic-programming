#include <iostream>
using namespace std;

int collatz_conj(int n);

int main () 
{
    int n;
    cin >> n;
    
    int counter = collatz_conj(n);
    cout << counter << endl;
    return 0;
}

int collatz_conj(int n)
{
    int count = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n /= 2;
            count++;
        } else {
            n *= 3;
            n += 1;
            count++;
        }
    }
    return count;
}
