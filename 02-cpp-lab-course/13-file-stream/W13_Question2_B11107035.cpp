#include <iostream>
#include <string> 
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

int main()
{
	int ord;
	cin >> ord;
	
	srand(time(NULL));
	int c, e, m, s;
	
	if (ord == 1) {
		int n;
		string csv;
		cin >> n >> csv;
		
		fstream file;
		file.open(csv.c_str(), fstream::in | fstream::app);
		if (file.is_open()) {
			for (int i = 1; i <= n; i++) { 
				c = rand() % 100;
				e = rand() % 100;
				m = rand() % 100;
				s = rand() % 100;
				file << c << "," << e << "," << m << "," << s << endl;
			}
		}
		else cout << "File cannot be opened!" << endl; 
	}
	else if (ord == 2) {
		string csv;
		cin >> csv;
		
		fstream file;
		file.open(csv.c_str(), fstream::in | fstream::app);
		if (file.is_open()) {
			
			int i = 0;
			char comma;
			int cTot = 0, eTot = 0, mTot = 0, sTot = 0;
			
			while (file >> c) {
				file >> comma >> e >> comma >> m >> comma >> s;
				cTot += c;
				eTot += e;
				mTot += m;
				sTot += s;
				i++;
			}
			
			int cAvg = cTot / i;
			int eAvg = eTot / i;
			int mAvg = mTot / i;
			int sAvg = sTot / i;
			int total = (cAvg + eAvg + mAvg + sAvg) / 4;
			
			cout << "Chinese: " << cAvg << endl;
			cout << "English: " << eAvg << endl;
			cout << "Math: " << mAvg << endl;
			cout << "Society: " << sAvg << endl;
			cout << "Total: " << total << endl; 
		}
		else cout << "File cannot be opened!" << endl; 
	}	
	 
	 return 0;
} 
