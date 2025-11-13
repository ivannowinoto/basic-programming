// EE3405301 Lab07 Pandita Permutations
// Pandita.h: function declarations
// B11107035, 黃偉智
// Nov. 21, 2022

#include <iostream>
using namespace std;

int compare(const void* a, const void* b)	// make a function for comparing two characters
{
	char x = *(char*)a;		// make a variable for storing value of char
	char y = *(char*)b;		// make another variable for storing another char
	return x - y;			// return the difference between two chars
}

void swap(char* a, char* b)		// make a function for swapping two characters
{
	char temp = *a;			// declare a temporary variable for storing the value
	*a = *b;				// swap a and b
	*b = temp;				// swap b and a (before a was changed)
}

void reverse(char a[], int i, int j)	// make a function for reversing the order of characters
{
	while (i < j)				// while i is less than j
	{
		swap(&a[i], &a[j]);		// swap both characters
		i++;					// add i by 1
		j--;					// subtract j by 1
	}
}

int getIndex(char a[], char first, int i, int j)	// make a function for getting the index
{													// this function will be used on the second step of Pandita's algorithm,
	int index = i;									// where we need to find largest index k such that A[j]<A[k].
	for (int k = i + 1; k <= j; k++) {		
		if (a[k] > first && a[k] < a[index]) {
			index = k;
		}
	}

	return index;			// return the value of index
}

template <class T>

int Pandita(T a[], int size)		// making the Pandita function for the permutation
{
	qsort(a, size, sizeof(a[0]), compare);	// because we need to print the permutation in a lexicographical order,
											// we need to first sort all of the characters before continuing.
											// use the sort function to sort all of the characters

	bool isValid = false;			// make a boolean variable for controlling the while loop
	int counter = 1;				// make a counter variable
	while (isValid == false)
	{
		cout << "permutation #" << counter << ": ";		// printing out the characters
		for (int i = 0; i < size; i++) {	
			cout << a[i] << " ";
		}
		cout << endl;
		++counter;			// after printing out the characters, increment counter by 1

		int j;		// make another variable
		for (j = size - 2; j >= 0; j--) {	// this for loop runs the first step of Pandita's algorithm:
			if (a[j] < a[j + 1]) {			// "1) Find the largest index j such that A[j] < A[j+1].
				break;						// If no such index exists, the permutation is the last permutation."
			}
		}

		if (j == -1) {			// j is -1 when no such index exists, 
			isValid = true;		// thus the permutation is the last permutation and immediately ends the while loop.
		}
		else
		{
			// step 2 of Pandita's algorithm: "Find the largest index k such that A[j]<A[k]."
			// the index found using getIndex function is the largest index k
			int index = getIndex(a, a[j], j + 1, size - 1);		

			// step 3 of Pandita's algorithm: "Swap A[j] with A[k]."
			// call the swap function and swap both characters
			swap(&a[j], &a[index]);

			// step 4 of Pandita's algorithm: "Reverse the sequence from A[j+1] up to ad including the last element A[N-1]."
			// call the reverse function and reverse the characters order.
			reverse(a, j + 1, size - 1);
		}
	}

	return counter - 1;		// because this function must return a value,
							// then return the value of counter since it represents
							// the amount of permutations found by using this algorithm.
}