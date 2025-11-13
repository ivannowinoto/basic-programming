// EE3405301 Lab06. Poker Dice Game
// roll.h: macros and function declarations
// Oct. 31, 2022

#define FiveKind 0
#define FourKind 1
#define FullHouse 2
#define Straight 3
#define ThreeKind 4
#define TwoPair 5
#define OnePair 6
#define Bust 7

// how to pass an array:
// https://www.tutorialspoint.com/cplusplus/cpp_passing_arrays_to_functions.htm

void FairDiceRoll(int dice[5]) // roll fair dice
{
	for (int i = 0; i < 5; i++) {	//to roll the fair dice, just call the random function and mod it by 6, shift by 1
		dice[i] = rand() % 6 + 1;	//then we'll have random number from 1 to 6 with the same probability
	}
}

void UnfairDiceRoll(int dice[5]) // roll unfair dice
{
	for (int i = 0; i < 5; i++) {		//to roll unfair dice (third to sixth dice), it is the same as fair dice:
		dice[i] = rand() % 6 + 1;		//call the random function and mod it by 6, shift by 1
		if (i < 2) {
			int rnd = rand() % 100 + 1;			//but what makes it unfair lies between this code:
			if (rnd >= 1 && rnd <= 15) {		//if we mod the random by 100 and shift by 1, then we will have random numbers between 1-100
				dice[i] = 1;					//but we need to have 50% higher probability on getting 6.
			}									//so, just take the previous probability 100% / 6 = 16.67%; 50% higher probability from 16.67% is 25%.
			else if (rnd >= 16 && rnd <= 30) {	//so now, the probability for getting 6 is 25%, and other five numbers are 75% / 5 = 15%.
				dice[i] = 2;					//that means for every random number from 1-100, we set the range of getting 6 by 25 numbers and set the others by 15 numbers.
			}									//for this code, when the random number gets between 1-15, the dice 1.
			else if (rnd >= 31 && rnd <= 45) {	//when the random number gets between 16-30, the dice 2.
				dice[i] = 3;					//when the random number gets between 31-45, the dice 3.
			}									//when the random number gets between 46-60, the dice 4.
			else if (rnd >= 46 && rnd <= 60) {	//when the random number gets between 61-75, the dice 5.
				dice[i] = 4;					//and when the random number gets between 76-100, the dice 6.
			}
			else if (rnd >= 61 && rnd <= 75) {
				dice[i] = 5;
			}
			else {
				dice[i] = 6;
			}
		}
	}
}

int ranking(int dice[5]) // Given dice, return corresponding rank
{
	int temp = 0;							//use bubble sort to first up sort all the dice values
	for (int i = 0; i < 5; i++) {			//ex: from 4, 5, 1, 2, 2, 3 to 1, 2, 2, 3, 4, 5
		for (int j = i + 1; j < 5; j++) {	//this way it is easier to check
			if (dice[i] > dice[j]) {
				temp = dice[i];
				dice[i] = dice[j];
				dice[j] = temp;
			}
		}
	}

	int answer[6] = { 0 };				//make another variable for returning values
	for (int out = 0; out < 5; out++) {	
		answer[dice[out] - 1]++;
	}

	int straight = 0, fivekind = 0, pair = 0, tris = 0, four = 0;
	for (int i = 0; i < 6; i++) {
		if (answer[i] != 1 && straight > 0) {	//looking for the same number of dices
			break;
		}
		else if (answer[i] == 1) {	//if the same number of dice is 1, then it is straight
			straight++;
		}
	}
	for (int i = 0; i < 6; i++) {
		if (answer[i] == 5) {		//if the same number of dice is 5, then it is fivekind
			fivekind++;
		}
		else if (answer[i] == 4) {	//if the same number of dice is 4, then it is four
			four++;
		}
		else if (answer[i] == 2) {	//if the same number of dice is 2, then it is pair
			pair++;
		}
		else if (answer[i] == 3) {	//if the same number of dice is 3, then it is tris
			tris++;
		}
	}
	if (straight == 5) return Straight;					//if the straight is five then return Straight
	else if (fivekind == 1) return FiveKind;			//if the fivekind is one then return FiveKind
	else if (pair == 1 && tris == 1) return FullHouse;	//if there is a pair and a tris then return FullHouse
	else if (pair == 2) return TwoPair;					//if there are two pairs then return TwoPair
	else if (four == 1) return FourKind;				//if the four is one then return FourKind
	else if (pair == 1) return OnePair;					//if the pair is one then return OnePair
	else if (tris == 1) return ThreeKind;				//if the tris is one then return ThreeKind

	return Bust;			//else return Bust
}