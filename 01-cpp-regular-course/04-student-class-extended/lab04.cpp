// EE3405301 Lab04 Student records and ranking
// B11107006, 張德文
// October. 7, 2022
//

#include <iostream>     // Header defines standard input/output stream objects
#include <cmath>        // Using C math in order to be able to rounded the result
#include <iomanip>      //use to manipulating the output
#include "student.h"    //include the stundet.h as class and function proccessing
#include <string>       // Using string to group function 

using namespace std;        // Using standard namespace, i.e.,cin, cout

int main() {
    int i = 0;          //define i equal to 0
    Student st, average, scoring[4][3];     // calling Student class, average, and using scoing array
    cout << "size of Student : " << sizeof(st) << " bytes" << "\n"; //count the size of the class
    char fline[200];      //use to read data
    cin.getline(fline, 200); //get line from file
    while (st.readIn()) {       //using while function to readin the data in the file
        i = i + 1;                // use i+1 because i start from 0 
        average.countscore(st);         //use to count the average of data
        for (int i = 0; i < 4; i = i + 1) {     // using for function if i less than 4 because we are finding the 3 highest score
            if (st.ifhigher(scoring[i][0], i)) {      // declare the condition to find the 3 highest score in the class 
                scoring[i][2] = scoring[i][1];         // using array to find the first highest
                scoring[i][1] = scoring[i][0];
                scoring[i][0] = st;                     //define the first largest score
            }
            else if (st.ifhigher(scoring[i][1], i)) {    //declare the function to find the second highest score
                scoring[i][2] = scoring[i][1];
                scoring[i][1] = st;                      // define the second largest score
            }
            else if (st.ifhigher(scoring[i][2], i)) {
                scoring[i][2] = st;                     // define the third largest score in test
            }
        }
    }
    float termTotal = 0;		//make a variable for total average scores
    float mid1Total = 0;		//make a variable for total midterm 1 scores
    float mid2Total = 0;		//make a variable for total midterm 2 scores
    float finTotal = 0;

    cout << fixed << setprecision(2);           // use setprecision to use 2 number behind the decimal
    average.countaverage(i);                    //count average from the input from file 
    average.printaverage(3);                    // print the result of term average
    cout << "   ";                              //cout space before print the score
    scoring[3][0].outputscore(3);               // print the first highest score
    cout << "   ";
    scoring[3][1].outputscore(3);               // print the second highest score
    cout << "   ";                      
    scoring[3][2].outputscore(3);               // print the third highest score in exam
    cout << endl;
        
    average.printaverage(0);                    // print the average of mid1
    cout << "   ";  
    scoring[0][0].outputscore(0);               // print the first highest score in mid1
    cout << "   ";
    scoring[0][1].outputscore(0);               // print the second highest score in mid1
    cout << "   ";
    scoring[0][2].outputscore(0);               // print the third highest score in mid1
    cout << endl;

    average.printaverage(1);                    // print the average of mid2
    cout << "   ";
    scoring[1][0].outputscore(1);               // print the first highest score in mid2
    cout << "   ";
    scoring[1][1].outputscore(1);                // print the second highest score in mid2
    cout << "   ";
    scoring[1][2].outputscore(1);               // print the third highest score in mid2
    cout << endl;

    average.printaverage(2);                    // print the average of final
    cout << "   ";
    scoring[2][0].outputscore(2);               // print the first highest score in final
    cout << "   ";
    scoring[2][1].outputscore(2);               // print the second highest score in final
    cout << "   ";      
    scoring[2][2].outputscore(2);               // print the third highest score in mid2
    cout << endl;
}










