// EE3405301 Lab10 Structure & Pointer
// B11107004, ªô¦ö»¨
// Dec. 24, 2022

#include <iostream>
#include <sstream>
#include "num_factor.h"
using namespace std; 
int main() { 
	int n; // declare n
	cout << "How many numbers will you input: "; // how many numbers input: 
	cin >> n;
	Num_Fact nums[100]; // build class Num_Fact input array
	Num_Fact gcd; // class of GCD
	Num_Fact lcm; // class of LCM
	Num_Fact gcdtemp; // class Num_Fact of GCD when input numbers is bigger than 2, have to use it to count LCM
	for (int i = 0; i < n; i++) { 
		__int64 num; 
		cin >> num; // input number
		nums[i].set(num); // set num nums[i]
	}
	gcd = nums[0]; // gcd = first number
	lcm = nums[0]; // lcm = first number
	for (int i = 0; i < (n - 1); i++) {
		gcd = GCD(gcd, nums[i + 1]); // the gcd will be the previous gcd and the next number's gcd
		gcdtemp = GCD(lcm, nums[i + 1]); // get the previous lcm and next number's gcd to calculate their LCM
		lcm = LCM(lcm, nums[i + 1], gcdtemp); // lcm will be previous lcm and next number's lcm
	}
	for (int i = 0; i < n; i++) {
		cout << nums[i].getnum() << " = " << nums[i].output() << endl; // num = num's factorize
	}
	cout << "GCD(";
	for (int i = 0; i < n-1; i++) {
		cout << nums[i].getnum() << ","; 
	}
	cout << nums[n - 1].getnum() << ") = "; 
	cout << gcd.output() << " = " << gcd.getnum() << endl; // GCD factorize = GCD(number)
	cout << "LCM("; // LCM(
	for (int i = 0; i < n - 1; i++) { 
		cout << nums[i].getnum() << ","; 
	}
	cout << nums[n - 1].getnum() << ") = "; 
	cout << lcm.output() << " = " << lcm.getnum() << endl; // LCM factorize = LCM(number)
}