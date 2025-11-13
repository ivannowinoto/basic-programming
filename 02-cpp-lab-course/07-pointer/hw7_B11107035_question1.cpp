//C++ Week 7
//First question
//Ivanno Winoto (huang weizhi) B11107035 

#include <iostream>
using namespace std;

int main () {
	int n;
	cout << "Number of arrays: ";
	cin >> n;
	
	int arr1[n];
	cout << "Input " << n << " numbers: ";
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr1[i] == arr1[j]) {
				cout << *(arr1 + j) << " "; 
			}
		}
	}
} 
