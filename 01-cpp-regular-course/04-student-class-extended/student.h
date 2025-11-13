#include <iostream> // Header defines standard input/output stream objects
#include <cmath>    // Using C math in order to be able to rounded the result
#include <iomanip>  //use to manipulating the output
#include<string>    // Using string to group function 



using namespace std;        // Using standard namespace, i.e.,cin, cout
class Student {             // make a class of student to seperate between public and private
public:
	float getAverage() {
		return average;
	}

	bool readIn() {			// use read in to declare true of false from the input
		cin >> Id;			
		if (cin.fail()) return false;	
		else {
			cin >> Fname;				// define the input in structure, first name , last name, department, mid 1 score, mid2 score, final score
			cin >> Lname >> dept
				>> mid1
				>> mid2
				>> final;
			average = (mid1 * 0.3 + mid2 * 0.3 + final * 0.4);		//count the average score
			return true;
		}
	}
	void countscore(Student i) {			//count the test score(mid1,mid2,final, and average score)
		mid1 = mid1 + i.mid1;				//count all the mid 1 score in the data
		mid2 = mid2 + i.mid2;				//count all the mid 2 score in the data
		final = final + i.final;			//count all the final score in the data
		average = average + i.average;		//count all the average score in the data
	}
	void countaverage(float i) {			//count the average of all test score
		mid1 = mid1 / i;					// count average of mid 1 score in the data
		mid2 = mid2 / i;					// count average of mid 2 score in the data
		final = final / i;					// count average of final score in the data
		average = average / i;				// count average of term  score in the data
	}
	bool ifhigher(Student i, int x) {				// finding the highest score from all data
		if (x == 0) return (mid1 >= i.mid1);		// finding the highest score from mid1
		else if (x == 1) return (mid2 >= i.mid2);	// finding the highest score from mid2
		else if (x == 2) return (final >= i.final); // finding the highest score from final
		else if (x == 3) return (average >= i.average); // finding the highest score from average/term score
	}

	void printaverage(int y) {							//print out the average score
		if (y == 0)cout << "Midterm 1 average: " <<setw(2)<<mid1;	//print out the average score of mid1
		if (y == 1)cout << "Midterm 2 average: " << setw(2)<< mid2; //print out the average score of mid2
		if (y == 2)cout << "Final average: " << setw(2)<< final;    //print out the average score of final
		if (y == 3)cout << " Term average: " << average;            //print out the average score of term score
		cout << "\n  The top most three students: \n";				////print out the top most three students from each test
	}

	void outputscore(int y) {    // print out the score of mid 1, mid 2, final, average
		if (y == 0)cout << mid1;	// print out the mid 1 score
		else if (y == 1)cout << mid2;	  //print out the mid 2 score
		else if (y == 2)cout << final;  //print out the final score
		else if (y == 3)cout << average;  // print out the average score
		cout << ": " << Id << "  " << Fname << "  " << Lname << "  (" << dept << ")\n";			// print the student data of the top 3 highgest score from each test
	}	
	
private:
	string Id{ "" }, Fname{ "" }, Lname{ "" }, dept{ "" };			// define the string for first name , lastname, department
	float mid1{ 0 }, mid2{ 0 }, final{ 0 }, average{ 0 };			// define the mid1, mid 2, final, average as floating number 

};
