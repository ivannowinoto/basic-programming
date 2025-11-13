#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int blankCounter = 0;
    int n = s.length();
    
    for (int i = 0; i < n; i++)
    {
        if (i == 0) 
        {
            s[i] -= 32;
        }
        if(s[i] == ' ')
        {
            s[i + 1] -= 32;
            blankCounter++;
        }
    }
    cout << s << endl;
    for (int i = 0, n = s.length(); i < n; i++)
    {
        if (i == 0)
        {
            cout << s[i] << ".";
        }
        if (s[i] == ' ')
        {
            if(blankCounter != 1)
            {
                cout << s[i + 1] << ".";
            }
            blankCounter--;
        }
        if (blankCounter == 0)
        {
            cout << s[i];
        }
    }
}