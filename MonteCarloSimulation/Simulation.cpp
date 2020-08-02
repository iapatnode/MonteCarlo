/******************************************************
**Isabella Patnode ~ COMP233.A ~ Monte Carlo Simulation
******************************************************/


#include <math.h>
#include <time.h>
#include <iostream>
#include<iomanip>
#include "..//MonteCarlo/Card.h"
#include "..//MonteCarlo/Deck.h"

using namespace std;

Deck createHand(); //creates a hand of 5 cards
int checkTwoPair(Deck); //checks a hand for Two pair

int main() {
	int handCount; //loop variables
	int numHands; //number of hands in each set being simulated
	const int MAX_HANDS = pow(2, 24); //max number of hands to be simulated
	int twoPairNum; //number of two pair found in each set of hands
	double twoPairProb; //percentage of two pair found in each set of hands
	Deck currentHand(5); //the hand of five cards to be generated

	srand(time(NULL));

	cout << "Isabella Patnode ~ COMP233.A ~ Monte Carlo Simulation\n";
	cout << "This program calculates the percent of poker hands "
		 << "that contain a two pair.\n\n";

	numHands = 512;

	cout << " Number of hands" << setw(23) << "Number of Two Pair"
		 << setw(27) << "Percentage of Two Pair" << endl;

	//keeps generating hands until 16 meg hands have been generated
	while (numHands <= MAX_HANDS) {
		twoPairNum = 0;
		twoPairProb = 0;

		//generates  a set of numHand hands
		for (handCount = 0; handCount < numHands; handCount++) {
			
			currentHand = createHand();

			//Counts the number of two pair found
			twoPairNum += checkTwoPair(currentHand);
			
			//Garbage collection
			currentHand.~Deck();	
		}

		//calculates the percentage of two pair
		twoPairProb = ((double) twoPairNum / (double) numHands) * 100;

		cout << setw(11) << numHands << setw(21) << twoPairNum
			 << setw(27) << twoPairProb << endl;

		numHands *= 2;
	}

	//Normal termination
	cout << "Program terminated normally." << endl;
	return 0;
}

//Creates a hand of 5 unique cards and returns it
Deck createHand() {
	//cards dealt to hand
	int firstCard, secondCard, thirdCard, fourthCard, fifthCard;
	Deck deckCards; //standard deck of cards
	Deck currentHand(5); //hand of 5 cards
	
	//Picks 5 unique positions of cards in default deck
	firstCard = rand() % deckCards.getNumCards();

	do {
		secondCard = rand() % deckCards.getNumCards();
	} while (secondCard == firstCard);

	do {
		thirdCard = rand() % deckCards.getNumCards();
	} while (thirdCard == firstCard || thirdCard == secondCard);

	do {
		fourthCard = rand() % deckCards.getNumCards();
	} while (fourthCard == firstCard || fourthCard == secondCard 
		     || fourthCard == thirdCard);

	do {
		fifthCard = rand() % deckCards.getNumCards();
	} while (fifthCard == firstCard || fifthCard == secondCard || 
		     fifthCard == thirdCard || fifthCard == fourthCard);

	//Adds chosen cards to current hand
	currentHand.addCard(deckCards.peekCard(firstCard));
	currentHand.addCard(deckCards.peekCard(secondCard));
	currentHand.addCard(deckCards.peekCard(thirdCard));
	currentHand.addCard(deckCards.peekCard(fourthCard));
	currentHand.addCard(deckCards.peekCard(fifthCard));

	//Garbage collection
	deckCards.~Deck();

	return currentHand;
}

//checks a hand for two pairs
//Takes in the hand to be checked
//Returns 1 if a two pair is found, 0 otherwise
int checkTwoPair(Deck hand) {
	int firInd, secInd; //loop variables
	int potentialPair; //the number of pairs in hand
	int notPair; //number of combos greater than two pair in hand
	int twoPairFound; //number of two pair found in one hand
	Card cardOne, cardTwo; //cards being checked for two pair

	potentialPair = 0;
	notPair = 0;
	twoPairFound = 0;

	//checks each card against the ones after it in the hand
	for (firInd = 0; firInd < hand.getNumCards(); firInd++) {
		for (secInd = firInd + 1; secInd < hand.getNumCards(); secInd++) {
			cardOne = hand.peekCard(firInd);
			cardTwo = hand.peekCard(secInd);
			
			//counts the cards that might be part of a two pair
			if (cardOne.getFace() == cardTwo.getFace()) {
				potentialPair++;
			}
		}

		//increments notPair if three or four of a kind are found
		if (potentialPair > 1) {
			notPair++;
		}

		//increments twoPairFound if a pair of cards was found
		if (potentialPair == 1) {
			twoPairFound++;
		}

		//resets potentialPair after card has been checked
		potentialPair = 0;
	}
	
	//if the hand does not include anything greater than a two pair
    //and two pairs were found then the hand contains a two pair
	if (notPair == 0 && twoPairFound == 2) {
		return 1;
	}

	return 0;
}




