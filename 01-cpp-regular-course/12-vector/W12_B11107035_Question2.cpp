#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	vector<int> v;
	int temp = 0;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	
	for (int k = 0; k < n; k++) {
		
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		} 
		cout << endl;
		v.erase(v.begin());
		for (int i = 0, j = v.size() - 1; i < j; i++, j--) {
			swap(v[i], v[j]);
		}
	}
}

