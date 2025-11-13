// EE3405301 Lab02 Solving a Diophantine Equation
// B11107035, 黃偉智
// Sept. 27, 2022

#include <iostream>
using namespace std;

int main() {
    
    //diophantine equation: a + b^2 = c^3

    int N;      //declare a variable named N
    
    cout << "Input the value of N: ";   //tells the user to input a number which will be the value of N
    cin >> N;                           //input the value of N, where 1 <= a, b, c <= N

    long long int a, b;             //declare two variables: a and b
    long long int c = 2;            //declare variable c with the value of 2
    long long int counter = 1;      //declare variable counter with the value of 1

    for (a = 1; a <= N || c <= N; c++)      //for a or c is less or equal than 1,
    {
        for (b = 1; (b * b) < (c * c * c); b++)     //for b^2 is less than c^3,
        {
            a = (c * c * c) - (b * b);              //then a is equal to c^3.
            if (a <= N && b <= N && c <= N)         //if a, b, c are less or equal than N, then
            {
                cout << "Sol " << counter << ": " << a << " + " << b << "^2" << " = " << c << "^3" << endl;    //print the solution.
                counter++;        //increment the counter
            }
        }
        if (b > N)  //if b is greater than N,
        {
            break;  //then break and jump out from the for loop.
        }
    }
    cout << "Number of solutions found: " << counter - 1 << "\n";   //print the total number of solutions found

    return 0;
}


