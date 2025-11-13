#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	string str[n];
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	
	bool haveAlphabet[n][26];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
        	haveAlphabet[i][j] = false;
		}
    }
    
    for (int i = 0; i < n; i++) {
	    int len = str[i].length();
	    for (int j = 0; j < len; j++) {
	        switch (str[i][j]) {
	            case 97:
	            	haveAlphabet[i][0] = true;
	           		break;
	            case 98:
	            	haveAlphabet[i][1] = true;
	            	break;
	            case 99:
	            	haveAlphabet[i][2] = true;
	            	break;
	            case 100:
	            	haveAlphabet[i][3] = true;
	            	break;
	            case 101:
	            	haveAlphabet[i][4] = true;
	            	break;
	            case 102:
	            	haveAlphabet[i][5] = true;
	            	break;
	            case 103:
	            	haveAlphabet[i][6] = true;
	            	break;
	            case 104:
	            	haveAlphabet[i][7] = true;
	            	break;
	            case 105:
	            	haveAlphabet[i][8] = true;
	            	break;
	            case 106:
	            	haveAlphabet[i][9] = true;
	            	break;
	            case 107:
	            	haveAlphabet[i][10] = true;
	            	break;
	            case 108:
	            	haveAlphabet[i][11] = true;
	            	break;
	            case 109:
	            	haveAlphabet[i][12] = true;
	            	break;
	            case 110:
	            	haveAlphabet[i][13] = true;
	            	break;
	            case 111:
	            	haveAlphabet[i][14] = true;
	            	break;
	            case 112:
	            	haveAlphabet[i][15] = true;
	            	break;
	            case 113:
	            	haveAlphabet[i][16] = true;
	            	break;
	            case 114:
	            	haveAlphabet[i][17] = true;
	            	break;
	            case 115:
	            	haveAlphabet[i][18] = true;
	            	break;
	            case 116:
	            	haveAlphabet[i][19] = true;
	            	break;
	            case 117:
	            	haveAlphabet[i][20] = true;
	            	break;
	            case 118:
	            	haveAlphabet[i][21] = true;
	            	break;
	            case 119:
	            	haveAlphabet[i][22] = true;
	            	break;
	            case 120:
	            	haveAlphabet[i][23] = true;
	            	break;
	            case 121:
	            	haveAlphabet[i][24] = true;
	            	break;
	            case 122:
	            	haveAlphabet[i][25] = true;
	            	break;
	        }
	    }	
	}
	
	int arr[26] = { 0 };
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
        	if (haveAlphabet[i][j] == true) {
        		arr[j]++;
			}
		}
    }
    
    int counter = 0;
    for (int j = 0; j < 26; j++) {
		if (arr[j] == n) {
			counter++;
		}
	}
    cout << counter << endl;
    return 0;
}

