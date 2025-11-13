#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    char c;
    
    getline(cin, str);
    cin >> c;
    
    int len = str.length();
    for (int i = 0; i < len; i++) {
        if (str[i] == c) {
            str[i] = '\n';
        }
    }
    cout << str;
}
