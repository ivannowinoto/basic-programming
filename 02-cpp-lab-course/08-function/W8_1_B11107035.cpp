#include <iostream>
using namespace std;

int checkAnswer (char *sheet1, char *ans1)
{
	int correctAns = 0;
	for (int i = 0; i < 5; i++) {
		if (sheet1[i] == ans1[i]) {
			++correctAns;	
		}
	}
	return correctAns;
}

int main ()
{
	char sheet[5];
	char ans[5];
	
	for (int i = 0; i < 5; i++) {
		cin >> sheet[i];
	}
	
	for (int i = 0; i < 5; i++) {
		cin >> ans[i];
	}
	
	int score = checkAnswer(sheet, ans) * 20;
	cout << score << endl;
} 
