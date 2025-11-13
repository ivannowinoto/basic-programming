#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	int arr[n][n];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	} 
	
	int a, b;
	cin >> a >> b;
	
	 for (int i = 0; i < n; i++) {
			int temp = arr[i][a];
			arr[i][a] = arr[i][b];
			arr[i][b] = temp;
		} 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	} 
} 
