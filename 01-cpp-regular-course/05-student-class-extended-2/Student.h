// EE3405301 Lab05. Compact a student object and print GPA 
// B11107035, 黃偉智
// Oct.24, 2022

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

class Student {
private:						//declaring some variables in private access

	int id;								//make an integer variable called id for the student id
	char firstname[12], lastname[12], dept[4];	//make three chars called firstname, lastname, and dept for each student's first name, last name, and department
	unsigned __int16 mid1, mid2, fin;		//make three floats called mid1, mid2, and fin for each student's scores

public:							//making functions in public access

	void setId(int Id) {		//making a function as ID setter
		id = Id;
	}
	int getId() {				//making a function as ID getter
		return id;
	}

	void setFirstName(char firstName[12]) {	//making a function as first name setter
		for (int i = 0; i < 12; i++) {
			firstname[i] = firstName[i];
		}
	}
	string getFirstName() {					//making a function as first name getter
		return firstname;
	}

	void setLastName(char lastName[12]) {		//making a function as last name setter
		for (int i = 0; i < 12; i++) {
			lastname[i] = lastName[i];
		}

	}
	string getLastName() {					//making a function as last name getter
		return lastname;
	}

	void setDept(char Dept[4]) {				//making a function as department setter
		for (int i = 0; i < 4; i++) {
			dept[i] = Dept[i];
		}
		
	}
	string getDept() {						//making a function as department getter
		return dept;
	}

	void setMid1(unsigned __int16 Mid1) {				//making a function as midterm 1 score setter
		mid1 = Mid1;
	}
	unsigned __int16 getMid1() {						//making a function as midterm 1 score getter
		return mid1;
	}

	void setMid2(unsigned __int16 Mid2) {				//making a function as midterm 2 score setter
		mid2 = Mid2;
	}
	unsigned __int16 getMid2() {						//making a function as midterm 2 score getter
		return mid2;
	}

	void setFin(unsigned __int16 Fin) {				//making a function as final score setter
		fin = Fin;
	}
	unsigned __int16 getFin() {						//making a function as final score getter
		return fin;
	}

	float getAverage() {					//making a function to get the average value from the student's scores
		float average;
		average = 3 * mid1 + 3 * mid2 + 4 * fin;	//average = 30% midterm 1, 30% midterm 2, and 40% final
		return average / 100;	//because the real average from the scores need to be >= 0 and <= 100, divide 100 to make the scores back to real value
	}

	bool sentinelValue() {			//making the sentinel value boolean function
		if (!cin) {
			return false;		//the sentinal value will stop if cin fails
		} else
		return true;
	}

	unsigned __int8 getLetterGradeCode() {	//to be able to use switch case function, create a getter for letter grade code
		unsigned __int8 letterGradeCode;
		int average = round(getAverage());	//get the average value from the getAverage function
		if (average >= 90 && average <= 100) {	//if average is between 90-100
			letterGradeCode = 1;					//then letter grade code is 1
		}
		else if (average >= 85 && average <= 89) {	//if average is in or between 85-89,
			letterGradeCode = 2;						//then letter grade code is 2
		}
		else if (average >= 80 && average <= 84) {	//if average is in or between 80-84,
			letterGradeCode = 3;						//then letter grade code is 3
		}
		else if (average >= 77 && average <= 79) {	//if average is in or between 77-79,
			letterGradeCode = 4;						//then letter grade code is 4
		}
		else if (average >= 73 && average <= 76) {	//if average is in or between 73-76,
			letterGradeCode = 5;						//then letter grade code is 5
		}
		else if (average >= 70 && average <= 72) {	//if average is in or between 70-72,
			letterGradeCode = 6;						//then letter grade code is 6
		}
		else if (average >= 67 && average <= 69) {	//if average is in or between 67-69,
			letterGradeCode = 7;						//then letter grade code is 7
		}
		else if (average >= 63 && average <= 66) {	//if average is in or between 63-66,
			letterGradeCode = 8;						//then letter grade code is 8
		}
		else if (average >= 60 && average <= 62) {	//if average is in or between 60-62,
			letterGradeCode = 9;						//then letter grade code is 9
		}
		else if (average >= 50 && average <= 59) {	//if average is in or between 50-59,
			letterGradeCode = 10;						//then letter grade code is 10
		}
		else if (average >= 1 && average <= 49) {	//if average is in or between 1-49,
			letterGradeCode = 11;						//then letter grade code is 11
		}
		else {		//else if average is not the same value as all of the above,
			letterGradeCode = 12;	//letter grade code is 12
		}
		return letterGradeCode;		//return the value of letterGradeCode
	}

	string getLetterGrade() {	//create a getter function for letter grade
		string letterGrade;
		switch (getLetterGradeCode()) {	//using a switch function to determine the letter grade
		case 1:						//if letter grade code is 1,
			letterGrade = "A+";		//letter grade is A+
			break;			
		case 2:						//if letter grade code is 2,
			letterGrade = "A";		//letter grade is A
			break;
		case 3:						//if letter grade code is 3,
			letterGrade = "A-";		//letter grade is A-
			break;
		case 4:						//if letter grade code is 4,
			letterGrade = "B+";		//letter grade is B+
			break;
		case 5:						//if letter grade code is 5,
			letterGrade = "B";		//letter grade is B
			break;
		case 6:						//if letter grade code is 6,
			letterGrade = "B-";		//letter grade is B-
			break;
		case 7:						//if letter grade code is 7,
			letterGrade = "C+";		//letter grade is C+
			break;
		case 8:						//if letter grade code is 8,
			letterGrade = "C";		//letter grade is C
			break;
		case 9:						//if letter grade code is 9,
			letterGrade = "C-";		//letter grade is C-
			break;
		case 10:					//if letter grade code is 10,
			letterGrade = "D";		//letter grade is D
			break;	
		case 11:					//if letter grade code is 11,
			letterGrade = "E";		//letter grade is E
			break;
		case 12:					//if letter grade code is 12,
			letterGrade = "X";		//letter grade is X
			break;
		default:					//set the default letter grade to X
			letterGrade = "X";
		}
		return letterGrade;
	}

	float getGPA() {		//create a getter function for student's GPA
		float GPA;
		switch (getLetterGradeCode()) {
		case 1:				//if letter grade code is 1,
			GPA = 4.3;		//GPA is 4.3
			break;
		case 2:				//if letter grade code is 2,
			GPA = 4.0;		//GPA is 4.0
			break;
		case 3:				//if letter grade code is 3,
			GPA = 3.7;		//GPA is 3.7
			break;
		case 4:				//if letter grade code is 4,
			GPA = 3.3;		//GPA is 3.3
			break;
		case 5:				//if letter grade code is 5,
			GPA = 3.0;		//GPA is 3.0
			break;
		case 6:				//if letter grade code is 6,
			GPA = 2.7;		//GPA is 2.7
			break;
		case 7:				//if letter grade code is 7,
			GPA = 2.3;		//GPA is 2.3
			break;
		case 8:				//if letter grade code is 8,
			GPA = 2.0;		//GPA is 2.0
			break;
		case 9:				//if letter grade code is 9,
			GPA = 1.7;		//GPA is 1.7
			break;
		case 10:			//if letter grade code is 10,
			GPA = 1.0;		//GPA is 1.0
			break;
		case 11:			//if letter grade code is 11,
			GPA = 0.0;		//GPA is 0.0
			break;
		case 12:			//if letter grade code is 12,
			GPA = 0.0;		//GPA is 0.0
			break;
		default:			//set the default GPA to 0.0
			GPA = 0.0;
		}
		return GPA;
	}

};
