// EE3405301 Lab03 Design and Create a Student Class (補交)
// B11107035  黃偉智 
// Oct.27, 2022

#include <iostream>   //include libraries
#include <iomanip>
#include <cmath>
using namespace std;

class Student {   //declare a class named Student

private:			//declare variables in private so that other classes can't access directly
	char name[12];	//declare a char array called name with the array length of 12
	char id[10];		//declare a char array called id with the array length of 10
	unsigned __int16 hw = 0;			//declare an integer called hw
	unsigned __int16 mid = 0;		//declare an integer called mid
	unsigned __int16 fin = 0;		//declare an integer called fin
	//======use char array instead of string and use unsigned __int16 instead of int to make the size of student smaller=====

public:			//public for user access

	void setName(char Name[12]) {	//create a setter for name
		for (int i = 0; i < 12; i++) {
			name[i] = Name[i];
		}
	}
	string getName() {		//create a getter for name
		return name;
	}

	void setID(char Id[10]) { //create a setter for ID
		for (int i = 0; i < 10; i++) {
			id[i] = Id[i];
		}
	}
	string getID() {	//create a getter for ID
		return id;
	}

	void setHW(int HW) {	//create a setter for hw
		if (HW > 0 && HW <= 100) {	//check if hw is valid for a score
			hw = HW;
		}
	}
	int getHW() {	//create a getter for hw
		return hw;
	}

	void setMid(int Mid) {	//create a setter for mid
		if (Mid > 0 && Mid <= 100) {	//check if mid is valid for a score
			mid = Mid;
		}
	}
	int getMid() {	//create a getter for hw
		return mid;
	}

	void setFin(int Fin) {	//create a setter for final
		if (Fin > 0 && Fin <= 100) {	//check if final is valid for a score
			fin = Fin;
		}
	}
	int getFin() {	//create a getter for final
		return fin;
	}

	float getAverage() {	//create a getter for average
		float average;		//use float because average will be decimals
		average = 0.4 * hw + 0.3 * mid + 0.3 * fin;	//average = 40% hw, 30% mid, 30% final
		return round(average);	//round the average value so there will be no decimals
	}

	string getLetterGrade() {	//create a getter for letter grade
		string letterGrade;
		int average = getAverage();	//get the average value from the getAverage function
		if (average >= 90 && average <= 100) {	//if average is between 90-100
			letterGrade = "A+";					//then letter grade is A+
		}
		else if (average >= 85 && average <= 89) {	//if average is in or between 85-89,
			letterGrade = "A";						//then letter grade is A
		}
		else if (average >= 80 && average <= 84) {	//if average is in or between 80-84,
			letterGrade = "A-";						//then letter grade is A-
		}
		else if (average >= 77 && average <= 79) {	//if average is in or between 77-79,
			letterGrade = "B+";						//then letter grade is B+
		}
		else if (average >= 73 && average <= 76) {	//if average is in or between 73-76,
			letterGrade = "B";						//then letter grade is B
		}
		else if (average >= 70 && average <= 72) {	//if average is in or between 70-72,
			letterGrade = "B-";						//then letter grade is B-
		}
		else if (average >= 67 && average <= 69) {	//if average is in or between 67-69,
			letterGrade = "C+";						//then letter grade is C+
		}
		else if (average >= 63 && average <= 66) {	//if average is in or between 63-66,
			letterGrade = "C";						//then letter grade is C
		}
		else if (average >= 60 && average <= 62) {	//if average is in or between 60-62,
			letterGrade = "C-";						//then letter grade is C-
		}
		else if (average >= 50 && average <= 59) {	//if average is in or between 50-59,
			letterGrade = "D";						//then letter grade is D
		}
		else if (average >= 1 && average <= 49) {	//if average is in or between 1-49,
			letterGrade = "E";						//then letter grade is E
		}
		else {		//else if average is not the same value as all of the above,
			letterGrade = "X";	//letter grade is X
		}
		return letterGrade;		//return the value of letterGrade
	}

};
