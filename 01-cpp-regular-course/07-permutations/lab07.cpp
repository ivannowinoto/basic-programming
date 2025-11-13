// EE3405301 Lab07 Pandita Permutations
// B11107035, 黃偉智
// Nov. 21, 2022

#include <iostream>
#include "Pandita.h"
using namespace std;

template<class T> int Pandita(T a[], int size);		// function template prototype
#define N 4
int main(void)
{
	char a[5]{ "abcd" };							// initial N-element array 
	cout << "N-element Array Permutation (N =" 
		<< N << ')' << endl;						// output message 
	int num = Pandita(a, 4);						// call function template 
	cout << "Total number of permutations is " 
		<< num << endl;								// output message 
	
	return 0;
}