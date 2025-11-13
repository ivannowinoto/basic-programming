//C++ week 5 homework
//Ivanno Winoto (Huang Weizhi) B11107035
//second question

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
	
	int s;
	int arr2[n];
	cout << "Input the number to be searched: ";
	cin >> s;
	for (int i = 0; i < n; i++)
	{
		arr2[i] = s;
	}
	
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		if (arr1[i] == arr2[i])
		{
			counter++;
		}
	}
	cout << counter;
}
