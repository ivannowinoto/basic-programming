// EE3405301 Lab08 Matrix Determinant
// Determinant.h header file
// B11107035, 黃偉智
// Nov. 28, 2022

#include <iostream>
#include <array>
#include <iomanip>
using namespace std;

#ifndef N									// defining the constant N with the value of 21
#define N 21
#endif

#define MAT2D array<array<double, N>, N>	// defining a two-dimensional array
int num = 0;								// num is to count how many times the function has been called
int dim = 0;								// dim is the size of the matrix

void Input1(MAT2D& matrix)	// making the input function
{
	int size;			// inputting the size (the first line of each files)
	cin >> size;
	dim = size;			// storing the size in the dim variable

	for (int i = 0; i < size; i++) {			// inputting each values of the matrix
		for (int j = 0; j < size; j++) {
			cin >> matrix[i][j];
		}
	}

	cout << "Matrix A[" << size << "][" << size << "] is" << endl;	// outputting each values of the matrix
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			cout << right << setw(3) << matrix[i][j];
		}
		cout << endl;
	}
}

double Det(MAT2D& matrix, int n)	// making the Det function
{
	MAT2D subMatrix;				// define another matrix for sub-matrix
	double sum = 0;					// define the result of the determinant

	switch (n) {				// use switch case instead of if-else to make program faster
	case 1:
		num++;
		sum = matrix[0][0];		// if size of matrix is one, then determinant is the matrix itself
		break;
	case 2:
		num++;
		sum = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);	// count the determinant of 2x2 matrix
		break;
	case 3:
		num++;
		sum = matrix[0][0] * ((matrix[1][1] * matrix[2][2]) - (matrix[2][1] * matrix[1][2]))		// count the determinant of 3x3 matrix
			- matrix[1][0] * ((matrix[0][1] * matrix[2][2]) - (matrix[2][1] * matrix[0][2]))		// manually to make the program faster.
			+ matrix[2][0] * ((matrix[0][1] * matrix[1][2]) - (matrix[1][1] * matrix[0][2]));
		break;
	case 4:
		num++;
		sum = (matrix[0][3] * matrix[1][2] * matrix[2][1] * matrix[3][0]) - (matrix[0][2] * matrix[1][3] * matrix[2][1] * matrix[3][0]) -	// count the determinant
			(matrix[0][3] * matrix[1][1] * matrix[2][2] * matrix[3][0]) + (matrix[0][1] * matrix[1][3] * matrix[2][2] * matrix[3][0]) +		// of 4x4 matrix manually
			(matrix[0][2] * matrix[1][1] * matrix[2][3] * matrix[3][0]) - (matrix[0][1] * matrix[1][2] * matrix[2][3] * matrix[3][0]) -		// to make the program
			(matrix[0][3] * matrix[1][2] * matrix[2][0] * matrix[3][1]) + (matrix[0][2] * matrix[1][3] * matrix[2][0] * matrix[3][1]) +		// even faster.
			(matrix[0][3] * matrix[1][0] * matrix[2][2] * matrix[3][1]) - (matrix[0][0] * matrix[1][3] * matrix[2][2] * matrix[3][1]) -
			(matrix[0][2] * matrix[1][0] * matrix[2][3] * matrix[3][1]) + (matrix[0][0] * matrix[1][2] * matrix[2][3] * matrix[3][1]) +
			(matrix[0][3] * matrix[1][1] * matrix[2][0] * matrix[3][2]) - (matrix[0][1] * matrix[1][3] * matrix[2][0] * matrix[3][2]) -
			(matrix[0][3] * matrix[1][0] * matrix[2][1] * matrix[3][2]) + (matrix[0][0] * matrix[1][3] * matrix[2][1] * matrix[3][2]) +
			(matrix[0][1] * matrix[1][0] * matrix[2][3] * matrix[3][2]) - (matrix[0][0] * matrix[1][1] * matrix[2][3] * matrix[3][2]) -
			(matrix[0][2] * matrix[1][1] * matrix[2][0] * matrix[3][3]) + (matrix[0][1] * matrix[1][2] * matrix[2][0] * matrix[3][3]) +
			(matrix[0][2] * matrix[1][0] * matrix[2][1] * matrix[3][3]) - (matrix[0][0] * matrix[1][2] * matrix[2][1] * matrix[3][3]) -
			(matrix[0][1] * matrix[1][0] * matrix[2][2] * matrix[3][3]) + (matrix[0][0] * matrix[1][1] * matrix[2][2] * matrix[3][3]);
		break;
	default:
		for (int i = 0; i < n; i++) {								// begin the algorithm to find the determinant of matrix
			int subCol = 0;											// declare a variable for subMatrix column
			for (int j = 1; j < n; j++) {
				int subRow = 0;										// declare a variable for subMatrix row
				for (int k = 0; k < n; k++) {
					if (k == i)										// if k is equal to i then skip to next index
						continue;
					subMatrix[subCol][subRow] = matrix[j][k];		// set the subMatrix equal to matrix
					subRow++;										// increment subRow by 1
				}
				subCol++;											// increment subCol by 1
			}
			sum += (i % 2 ? -1.0 : 1.0) * matrix[0][i] * Det(subMatrix, n - 1);		// determinant: -1 or 1 times matrix times the determinant of subMatrix
			num++;																	// increment num for the counter
		}
	}
	return sum;			// the function returns the value of sum, which is the determinant itself
}





