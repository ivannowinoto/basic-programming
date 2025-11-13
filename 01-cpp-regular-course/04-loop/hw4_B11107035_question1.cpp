#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main () {
	srand (time(NULL));
	int m = rand();
    m = m % 100;
    
    int n;
    cout << "Input a number: ";
    cin >> n;
    
    int upperLimit = 100;
    int lowerLimit = 0;
    
    if (lowerLimit < n && n < upperLimit) 
    {
      while (n != m) 
      {
        if (lowerLimit > n || n > upperLimit)
        {
         cout << "Invalid input";
         break;
        }
        else if (n > m) 
        {
            upperLimit = n;
            cout << "Range: " << lowerLimit << " - " << upperLimit << endl;
            cout << "Input number again: ";
            cin >> n;
        }
        else if (n < m) 
        {
            lowerLimit = n;
            cout << "Range: " << lowerLimit << " - " << upperLimit << endl;
            cout << "Input number again: ";
            cin >> n;
        }
      }
      if (n == m) 
      {
          cout << "Bang!!";
      }
       
    }
    else cout << "Invalid input";
}