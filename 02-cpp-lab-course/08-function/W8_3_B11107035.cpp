#include <iostream>
#include <cstring>
using namespace std;

void shiftString(char *str, int shift)
{
	int n = shift;
	int a = strlen(str);
	for (int i = 0; i < a; i++) {
		if (str[i] + n >= 91){
			str[i] += n % 26 - 26;
		} else str[i] += n; 
	}
}

int main()
{
	char input[1005];
	cin >> input;
	
	int n;
	cin >> n;
	
	shiftString(input, n);
	cout << input << endl;

}
