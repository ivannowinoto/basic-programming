#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    
    bool haveAlphabet[26];
    for (int i = 0; i < 26; i++) {
        haveAlphabet[i] = false;
    }
    
    int len = str.length();
    for (int i = 0; i < len; i++) {
        switch (str[i]) {
            case 97:
            haveAlphabet[0] = true;
            break;
            case 98:
            haveAlphabet[1] = true;
            break;
            case 99:
            haveAlphabet[2] = true;
            break;
            case 100:
            haveAlphabet[3] = true;
            break;
            case 101:
            haveAlphabet[4] = true;
            break;
            case 102:
            haveAlphabet[5] = true;
            break;
            case 103:
            haveAlphabet[6] = true;
            break;
            case 104:
            haveAlphabet[7] = true;
            break;
            case 105:
            haveAlphabet[8] = true;
            break;
            case 106:
            haveAlphabet[9] = true;
            break;
            case 107:
            haveAlphabet[10] = true;
            break;
            case 108:
            haveAlphabet[11] = true;
            break;
            case 109:
            haveAlphabet[12] = true;
            break;
            case 110:
            haveAlphabet[13] = true;
            break;
            case 111:
            haveAlphabet[14] = true;
            break;
            case 112:
            haveAlphabet[15] = true;
            break;
            case 113:
            haveAlphabet[16] = true;
            break;
            case 114:
            haveAlphabet[17] = true;
            break;
            case 115:
            haveAlphabet[18] = true;
            break;
            case 116:
            haveAlphabet[19] = true;
            break;
            case 117:
            haveAlphabet[20] = true;
            break;
            case 118:
            haveAlphabet[21] = true;
            break;
            case 119:
            haveAlphabet[22] = true;
            break;
            case 120:
            haveAlphabet[23] = true;
            break;
            case 121:
            haveAlphabet[24] = true;
            break;
            case 122:
            haveAlphabet[25] = true;
            break;
        }
    }
    
    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (haveAlphabet[i] == true) {
            ++count;
        }
    }

    if (count == 26) {
        cout << "Pangrams" << endl;
    } else cout << "Not pangram" << endl;

}
