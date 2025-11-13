//C++ week 5 homework
//Ivanno Winoto (Huang Weizhi) B11107035
//first question 

#include <iostream>
using namespace std;

int main () 
{
	int n;
	cout << "Number of arrays: ";
	cin >> n;
	
	int arr1[n];
	cout << "Input elements of array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr1[i];
	}
	
	int spoint, tlr;
	cout << "Input start point and tolerance: ";
	cin >> spoint >> tlr;
	
	int arr2[n];
	for (int i = 0; i < n; i++)
	{
		arr2[i] = spoint + i * tlr;
	}
	
	bool isComposed;
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] == arr2[i])
		{
			isComposed = true;
		} 
		else isComposed = false;
	}
	
	if (isComposed)
	{
		cout << "True";
	}
	else cout << "False";
}


