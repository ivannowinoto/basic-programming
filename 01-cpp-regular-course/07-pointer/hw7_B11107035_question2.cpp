//C++ Week 7
//Second question
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
	
	int arr2[n];
	int max = 0, max2 = 0; 
	for (int i = 0; i < n; i++) {
		if (arr1[i] > max) {
			max2 = max;
			max = arr1[i];
			arr2[i] = max;
		} else if (arr1[i] > max2) {
			max2 = arr1[i];
			arr2[i] = max2;
		}
		
	}
	
	int arr3[n];
	int min = max, min2 = max2;
	for (int i = 0; i < n; i++) {
		if (arr1[i] < min) {
			min2 = min;
			min = arr1[i];
			arr3[i] = min;
		} else if (arr1[i] < min2) {
			min2 = arr1[i];
			arr3[i] = min2;
		}
	}
	
	int maxSum = max + max2;
	int minSum = min + min2;
	
	int *ptr;
	ptr = &maxSum;
	cout << "Max: " << *ptr << endl;
	
	int *ptr2;
	ptr2 = &minSum;
	cout << "Min: " << *ptr2 << endl; 
	
}
