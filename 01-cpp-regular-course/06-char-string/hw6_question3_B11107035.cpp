#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int n = s.length();
    for (int i = 0; i < n/2; i++, n--)
    {
        if (s[i] != s[n - 1])
        {
            cout << "No" << endl;
            return 0;
        }
        else continue;
    }
    cout << "Yes" << endl;
}