// EE3405301 Lab09 GCD and LCM
// B11107035, 黃偉智
// Dec. 12, 2022

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <sstream>
#include "GCDnLCM.h"
using namespace std;

int main()
{
	cout << "-----GCD and LCM of two integers-----" << endl;	// separate the main question and the bonus question.

	int a, b;													// making two integer variables.
	cout << "Key in number A: ";								// input both numbers, A and B.
	cin >> a;
	cout << "Key in number B: ";
	cin >> b;

	vector<int> v1;												// for the main question, we only need to find the GCD and LCM of
	v1.push_back(a);											// two numbers. so it is the same as making a vector with 2 numbers
	v1.push_back(b);											// then calculating the GCD and LCM of the vector.

	Num_Fact find = Num_Fact(v1, 2);							// construct an object named find with the arr of v1 and Num of 2.
	Num_Fact ansGCD = GCD(find);								// declare another object named ansGCD and assign it with the value of 
	Num_Fact ansLCM = LCM(find);								// object find, which values has been modified by the GCD function.
																// this goes the same with the ansLCM object.

	unsigned long long int GCD2Num = ansGCD.getResult();		// assign the result of ansGCD object to GCD2Num unsigned long long integer.
	unsigned long long int LCM2Num = ansLCM.getResult();		// assign the result of ansLCM object to LCM2Num unsigned long long integer.

	cout << " A = " << ansGCD.output(a) << " = " << a << endl;	// printing the value of A number and its factorization.
	cout << " B = " << ansLCM.output(b) << " = " << b << endl;	// printing the value of B number and its factorization.

	cout << " GCD(A, B) = " << ansGCD.output(GCD2Num) << " = " << GCD2Num << endl;			// printing the GCD of 2 numbers and its factorization.
	cout << " LCM(A, B) = " << ansLCM.output(LCM2Num) << " = " << LCM2Num << endl << endl;	// printing the LCM of 2 numbers and its factorization.

	
	cout << "-----GCD and LCM of n integers-----" << endl;		// bonus question: GCD and LCM of n numbers

	int n;														// make an integer n and assign it
	cout << "How many numbers will you input? ";				// to the user input as how many numbers
	cin >> n;													// that the user wants to input.

	vector<int> v2;												// make another vector to hold the values of the numbers
																// that the user wants to find the GCD and LCM of.
	int temp = 0;
	for (int i = 0; i < n; i++) {								// receiving user input with the amount of n,
		cin >> temp;											// and directly assigning the numbers inputted
		v2.push_back(temp);										// into the vector v2.
	}

	Num_Fact find2 = Num_Fact(v2, n);							// construct an object named find2 with the arr of v2 and Num of n.
	Num_Fact ansGCD2 = GCD(find2);								// declare another object named ansGCD2 and assign it with the value of 
	Num_Fact ansLCM2 = LCM(find2);								// object find2, which values has been modified by the GCD function.
																// this goes the same with the ansLCM2 object.

	unsigned long long int GCDnNum = ansGCD2.getResult();		// assign the result of ansGCD2 object to GCDnNum unsigned long long integer.
	unsigned long long int LCMnNum = ansLCM2.getResult();		// assign the result of ansLCM2 object to LCMnNum unsigned long long integer.

	cout << "GCD(";												// printing out the result of GCD of n numbers.
	for (int i = 0; i < n; i++) {
		if (i == n - 1)											// if the for loop is on the last index, then print the number and ')'.		
			cout << v2[i] << ")";
		else													// if the for loop is not on the last index, then print the number and ','.
			cout << v2[i] << ",";
	}
	cout << " = " << ansGCD2.output(GCDnNum) << " = " << GCDnNum << endl;	// print out the GCD of n numbers and its factorization.

	cout << "LCM(";												// printing out the result of LCM of n numbers.
	for (int i = 0; i < n; i++) {
		if (i == n - 1)											// if the for loop is on the last index, then print the number and ')'.			
			cout << v2[i] << ")";
		else													// if the for loop is not on the last index, then print the number and ','.
			cout << v2[i] << ",";
	}
	cout << " = " << ansLCM2.output(LCMnNum) << " = " << LCMnNum << endl;	// print out the LCM of n numbers and its factorization.

	return 0;
}