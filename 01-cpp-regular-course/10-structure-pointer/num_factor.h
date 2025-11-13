// EE3405301 Lab10 Structure & Pointer
// B11107004,ªô¦ö»¨
// Dec. 24, 2022


#ifndef NUM_FACTOR
#define NUM_FACTOR
#include<iostream>
#include <sstream>
using namespace std;
#define DEBUG 1
#define ADDRESS 1

typedef struct factor Fact;// declare a new struct type name factor, and set a Fact which type is factor 
typedef struct factor {
	int prime; // save the factor number
	int power; // save number's power
	Fact* ptr; // save the next location
	factor(int pr = 0, int po = 0, Fact* tptr = nullptr) :prime(pr), power(po), ptr(tptr) {}; // struct constructor
}Fact;
class Num_Fact {// build a class
	friend Num_Fact GCD(Num_Fact& A, Num_Fact& B);	// build a friend (type Num_Fact) GCD function (Num_Fact A, Num_Fact B)
	friend Num_Fact LCM(Num_Fact& A, Num_Fact& B, Num_Fact& gcd);	// build a friend (type Num_Fact) LCM function (Num_Fact A, Num_Fact B, Num_Fact gcd)
private:
	__int64 Num;
	Fact* head = nullptr;
public:
	Fact* Factorize() {
		__int64 i = 2; // the fact start from 2
		__int64 x = Num; // x store Num
		int facts{ 0 }; // how many facts there are
		while (x != 1) {
			int power{ 0 };	
			while (x % i == 0) {
				x = x / i; 
				power++; 
			}
			if (power > 0) { 
				facts++; 
				if (head == nullptr) {
					Fact* node = new Fact();
					node->prime = i; // the node's prime store factor
					node->power = power; // the node's power store power
					node->ptr = nullptr; // there is no next one for now, so node's ptr is NULL
					head = node; // head is node
				}
				else {
					Fact* node = new Fact(); // build a name node
					Fact* temp = head; // build a temp Fact, it = head
					node->prime = i; // the node's prime store factor
					node->power = power; // the node's power store power
					node->ptr = nullptr; // there is no next one for now, so node's ptr is NULL
					// find the last factor's location
					while (temp->ptr != nullptr) { // if this temp is not last one 
						temp = temp->ptr; // temp = the next one
					}
					temp->ptr = node; // connect node to the last one
				}
			}
			i++;
		}
		return head;// return head
	}
	void set(__int64 num) { Num = num; head = Factorize(); }; // set num = Num, and do Factorize
	
	string output() { // output function
		string st{ 0 }; // build a string to store Factorize (fact^power * fact^power *.....)
		string a, pw; // a to store the fact; pw to store fact's power
		string pos;// its location
		stringstream ss; // set a stringstream ss to change number int into string
		if (head == nullptr) { // if it has no fact biger than 1
			st = " 1 "; // it's fact only 1
		}
		else {
			while(head->ptr != nullptr) { // do (Facts - 1) times
				ss.str(""); // initializ ss
				ss.clear(); // initializ ss
				ss << head->prime; // put int fact into ss
				ss >> a; // change the fact from int into string and store in a
				st += a; // store a into st
				ss.str(""); // initializ ss
				ss.clear(); // initializ ss
				ss << head->power; // put int power into ss
				ss >> pw; // change teh power from int into string and store in pw
				st += "^" + pw; // store ^ pw into st, then st will be fact^power 
				ss.str(""); // initializ ss
				ss.clear(); // initializ ss
				ss << head; // put head(location) into ss
				ss >> pos; // change the location from pointer into string and store in pos
				st += "(" + pos + ")" + " * ";// store (pos) * into st, then st will be fact^power(location) * 
				head = head->ptr;
			}
			ss.str(""); // initializ ss
			ss.clear(); // initializ ss
			ss << head->prime; // put the last int fact into ss
			ss >> a; // change the last fact from int into string and store in a
			st += a; // store a into st
			ss.str(""); // initializ ss
			ss.clear(); // initializ ss
			ss << head->power; // put int power into ss
			ss >> pw; // change teh power from int into string and store in pw
			st += "^" + pw; // store ^ pw into st, then st will be ....fact^power
			ss.str(""); // initializ ss
			ss.clear(); // initializ ss
			ss << head; // put head(location) into ss
			ss >> pos; // change the location from pointer into string and store in pos
			st += "(" + pos + ")";// store (pos) * into st, then st will be ....fact^power(location)
		}
		return st; // return the Factorize
	}
	__int64 getnum() { // to get Num
		return Num; // return Num back
	}

};

Num_Fact GCD(Num_Fact& A, Num_Fact& B) { // to get GCD(A, B), use Euclidean Algorithm
	Num_Fact C; // build a class Num_Fact C to store GCD
	int big, small; // set big number and small number
	if (A.Num > B.Num) { // if A > B
		big = A.Num; // B is the big one
		small = B.Num; // A is the small one
	} // B > A
	else {
		big = B.Num;	// B is the big
		small = A.Num;	// A is the small
	}
	while (small != 0) { 
		int temp = small; 
		small = big % small;
		big = temp; 
	}
	C.set(big);
	return C; // return the class of GCD
}

Num_Fact LCM(Num_Fact& A, Num_Fact& B, Num_Fact& gcd) { // get LCM(A, B)
	Num_Fact C; // build a class  store LCM
	int num; 
	num = A.Num * B.Num / gcd.Num; // LCM = A*B / GCD
	C.set(num);
	return C; // return the class of LCM
}
#endif
