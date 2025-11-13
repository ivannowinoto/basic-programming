//C++ week 5 homework
//Ivanno Winoto (Huang Weizhi) B11107035
//third question 

#include <iostream>
using namespace std;

int main () 
{
	int n;
	cout << "Number of arrays: ";
	cin >> n;
	
	int arr[n];
	cout << "Input elements of array: ";
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	
	bool arrTry[10] = {false};
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		arrTry[arr[i]] = true;	
	}
	
	for (int i = 0; i < 10; i++)
	{
		if (arrTry[i] == true)
		{
			counter++;
		}
	}
		
	cout << counter; 
}
