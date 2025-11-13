#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n1;
	int temp1 = 0;
	vector<int> v1;
	
	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> temp1;
		v1.push_back(temp1);
	} 
	
	int n2;
	int temp2 = 0;
	vector<int> v2;
	
	cin >> n2;
	for (int i = 0; i < n2; i++) {
		cin >> temp2;
		v2.push_back(temp2);
	} 
	
	vector<int> v3;

	vector<int>::iterator iter;
	for (int i = 0; i < n1; i++) {
		iter = find(v2.begin(), v2.end(), v1[i]);
		if (iter == v2.end()) {
			v3.push_back(v1[i]);
		}
	}	
	
	
	for (int i = 0; i < n2; i++) {
		iter = find(v1.begin(), v1.end(), v2[i]);
		if (iter == v1.end()) {
			v3.push_back(v2[i]);
		}
	}
	
	for (int i = 0; i < v3.size(); i++) {
		for (int j = i + 1; j < v3.size(); j++) {
			if (v3[i] > v3[j]) {
				int temp = v3[i];
				v3[i] = v3[j];
				v3[j] = temp;
			}
		} 
	}
	
	for (int i = 0; i < v3.size(); i++) {
		cout << v3[i] << " ";
	} 
	
} 
