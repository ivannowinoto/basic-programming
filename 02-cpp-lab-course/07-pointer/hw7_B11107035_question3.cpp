//C++ Week 7
//Third question
//Ivanno Winoto (huang weizhi) B11107035 

#include <iostream>
using namespace std;

int main () {
	int n;
	cout << "Amount of winning numbers: ";
	cin >> n;
	
	int arr[n];
	for (int i = 0; i < n; i++) {
		cout << "Winning number " << i + 1 << " : ";
		cin >> arr[i];
	}
	
	cout << "Number to redeem : ";
	cin >> arr[n];
	
	for (int i = 0; i < n; i++) {
		if (arr[i] == arr[n]) {
			cout << arr[i];
			return 0;
		}
		else if (arr[i] % 10000000 == arr[n] % 10000000) {
			cout << arr[i] % 10000000;
			return 0;
		}
		else if (arr[i] % 1000000 == arr[n] % 1000000) {
			cout << arr[i] % 1000000;
			return 0;
		}
		else if (arr[i] % 100000 == arr[n] % 100000) {
			cout << arr[i] % 100000;
			return 0;
		}
		else if (arr[i] % 10000 == arr[n] % 10000) {
			cout << arr[i] % 10000;
			return 0;
		}
		else if (arr[i] % 1000 == arr[n] % 1000) {
			cout << arr[i] % 1000;
			return 0;
		}
	}
	
	cout << "NO" << endl;

}

