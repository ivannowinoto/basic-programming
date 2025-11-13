// EE3405301 Lab08 Matrix Determinant
// B11107035, 黃偉智
// Nov. 28, 2022

#include <iostream>
#include <array>
#include <ctime>
#include "determinant.h"
using namespace std;

#ifndef N			// defining the constant N with the value of 21
#define N 21 
#endif

#define MAT2D array<array<double, N>, N>	// defining a two-dimensional array with the
											// max capacity of array[21][21].

void Input1(MAT2D&);						// define the Input function
double Det(MAT2D&, int);					// define the Det function

int main(void)
{
	time_t begin, end;											// call time_t to count elapsed time
	MAT2D A;													// "MAT2D A" equals to "array<array<double, N>, N> A"

	Input1(A);													// input the contents of matrix A
	time(&begin);												// begin the timer

	cout << "Det(A) = " << Det(A, dim);							// calling the Det function and
	cout << "\n (function called " << ::num << " times)\n";		// outputs the return value from it.

	time(&end);													// end the timer
	time_t elapsed = end - begin;								// count elapsed time
	cout << "execution time: " << elapsed << " secs." << endl;	// output the elapsed time

	return 0;
}