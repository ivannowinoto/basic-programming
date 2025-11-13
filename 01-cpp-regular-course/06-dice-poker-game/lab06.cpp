// EE3405301 Lab06. Poker Dice Game
// B11107035, 黃偉智
// Nov. 14, 2022

#include <iostream>		//include neccessary libraries
#include <iomanip>		
#include <cstdlib>
#include <time.h>
#include "roll.h"		//include the header file
using namespace std;

int main()
{
	srand(time(NULL));						//make the random seed using time, so that the seed will always be different
	int fairDice[5][6] = { 0 };				//make a variable for the fair dice
	cout << "Roll FairDice 390000 times" << endl;	//output the "table" header
	cout << "Occurrences  1     2     3     4     5     6" << endl;
	for (int i = 1; i <= 390000; i++) {		//roll the fair dice 390'000 times
		int arr[5];
		FairDiceRoll(arr);
		for (int j = 0; j < 5; j++) {		//count the roll dice result and store it in the array
			fairDice[j][arr[j] - 1]++;
		}
	}
	for (int j = 0; j < 5; j++) {
		cout << "  die " << j + 1 << ": ";
		for (int k = 0; k < 6; k++) {		//printing out the count dice result
			if (k == 5) {					
				cout << fairDice[j][k];		//if it is the last array, only output the numbers so there will be no excess space
			}
			else {
				cout << fairDice[j][k] << " ";	//else, output the number and space to make the table easier to read
			}
		}
		cout << endl;						//end every line after each output
	}
	cout << endl;

	int UnfairDice[5][6] = { 0 };				//make a variable for the unfair dice
	cout << "Roll UnFairDice 390000 times" << endl;	//output the "table" header
	cout << "Occurrences  1     2     3     4     5     6" << endl;
	for (int i = 1; i <= 390000; i++) {			//roll the unfair dice 390'000 times
		int arr[5];
		UnfairDiceRoll(arr);
		for (int j = 0; j < 5; j++) {			//count the roll dice result and store it in the array
			UnfairDice[j][arr[j] - 1]++;		
		}
	}
	for (int j = 0; j < 5; j++) {
		cout << "  die " << j + 1 << ": ";		//printing out the count dice result
		for (int k = 0; k < 6; k++) {
			if (k == 5) {
				cout << UnfairDice[j][k];		//if it is the last array, only output the numbers so there will be no excess space
			}
			else {
				cout << UnfairDice[j][k] << " ";	//else, output the number and space to make the table easier to read
			}
		}
		cout << endl;							//end every line after each output
	}
	cout << endl;

	int win1 = 0;					//make variables for player 1 win, player 2 win, and the total games
	int win2 = 0;					
	int totalGames = 10'000'000;

	for (int i = 1; i <= totalGames; i++) {		//playing the poker games 10 million times
		int arr1[5] = { 0 };			//making dice 1
		int arr2[5] = { 0 };			//making dice 2
		FairDiceRoll(arr1);			//rolling dice 1 using fair dice roll
		UnfairDiceRoll(arr2);		//rolling dice 2 using unfair dice roll
		int rank1 = ranking(arr1);	//determine the ranking of dice 1
		int rank2 = ranking(arr2);	//determine the ranking of dice 2
		if (rank1 < rank2) {		//if rank1 is lower than rank2, 
			win1++;					//player 1 wins
		}
		else if (rank1 == rank2) {	//if it is draw,
			i--;					//replay the round
		}
		else {						//else then player 2 wins
			win2++;
		}
	}

	cout << "Player 2 using unfair dice playing " << totalGames << " games:" << endl;		//printing out the winning and losing percentages
	cout << "  Wining percentage: " << fixed << setprecision(2) << (double(win2) / (totalGames)) * 100 << "%" << endl;
	cout << "  Losing percentage: " << fixed << setprecision(2) << (double(win1) / (totalGames)) * 100 << "%" << endl;

	return 0;
}

//conclusion: there are differences in winning percentage but only a little. From the code, it is also known that
//the player who uses the unfairdiceroll always loses more than the player who uses fairdiceroll.