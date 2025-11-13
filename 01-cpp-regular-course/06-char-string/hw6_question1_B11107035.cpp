#include <iostream>
#include <cstring>
using namespace std;

int main ()
{
    char pass[8];
    cin >> pass;
    
    bool flag;
    bool haveNumber = false, haveUpCase = false, haveLowCase = false;
    for (int i = 0; i < strlen(pass); i++)
    {
        if (pass[i] >= 48 && pass[i] <= 122)
        {
            if (pass[i] >= 58 && pass[i] <= 64)
            {
                flag = false;
                break;
            }
            else if (pass [i] >= 91 && pass [i] <= 96)
            {
                flag = false;
                break;
            }
            else
            {
                if (pass[i] >= 48 && pass[i] <= 57)
                {
                    haveNumber = true;
                    continue;
                }
                else if (pass[i] >= 65 && pass[i] <= 90)
                {
                    haveUpCase = true;
                    continue;
                }
                else if (pass[i] >= 97 && pass[i] <= 122)
                {
                    haveLowCase = true;
                    continue;
                }
            }
        }
        else 
        {
            flag = false;
            break;
        }
    }
    
    if (flag && haveNumber && haveUpCase && haveLowCase)
    {
        cout << "success" << endl;
    }
    else cout << "error" << endl;

}