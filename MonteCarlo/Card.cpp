/**************************************************************************
**Rachel Franklin & Isabella Patnode ~ COMP233.A ~ Card Implementation File
**************************************************************************/

#include "Card.h"
#include <iostream>
using namespace std;

//Method by Isabella Patnode
//Card default constructor - sets Card to Ace of Clubs
Card::Card() {
	cardNum = 2 * 13 + 1;
}

//Method by Rachel Franklin
//Card parameterized constructor
//Sets Card to specified face and suit values
Card::Card(int f, char s) {
	try {
		cardNum = 0;
		setFace(f);
		setSuit(s);
	}
	catch (exception e) {
		cerr << e.what() << endl;
	}
	
}

//Method by Isabella Patnode
//Returns face of the Card
const int Card::getFace() {
	//initializes faceVal as an int from 0-12
	int faceVal = cardNum % 13;

	//king has a face value of 0 to the class but 13 to the player
	if (faceVal == 0) {
		return 13;
	}

	return faceVal;
}

//Method by Isabella Patnode
//Returns suit of the card
const char Card::getSuit() {
	//according to card suitVal is an int from 0-3
	int suitVal = cardNum / 13;

	if (suitVal == 0) {
		return 'S';
	}
	if (suitVal == 1) {
		return 'D';
	}
	if (suitVal == 2) {
		return 'C';
	}
	return 'H';
}

//Method by Rachel Franklin
//Sets face to specified value
//Throws exception if value is invalid ( < 1 or > 13)
void Card::setFace(int f) throw (runtime_error) {
	int suitVal; //the suit of the current card
	if (f < 1 || f > 13) {
		throw runtime_error("Card setFace has illegal value\n.");
	}
	else {
		suitVal = cardNum / 13;

		//king is 0 according to the class
		if (f == 13) {
			cardNum = suitVal * 13 + 0;
		}
		else {
			cardNum = suitVal * 13 + f;
		}
	}
}

//Method by Rachel Franklin
//Sets suit to specified value
//Throws exception if suit is invalid (not SHCD)
void Card::setSuit(char s) throw (runtime_error) {
	int faceVal; //the face value of the current card

	if (s != 'S' && s != 'D' && s != 'C' && s != 'H') {
		throw runtime_error("Card setSuit has illegal value\n.");
	}
	else {
		faceVal = cardNum % 13;

		if (s == 'S') {
			cardNum = 0 * 13 + faceVal;
		}
		if (s == 'D') {
			cardNum = 1 * 13 + faceVal;
		}
		if (s == 'C') {
			cardNum = 2 * 13 + faceVal;
		}
		if (s == 'H') {
			cardNum = 3 * 13 + faceVal;
		}
	}
}

//Method by Isabella Patnode
//Creates the toString of each card
string Card::toString() {
	string cardName;
	int face, suit; //face and suit values of the current card

	face = cardNum % 13;
	suit = cardNum / 13;

	if (face == 1) {
		cardName = "Ace of ";
	}
	else if (face == 2) {
		cardName = "Two of ";
	}
	else if (face == 3) {
		cardName = "Three of ";
	}
	else if (face == 4) {
		cardName = "Four of ";
	}
	else if (face == 5) {
		cardName = "Five of ";
	}
	else if (face == 6) {
		cardName = "Six of ";
	}
	else if (face == 7) {
		cardName = "Seven of ";
	}
	else if (face == 8) {
		cardName = "Eight of ";
	}
	else if (face == 9) {
		cardName = "Nine of ";
	}
	else if (face == 10) {
		cardName = "Ten of ";
	}
	else if (face == 11) {
		cardName = "Jack of ";
	}
	else if (face == 12) {
		cardName = "Queen of ";
	}
	else {
		cardName = "King of ";
	}

	if (suit == 0) {
		cardName = cardName + "Spades";
	}
	else if (suit == 1) {
		cardName = cardName + "Diamonds";
	}
	else if (suit == 2) {
		cardName = cardName + "Clubs";
	}
	else {
		cardName = cardName + "Hearts";
	}

	return cardName;
}

//Method by Rachel Franklin
//Receives card to be compared to current card & opt. bool for high ace
//Returns -1 if calling face value < parameter face value,
//0 if calling face value = parameter face value, 
//or 1 if calling face value > parameter face value
int Card::compareTo(const Card other, bool aceIsHigh) {
	int calCardFace, parCardFace; //face values of calling card and parameter card respectively

	calCardFace = cardNum % 13;
	parCardFace = other.cardNum % 13;

	//ace is the highest number
	if (aceIsHigh) {
		//Calling face is ace and parameter face is not
		if (calCardFace == 1 && parCardFace != 1) {
			return 1;
		}

		//Parameter face is ace and calling face is not
		if (parCardFace == 1 && calCardFace != 1) {
			return -1;
		}
	}

	//when ace is the lowest number

	//calling face < parameter face except 0 which is king
	if (calCardFace < parCardFace && calCardFace != 0) {
		return -1;
	}

	//calling face > parameter face except 0 which is king
	if (calCardFace > parCardFace && parCardFace != 0) {
		return 1;
	}

	//0 is king so it is the highest card when ace is low
	if (calCardFace == 0 && parCardFace != 0) {
		return 1;
	}

	if (calCardFace != 0 && parCardFace == 0) {
		return -1;
	}
	
	//calling face = parameter face
	return 0;
}