// EE3405301 Lab05. Compact a student object and print GPA 
// B11107035, 黃偉智
// Oct.24, 2022

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include "Student.h"
using namespace std;

int main() {

	Student student[200];

	unsigned __int8 i = 0;
	int ID;
	char Fname[12], Lname[12], Depart[4];
	float Midterm1, Midterm2, Final;

	while (student[i].sentinelValue()) {	//make a while loop with a sentinel value for inputs from user
		cin >> ID >> Fname >> Lname >> Depart >> Midterm1 >> Midterm2 >> Final;
		Midterm1 *= 10;		//all scores have one digit in the decimal place, so multiply every score by 10 to make it a whole number (integer)
		Midterm2 *= 10;
		Final *= 10;
		student[i].setId(ID);				//set the student's ID from user input
		student[i].setFirstName(Fname);		//set the student's first name from user input
		student[i].setLastName(Lname);		//set the student's last name from user input
		student[i].setDept(Depart);			//set the student's dept from user input
		student[i].setMid1(Midterm1);		//set the student's midterm 1 score from user input
		student[i].setMid2(Midterm2);		//set the student's midterm 2 score from user input
		student[i].setFin(Final);			//set the student's final score from user input
		i++;	//increment i by 1
	}
	
	cout << "Size of (student) = " << sizeof(student[0]) << " Bytes" << endl;		//printing out the header for the output table
	cout << left << setw(4) << "Idx" << setw(12) << "SID" << setw(15) << "Name";
	cout << left << setw(9) << "[Dept]" << setw(6) << "Ave." << setw(4) << "GPA" << "(QP)";
	cout << endl;

	for (int j = 0; j <  i - 1; j++) {		//printing out the output table
		cout << left << setw(4) << j;
		cout << left << setw(12) << student[j].getId();		//printing student's ID
		cout << left << student[j].getFirstName()[0] << ". " << setw(12) << student[j].getLastName();	//printing student's name
		cout << left << "[" << student[j].getDept()[0] << student[j].getDept()[1] << student[j].getDept()[2] << student[j].getDept()[3] << "]" << "\t"; //printing student's dept
		cout << left << setw(6) << fixed << setprecision(1) << student[j].getAverage();		//printing student's average score
		cout << left << setw(4) << student[j].getLetterGrade();		//printing student's letter grade
		cout << left << "(" << student[j].getGPA() << ")";		//printing student's GPA
		cout << endl;
	}

	 unsigned __int16 apCounter = 0, aCounter = 0, amCounter = 0;		//declare variable for each letter grade counter and set it to 0
	 unsigned __int16 bpCounter = 0, bCounter = 0, bmCounter = 0;
	 unsigned __int16 cpCounter = 0, cCounter = 0, cmCounter = 0;
	 unsigned __int16 dCounter = 0, eCounter = 0, xCounter = 0;
	
	 for (int j = 0; j < i - 1; j++) {
		switch (student[j].getLetterGradeCode()) {
		case 1:				//if student's letter grade code is 1,
			apCounter++;	//increment apCounter by 1
			break;
		case 2:				//if student's letter grade code is 2,
			aCounter++;		//increment aCounter by 1
			break;
		case 3:				//if student's letter grade code is 3,
			amCounter++;	//increment amCounter by 1
			break;
		case 4:				//if student's letter grade code is 4,
			bpCounter++;	//increment bpCounter by 1
			break;
		case 5:				//if student's letter grade code is 5,
			bCounter++;		//increment bCounter by 1
			break;
		case 6:				//if student's letter grade code is 6,
			bmCounter++;	//increment bmCounter by 1
			break;
		case 7:				//if student's letter grade code is 7,
			cpCounter++;	//increment cpCounter by 1
			break;
		case 8:				//if student's letter grade code is 8,
			cCounter++;		//increment cCounter by 1
			break;
		case 9:				//if student's letter grade code is 9,
			cmCounter++;	//increment cmCounter by 1
			break;
		case 10:			//if student's letter grade code is 10,
			dCounter++;		//increment dCounter by 1
			break;
		case 11:			//if student's letter grade code is 11,
			eCounter++;		//increment eCounter by 1
			break;
		case 12:			//if student's letter grade code is 12,
			xCounter++;		//increment xCounter by 1
			break;
		default:
			xCounter++;		//set the default to increment xCounter by 1
		}
	}

	cout << "\nNumber of students who received each grade: " << endl;	//printing out the amount of each student's grade
	cout << " A+: " << apCounter << endl;
	cout << " A : " << aCounter << endl;
	cout << " A-: " << amCounter << endl;
	cout << " B+: " << bpCounter << endl;
	cout << " B : " << bCounter << endl;
	cout << " B-: " << bmCounter << endl;
	cout << " C+: " << cpCounter << endl;
	cout << " C : " << cCounter << endl;
	cout << " C-: " << cmCounter << endl;
	cout << " D : " << dCounter << endl;
	cout << " E : " << eCounter << endl;
	cout << " X : " << xCounter << endl;

	return 0;
}