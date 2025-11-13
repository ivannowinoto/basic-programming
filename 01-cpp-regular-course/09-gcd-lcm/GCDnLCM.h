// EE3405301 Lab09 GCD and LCM
// B11107035, 黃偉智
// GCD and LCM header file
// Dec. 12, 2022

#include <iostream>									
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Num_Fact {
	friend Num_Fact GCD(Num_Fact);					// declaring the Num_Fact friend functions; instead of taking two Num_Fact
	friend Num_Fact LCM(Num_Fact);					// objects for two numbers (A and B), this program is designed to take an
													// array or vector so that it will be able to run the Bonus question which
													// requires the user to input more than 2 numbers to find their GCD and LCM.
public:

	Num_Fact(vector<int> input, int n) {			// make the default constructor for Num_Fact objects.
		for (int i = 0; i < input.size(); i++) {	
			arr.push_back(0);						// the constructor only needs the value of vector
			arr[i] = input[i];						// and the value of how many numbers in the vector
		}											// in order to change the other private data members 
		Num = n;									// of the Num_Fact class.
	}
	
	string output(unsigned long long int n) {		// make a function that changes an integer to its prime factorization.
		
		string str;									// declare a string variable;
		if (n == 1) {								// if the input number is 1, then just
			str = "1";								// immediately return "1" to the value
			return str;								// of the string.
		}

		vector<int> v1;								// first step: make an empty vector to 
		while (n != 1) {							// store the prime factorization of a number.
			for (int i = 2; i <= n; i++) {			
				if (n % i == 0) {					// divide all the numbers accordingly from 2, 3, 5, 7, etc.
					v1.push_back(i);				
					n /= i;							// all the numbers inside the vector (factorization of a number) 
					break;							// will always be prime numbers.
				}
			}										// after this while loop, we will have a vector which
		}											// holds the value of every prime factorization of a number.
													// i.e. input is 1080, then the vector is {2, 2, 2, 3, 3, 3, 5}.

		int len = v1.size();						// second step: make another empty vector
		vector <int> v2;							// which has the same size as the previous vector
		for (int i = 0; i < len; i++) {				// and assign 0 to every values of the vector.
			v2.push_back(0);						
		}											// this will be used on the next step for comparison.

		for (int i = 0; i < len; i++) {				// third step: make another loop for checking
			if (v2[i] == 0) {						// the same numbers in the vector.
				int count = 0;
				for (int j = i; j < len; j++) {		// make another loop inside for comparing the
					if (v1[j] == v1[i]) {			// values of two vectors.
						count++;
						v2[j] = 1;					// if the same value is found, then increment counter by 1
					}								// and change the second vector value from 0 to 1
				}									// to indicate that it is already checked.

				int a = v1[i];						// fourth step: declare integers which hold the value of
				int b = count;						// the prime factorization (v1[i]) and its power (count).
				stringstream ssa, ssb;
				ssa << a;							// use the stringstream function to convert the integers to strings.
				ssb << b;							
				string str1 = ssa.str();			// this step is necessary because the data type that
				string str2 = ssb.str();			// we need to return is string, not integer.

				str += str1 + "^" + str2 + " * ";	// increment the string with the value of the
			}										// integers that we changed into strings and
		}											// also add the ^ and * notation into the string.

		str.pop_back();								// use the string pop_back() function 3 times
		str.pop_back();								// to delete the last " * " from the string.
		str.pop_back();
													
		return str;									// the final step is to just return the final value of the string.
	}

	int getNum() {									// make a function to access
		return Num;									// the value of Num data member.
	}

	unsigned long long int getResult() {			// make a function to access
		return result;								// the value of result data member.
	}

private:
	vector<int> arr;								// declaring data member arr which contains numbers that we want to find the GCD and LCM of.
	int Num;										// declaring data member Num which is the value of how much numbers in the arr data member.
	unsigned long long int result;					// declaring data member result which is the result of GCD or LCM of an array/vector of numbers.
};

unsigned long long int retGCD(int n1, int n2) {		// making a function that returns the GCD of two numbers.
	if (n2 == 0)									
		return n1;									// if the second number is 0 then return the first number.
	else
		return retGCD(n2, n1 % n2);					// as long as the if condition isn't fulfilled, the function will loop.
}

Num_Fact GCD(Num_Fact findGCD)						// making a function to find GCD of an array/vector of numbers.
{
	unsigned long long int ans = findGCD.arr[0];	// declare ans with the value of the first integer of an array/vector.
	int n = findGCD.Num;							// declare n with the value of amount of numbers in the array/vector.

	for (int i = 1; i < n; i++) {					// make a for loop to find the GCD of an array of numbers.
		ans = retGCD(findGCD.arr[i], ans);
		if (ans == 1) {								// if the GCD is one, then return 1 immediately.
			findGCD.result = 1;						// if the GCD is not one then it will continue to loop until
			return findGCD;							// the GCD is found.
		}
	}

	findGCD.result = ans;							// assign the value of ans to the result data member of object findGCD.
	return findGCD;									// return the findGCD object.
}

Num_Fact LCM(Num_Fact findLCM)						// making a function to find LCM of an array/vector of numbers.
{
	unsigned long long int ans = findLCM.arr[0];	// declare ans with the value of the first integer of an array/vector.
	int n = findLCM.Num;							// declare n with the value of amount of numbers in the array/vector.

	for (int i = 1; i < n; i++) {					// use the for loop to find the LCM of an array of numbers.
		ans = (findLCM.arr[i] * ans) / (retGCD(findLCM.arr[i], ans));
	}

	findLCM.result = ans;							// assign the data member result of findLCM object with the value of ans.
	return findLCM;									// return the findLCM object.
	
}

