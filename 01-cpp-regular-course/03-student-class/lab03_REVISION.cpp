// EE3405301 Lab03 Design and Create a Student Class (補交)
// B11107035  黃偉智 
// Oct.27, 2022

#include <iostream>		//include the needed libraries
#include <string>
#include <iomanip>
#include <cmath>
#include "Student.h"
using namespace std;

int main() {

	Student student[200];		//make a student member of 200, assuming that the students amount won't reach 200
	cout << "Size of (student) = " << sizeof(student[0]) << " Bytes" << endl;	//printing out the size of student

	char Name[12];					//declare a variable for student's name, supposing the name won't exceed 12 characters
	char ID[10];					//declare a variable for student's ID, supposing the ID won't exceed 12 characters
	unsigned __int16 Hw, Mid, Fin;	//declare variables for each hw, mid, and fin scores
	//======use char array instead of string and use unsigned __int16 instead of int to make the size of student smaller=====

	int n = 0;
	cout << "How many students in this class? ";	//user input for amount of students
	cin >> n;
	cout << endl;

	for (int i = 0; i < n; i++) {				//user input for each students' data
		cin >> Name >> ID >> Hw >> Mid >> Fin;
		student[i].setName(Name);			//set the student's name from user input
		student[i].setID(ID);				//set the student's ID from user input
		student[i].setHW(Hw);				//set the student's hw score from user input
		student[i].setMid(Mid);				//set the student's mid score from user input
		student[i].setFin(Fin);				//set the student's fin score from user input
	}

	cout << left << setw(6) << "Idx" << setw(12) << "Name" << setw(12) << "ID";		//printing out the table header
	cout << left << setw(6) << "hw" << setw(6) << "mid" << setw(6) << "final";
	cout << left << setw(6) << "Ave." << "letterGrade";
	cout << endl;

	int counter = 1;
	float hwTotal = 0, midTotal = 0, finTotal = 0, avgTotal = 0;	//declaring variable to contain each sum of scores
	string avgLetterGrade;			//declaring variable to contain the average letter grade

	for (int i = 0; i < n; i++) {		//printing out the data from user input, and insert it to the output table using setw() function
		cout << right << setw(3) << i + 1 << setw(3) << " ";
		cout << left << setw(12) << student[i].getName() << setw(12) << student[i].getID();
		cout << left << setw(6) << student[i].getHW() << setw(6) << student[i].getMid() << setw(6) << student[i].getFin();
		cout << left << setw(6) << student[i].getAverage() << student[i].getLetterGrade();
		cout << endl;
		hwTotal += student[i].getHW();			//sum every student's total score
		midTotal += student[i].getMid();
		finTotal += student[i].getFin();
		avgTotal += student[i].getAverage();
		counter++;
	}

	int hwAvg = round(hwTotal / n);		//homework average score = sum of all students' homework score divided by the amount of the students
	int midAvg = round(midTotal / n);	//midterm average score = sum of all students' midterm score divided by the amount of the students
	int finAvg = round(finTotal / n);	//final average score = sum of all students' final score divided by the amount of the students
	int avgAvg = round(avgTotal / n);	//average average score = sum of all students' average score divided by the amount of the students
	if (avgAvg >= 90 && avgAvg <= 100) {	//if avgAvg is between 90-100
		avgLetterGrade = "A+";					//then avgLetterGrade is A+
	}
	else if (avgAvg >= 85 && avgAvg <= 89) {	//if avgAvg is in or between 85-89,
		avgLetterGrade = "A";						//then avgLetterGrade is A
	}
	else if (avgAvg >= 80 && avgAvg <= 84) {	//if avgAvg is in or between 80-84,
		avgLetterGrade = "A-";						//then avgLetterGrade is A-
	}
	else if (avgAvg >= 77 && avgAvg <= 79) {	//if avgAvg is in or between 77-79,
		avgLetterGrade = "B+";						//then avgLetterGrade is B+
	}
	else if (avgAvg >= 73 && avgAvg <= 76) {	//if avgAvg is in or between 73-76,
		avgLetterGrade = "B";						//then avgLetterGrade is B
	}
	else if (avgAvg >= 70 && avgAvg <= 72) {	//if avgAvg is in or between 70-72,
		avgLetterGrade = "B-";						//then avgLetterGrade is B-
	}
	else if (avgAvg >= 67 && avgAvg <= 69) {	//if avgAvg is in or between 67-69,
		avgLetterGrade = "C+";						//then avgLetterGrade is C+
	}
	else if (avgAvg >= 63 && avgAvg <= 66) {	//if avgAvg is in or between 63-66,
		avgLetterGrade = "C";						//then avgLetterGrade is C
	}
	else if (avgAvg >= 60 && avgAvg <= 62) {	//if avgAvg is in or between 60-62,
		avgLetterGrade = "C-";						//then avgLetterGrade is C-
	}
	else if (avgAvg >= 50 && avgAvg <= 59) {	//if avgAvg is in or between 50-59,
		avgLetterGrade = "D";						//then avgLetterGrade is D
	}
	else if (avgAvg >= 1 && avgAvg <= 49) {	//if avgAvg is in or between 1-49,
		avgLetterGrade = "E";						//then avgLetterGrade is E
	}
	else {		//else if avgAvg is not the same value as all of the above,
		avgLetterGrade = "X";	//avgLetterGrade is X
	}

	cout << right << setw(3) << counter << setw(3) << " ";				//printing out the last row of the table
	cout << left << setw(12) << "AVERAGE" << setw(12) << "********";
	cout << left << setw(6) << hwAvg << setw(6) << midAvg << setw(6) << finAvg;
	cout << left << setw(6) << avgAvg << avgLetterGrade;
	cout << endl;

	return 0;
}