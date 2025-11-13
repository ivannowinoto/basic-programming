#include <iostream>
using namespace std;

void mix(int *a, int *b, int *c, int size) 
{
	int n = size;
	for (int i = 0; i < n * 2; i++) {
		if (i % 2 == 0) {
			c[i] = b[i / 2];
		} else {
			c[i] = a[i / 2];
		}
	}
}

int main()
{
	int n;
	cin >> n;
	
	int arr1[n];
	int arr2[n];
	int arr3[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	
	mix(arr1, arr2, arr3, n);
	for (int i = 0; i < n * 2; i++) {
		cout << arr3[i] << " ";
	}
	
}
 
