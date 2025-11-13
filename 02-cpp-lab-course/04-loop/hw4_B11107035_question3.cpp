#include <iostream>
using namespace std;

int main () 
{
	int n;
	cin >> n;

	if (n % 2 != 0)
	{
	   n = n / 2 + 1;
	   	for (int i = 1; i < n; i++)
	    {
    		for (int j = i; j <= n; j++)
    		{
    			cout << " ";
    		}
    		for (int k = 1; k < i; k++)
    		{
    			cout << "*";
    		}
    		for (int l = 1; l <= i; l++)
    		{
    			cout << "*";
    		}
		cout << endl;
	    }

	    for (int i = 1; i <= n; i++)
	    {
    		for (int j = 1; j <= i; j++)
    		{
    			cout << " ";
    		}
    		for (int k = i; k < n; k++)
    		{
    			cout << "*";
    		}
    		for (int l = i; l <= n; l++)
    		{
    			cout << "*";
    		}
    		cout << endl;
	    }
	}
    else cout << "Number invalid";
}