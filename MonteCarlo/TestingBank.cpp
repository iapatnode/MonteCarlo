/**************************************************************
**Rachel Franklin & Isabella Patnode ~ COMP233.A ~ Testing Bank
**************************************************************/
/*
#include<iostream>
#include "Card.h"
#include "Deck.h"

using namespace std;

int defaultCardTest(); //testing Card default constructor

int paramValidCardTest(); //testing Card parameterized constructor for valid suit and middle face
int paramHighCardTest(); //testing Card parameterized constructor for valid suit and high face
int paramLowCardTest(); //testing Card parameterized constructor for valid suit and low face
int invalidCardTest(); //testing Card parameterized constructor for invalid suit and face
int invSuitCardTest(); //testing Card parameterized constructor for invalid suit and valid face
int invHighCardTest(); //testing Card parameterized constructor for valid suit and invalid high face
int invLowCardTest(); //testing Card parameterized constructor for valid suit and invalid low face

int getFaceTest(); //testing Card getFace
int getSuitTest(); //testing Card getSuit

int setFaceInvHighTest(); //testing Card setFace for high invalid value
int setFaceInvLowTest(); //testing Card setFace for low invalid value
int setFaceHighTest(); //testing Card setFace for high valid value
int setFaceLowTest(); //testing Card setFace for low valid value
int setFaceMidTest(); //testing Card setFace for middle valid value

int setSuitInvTest(); //testing Card setSuit for invalid value]
int setSuitSpadesTest(); //testing Card setSuit for spades
int setSuitClubsTest(); //testing Card setSuit for clubs
int setSuitDiamondsTest(); //testing Card setSuit for diamonds
int setSuitHeartsTest(); //testing Card setSuit for hearts

int toStringClubsTest(); //testing toString for clubs
int toStringSpadesTest(); //testing toString for spades
int toStringHeartsTest(); //testing toString for hearts
int toStringDiamondsTest(); //testing toString for diamonds
int toStringAceTest(); //testing toString for ace
int toStringTwoTest(); //testing toString for two
int toStringThreeTest(); //testing toString for three
int toStringFourTest(); //testing toString for four
int toStringFiveTest(); //testing toString for five
int toStringSixTest(); //testing toString for six
int toStringSevenTest(); //testing toString for seven
int toStringEightTest(); //testing toString for eight
int toStringNineTest(); //testing toString for nine
int toStringTenTest(); //testing toString for ten
int toStringJackTest(); //testing toString for jack
int toStringQueenTest(); //testing toString for queen
int toStringKingTest(); //testing toString for king

int compareToSmallTest(); //testing compareTo when calling card has smaller face
int compareToSameTest(); //testing compreTo when calling card has same face
int compareToBigTest(); //testing compareTo when calling card has bigger face
int compareToAceLowTest(); //testing compareTo when ace is low
int compareToAceHighTest(); //testing compreTo when ace is high

int defaultDeckTest(); //testing Deck default constructor

int paramConstructorNegInputTest(); //testing Deck parameterized constructor with negative capacity
int paramConstructorLargeInputTest(); //testing Deck parameterized constructor with invalid large capacity
int paramConstructorDefInputTest(); //testing Deck parameterized constructor with default capacity
int paramConstructorValInputTest(); //testing Deck parameterized constructor with valid capacity

int isEmptyEmptyTest(); //testing isEmpty when deck is empty
int isEmptyNonEmpTest(); //testing isEmpty when deck is not empty

int isFullFullTest(); //testing isFull with full deck
int isFullEmptyTest(); //testing isFull with empty deck

int getNumCardsEmptyTest(); //testing getNumCards when deck is empty
int getNumCardsNonEmpTest(); //testing getNumCards when deck is not empty

int dealCardFullTest(); //testing dealCard with full deck
int dealCardEmptyTest(); //testing dealCard with empty deck
int dealCardOneCardTest(); //testing dealCard with deck of one card

int addCardFullTest(); //testing addCard when deck is full
int addCardPartialTest(); //testing addCard when deck is not full

int peekCardEmptyTest(); //testing peekCard with empty deck
int peekCardDefaultTest(); //testing peekCard with default deck
int peekCardInvPosTest(); //testing peekCard with invalid position
int peekCardParamTest(); //testing peekCard with parameterized deck

int shuffleDeckOrderTest(); //testing shuffleDeck for proper shuffling
int shuffleDeckContainTest(); //testing shuffleDeck for duplicate cards

int cutDeckFullTest(); //testing cutDeck with default deck
int cutDeckEmptyTest(); //testing cutDeck with empty deck
int cutDeckSixOrLessTest(); //testing cutDeck with six or less cards

int resetDeckDefaultTest(); //testing resetDeck with default deck
int resetDeckParamTest(); //testing resetDeck with parameterized deck

int copyConstructorDefTest(); //testing copyConstructor with default deck
int copyConstructorParTest(); //testing copyConstructor with partial deck
int copyConstructorEmptyTest(); //testing copyConstructor with empty deck

int assignmentOpTest(); //testing operater= with default deck

int destructorTest(); //testing destructor

int main() {
	int numSucceeded = 0; //counter of successes
	int tests = 0; //number of tests run

	cout << "Rachel Franklin & Isabella Patnode ~ COMP233.A ~ Testing Bank for Deck and Card\n";
	cout << "This program will test the functions of Deck and Card\n\n";

	cout << "Testing Default Card constructor...\n\n";
	numSucceeded += defaultCardTest();
	tests++;

	cout << "Testing Parameterized Card constructor...\n\n";
	numSucceeded += paramValidCardTest();
	tests++;
	numSucceeded += paramHighCardTest();
	tests++;
	numSucceeded += paramLowCardTest();
	tests++;
	numSucceeded += invalidCardTest();
	tests++;
	numSucceeded += invSuitCardTest();
	tests++;
	numSucceeded += invHighCardTest();
	tests++;
	numSucceeded += invLowCardTest();
	tests++;

	cout << "Testing getSuit...\n\n";
	numSucceeded += getSuitTest();
	tests++;

	cout << "Testing getFace...\n\n";
	numSucceeded += getFaceTest();
	tests++;

	cout << "Testing setFace...\n\n";
	numSucceeded += setFaceInvHighTest();
	tests++;
	numSucceeded += setFaceInvLowTest();
	tests++;
	numSucceeded += setFaceHighTest();
	tests++;
	numSucceeded += setFaceLowTest();
	tests++;
	numSucceeded += setFaceMidTest();
	tests++;

	cout << "Testing setSuit...\n\n";
	numSucceeded += setSuitInvTest();
	tests++;
	numSucceeded += setSuitSpadesTest();
	tests++;
	numSucceeded += setSuitClubsTest();
	tests++;
	numSucceeded += setSuitDiamondsTest();
	tests++;
	numSucceeded += setSuitHeartsTest();
	tests++;

	cout << "Testing toString...\n\n";
	numSucceeded += toStringClubsTest();
	tests++;
	numSucceeded += toStringSpadesTest();
	tests++;
	numSucceeded += toStringHeartsTest();
	tests++;
	numSucceeded += toStringDiamondsTest();
	tests++;
	numSucceeded += toStringAceTest();
	tests++;
	numSucceeded += toStringTwoTest();
	tests++;
	numSucceeded += toStringThreeTest();
	tests++;
	numSucceeded += toStringFourTest();
	tests++;
	numSucceeded += toStringFiveTest();
	tests++;
	numSucceeded += toStringSixTest();
	tests++;
	numSucceeded += toStringSevenTest();
	tests++;
	numSucceeded += toStringEightTest();
	tests++;
	numSucceeded += toStringNineTest();
	tests++;
	numSucceeded += toStringTenTest();
	tests++;
	numSucceeded += toStringJackTest();
	tests++;
	numSucceeded += toStringQueenTest();
	tests++;
	numSucceeded += toStringKingTest();
	tests++;

	cout << "Testing Default Deck constructor...\n\n";
	numSucceeded += defaultDeckTest();
	tests++;

	cout << "Testing Parameterized Deck constructor...\n\n";
	numSucceeded += paramConstructorNegInputTest();
	tests++;
	numSucceeded += paramConstructorLargeInputTest();
	tests++;
	numSucceeded += paramConstructorDefInputTest();
	tests++;
	numSucceeded += paramConstructorValInputTest();
	tests++;

	cout << "Testing isEmpty...\n\n";
	numSucceeded += isEmptyEmptyTest();
	tests++;
	numSucceeded += isEmptyNonEmpTest();
	tests++;

	cout << "Testing isFull...\n\n";
	numSucceeded += isFullFullTest();
	tests++;
	numSucceeded += isFullEmptyTest();
	tests++;

	cout << "Testing getNumCards...\n\n";
	numSucceeded += getNumCardsEmptyTest();
	tests++;
	numSucceeded += getNumCardsNonEmpTest();
	tests++;

	cout << "Testing dealCard...\n\n";
	numSucceeded += dealCardFullTest();
	tests++;
	numSucceeded += dealCardEmptyTest();
	tests++;
	numSucceeded += dealCardOneCardTest();
	tests++;

	cout << "Testing addCard...\n\n";
	numSucceeded += addCardFullTest();
	tests++;
	numSucceeded += addCardPartialTest();
	tests++;

	cout << "Testing peekCard...\n\n";
	numSucceeded += peekCardEmptyTest();
	tests++;
	numSucceeded += peekCardDefaultTest();
	tests++;
	numSucceeded += peekCardInvPosTest();
	tests++;
	numSucceeded += peekCardParamTest();
	tests++;

	cout << "Testing shuffleDeck...\n\n";
	numSucceeded += shuffleDeckOrderTest();
	tests++;
	numSucceeded += shuffleDeckContainTest();
	tests++;

	cout << "Testing cutDeck...\n\n";
	numSucceeded += cutDeckFullTest();
	tests++;
	numSucceeded += cutDeckEmptyTest();
	tests++;
	numSucceeded += cutDeckSixOrLessTest();
	tests++;

	cout << "Testing resetDeck...\n\n";
	numSucceeded += resetDeckDefaultTest();
	tests++;
	numSucceeded += resetDeckParamTest();
	tests++;

	cout << "Testing Big Three...\n\n";
	numSucceeded += copyConstructorDefTest();
	tests++;
	numSucceeded += copyConstructorEmptyTest();
	tests++;
	numSucceeded += copyConstructorParTest();
	tests++;

	numSucceeded += assignmentOpTest();
	tests++;

	numSucceeded += destructorTest();
	tests++;

	cout << numSucceeded << " tests out of " << tests << " passed.\n\n";

	//Code termination
	cout << "Normal termination.\n\n";
	return 0;
}

//Method by Rachel Franklin
//Test method for Card default constructor
//Returns 1 if test succeeded, 0 otherwise
int defaultCardTest() {
	Card test; //test card

	if (test.getFace() != 1 || test.getSuit() != 'C') {
		cout << "defaultCardTest failed: default Card constructor did not return Ace of Clubs." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card parameterized constructor when face and suit are valid
//Returns 1 if test succeeded, 0 otherwise
int paramValidCardTest() {
	Card newCard(3, 'H'); //test card

	if (newCard.getFace() != 3 || newCard.getSuit() != 'H') {
		cout << "paramValidCardTest failed: card incorrectly constructed." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card parameterized constructor when high face and suit are valid
//Returns 1 if test succeeded, 0 otherwise
int paramHighCardTest() {
	Card newCard(13, 'D'); //test card

	if (newCard.getFace() != 13 || newCard.getSuit() != 'D') {
		cout << "paramHighCardTest failed: card incorrectly constructed." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card parameterized constructor when low face and suit are valid
//Returns 1 if test succeeded, 0 otherwise
int paramLowCardTest() {
	Card newCard(1, 'C'); //test card

	if (newCard.getFace() != 1 || newCard.getSuit() != 'C') {
		cout << "paramLowCardTest failed: card incorrectly constructed." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card parameterized constructor when face and suit are invalid
//Returns 1 if test succeeded, 0 otherwise
int invalidCardTest() {
	Card newCard(14, 'G'); //test card

	if (newCard.getFace() == 14 || newCard.getSuit() == 'G') {
		cout << "invalidCardTest failed: invalid card constructed." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card parameterized constructor when suit is invalid
//Returns 1 if test succeeded, 0 otherwise
int invSuitCardTest() {
	Card newCard(8, 'G'); //test card

	if (newCard.getFace() == 8 && newCard.getSuit() == 'G') {
		cout << "invSuitCardTest failed: card with invalid suit constructed." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card parameterized constructor when high face is invalid
//Returns 1 if test succeeded, 0 otherwise
int invHighCardTest() {
	Card newCard(15, 'H'); //test card

	if (newCard.getFace() == 15 || newCard.getSuit() == 'H') {
		cout << "invHighCardTest: card with invalid face constructed." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card parameterized constructor when low face is invalid
//Returns 1 if test succeeded, 0 otherwise
int invLowCardTest() {
	Card newCard(0, 'H'); //test card

	if (newCard.getFace() == 0 || newCard.getSuit() == 'H') {
		cout << "invLowCardTest failed: card with invalid face constructed." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card getFace
//Returns 1 if test succeeded, 0 otherwise
int getFaceTest() {
	Card test; //test card

	if (test.getFace() != 1) {
		cout << "getFaceTest failed: face returned for Ace of Clubs was not 1." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card getSuit
//Returns 1 if test succeeded, 0 otherwise
int getSuitTest() {
	Card test(6, 'C'); //test card

	if (test.getSuit() != 'C') {
		cout << "getSuitTest failed: suit returned for 6 of Clubs was not \'C." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card setFace with value too high
//Returns 1 if test succeeded, 0 otherwise
int setFaceInvHighTest() {
	try {
		Card c(10, 'C'); //test card
		c.setFace(14);

		if (c.getFace() == 14) {
			cout << "setFaceInvHighTest failed: face set to invalid value (14)." << endl;
			return 0;
		}
	}
	catch (runtime_error) {
		return 1;
	}
}

//Method by Isabella Patnode
//Test method for Card setFace with value too low
//Returns 1 if test succeeded, 0 otherwise
int setFaceInvLowTest() {
	try {
		Card testCard(10, 'C'); //test card
		testCard.setFace(0);

		if (testCard.getFace() == 0) {
			cout << "setFaceInvLowTest failed: face set to illegal value (0)." << endl;
			return 0;
		}
	}
	catch (runtime_error) {
		return 1;
	}
}

//Method by Isabella Patnode
//Test method for Card setFace with value of 13
//Returns 1 if test succeeded, 0 otherwise
int setFaceHighTest() {
	try {
		Card testCard(10, 'C'); //test card
		testCard.setFace(13);

		if (testCard.getFace() != 13) {
			cout << "setFaceHighTest failed: face not set to legal value (13)." << endl;
			return 0;
		}

		return 1;
	}
	catch (runtime_error) {
		cout << "setFace caught an error when it shouldn't." << endl;
		return 0;
	}
}

//Method by Isabella Patnode
//Test method for Card setFace with value of 1
//Returns 1 if test succeeded, 0 otherwise
int setFaceLowTest() {
	try {
		Card testCard(10, 'C'); //test card
		testCard.setFace(1);

		if (testCard.getFace() != 1) {
			cout << "setFaceLowTest failed: face not set to legal value (1)." << endl;
			return 0;
		}

		return 1;
	}
	catch (runtime_error) {
		cout << "setFace caught an error when it shouldn't." << endl;
		return 0;
	}


}

//Method by Isabella Patnode
//Test method for Card setFace with middle valid value
//Returns 1 if test succeeded, 0 otherwise
int setFaceMidTest() {
	try {
		Card testCard(10, 'C'); //test card
		testCard.setFace(8);

		if (testCard.getFace() != 8) {
			cout << "setFaceMidTest failed: face not set to legal value (8)." << endl;
			return 0;
		}

		return 1;
	}
	catch (runtime_error) {
		cout << "setFace caught an error when it shouldn't." << endl;
		return 0;
	}
}

//Method by Isabella Patnode
//Test method for Card setSuit with invalid suit
//Returns 1 if test succeeded, 0 otherwise
int setSuitInvTest() {
	try {
		Card testCard(10, 'C'); //test card
		testCard.setSuit('G');

		if (testCard.getSuit() == 'G') {
			cout << "setSuitInvTest failed: suit set to invalid value." << endl;

			return 0;
		}
	}
	catch (runtime_error) {
		return 1;
	}
}

//Method by Isabella Patnode
//Test method for Card setSuit with spades
//Returns 1 if test succeeded, 0 otherwise
int setSuitSpadesTest() {
	try {
		Card testCard(10, 'C'); //test card
		testCard.setSuit('S');

		if (testCard.getSuit() != 'S') {
			cout << "setSuitSpadesTest failed: suit not set to Spades." << endl;
			return 0;
		}

		return 1;
	}
	catch (runtime_error) {
		cout << "setSuit caught error when it shouldn't." << endl;
		return 0;
	}
}

//Method by Isabella Patnode
//Test method for Card setSuit with clubs
//Returns 1 if test succeeded, 0 otherwise
int setSuitClubsTest() {
	try {
		Card testCard(10, 'H'); //test card
		testCard.setSuit('C');

		if (testCard.getSuit() != 'C') {
			cout << "setSuitClubsTest failed: suit not set to Clubs." << endl;
			return 0;
		}

		return 1;
	}
	catch (runtime_error) {
		cout << "setSuit caught error when it shouldn't." << endl;
		return 0;
	}
}

//Method by Isabella Patnode
//Test method for Card setSuit with diamonds
//Returns 1 if test succeeded, 0 otherwise
int setSuitDiamondsTest() {
	try {
		Card testCard(10, 'C'); //test card
		testCard.setSuit('D');

		if (testCard.getSuit() != 'D') {
			cout << "setSuitDiamondsTest failed: suit not set to Diamonds." << endl;
			return 0;
		}

		return 1;
	}
	catch (runtime_error) {
		cout << "setSuit caught error when it shouldn't." << endl;
		return 0;
	}
}

//Method by Isabella Patnode
//Test method for Card setSuit with hearts
//Returns 1 if test succeeded, 0 otherwise
int setSuitHeartsTest() {
	try {
		Card testCard(10, 'C'); //test card
		testCard.setSuit('H');

		if (testCard.getSuit() != 'H') {
			cout << "setSuitHeartsTest failed: suit not set to Hearts." << endl;
			return 0;
		}

		return 1;
	}
	catch (runtime_error) {
		cout << "setSuit caught error when it shouldn't." << endl;
		return 0;
	}
}

//Method by Rachel Franklin
//Test method for Card toString for suit = Clubs
//Returns 1 if test succeeded, 0 if failed
int toStringClubsTest() {
	Card test; //test card

	if (test.toString() != "Ace of Clubs") {
		cout << "toStringClubsTest failed: toString was not equivalent to \"Ace of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for suit = Spades
//Returns 1 if test succeeded, 0 if failed
int toStringSpadesTest() {
	Card test(1, 'S'); //test card

	if (test.toString() != "Ace of Spades") {
		cout << "toStringSpadesTest failed: toString was not equivalent to \"Ace of Spades\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for suit = Hearts
//Returns 1 if test succeeded, 0 if failed
int toStringHeartsTest() {
	Card test(1, 'H'); //test card

	if (test.toString() != "Ace of Hearts") {
		cout << "toStringHeartsTest failed: toString was not equivalent to \"Ace of Hearts\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for suit = Diamonds
//Returns 1 if test succeeded, 0 if failed
int toStringDiamondsTest() {
	Card test(1, 'D'); //test card

	if (test.toString() != "Ace of Diamonds") {
		cout << "toStringDiamondsTest failed: toString was not equivalent to \"Ace of Diamonds\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = 1/ace
//Returns 1 if test succeeded, 0 if failed
int toStringAceTest() {
	Card test; //test card

	if (test.toString() != "Ace of Clubs") {
		cout << "toStringAceTest failed: toString was not equivalent to \"Ace of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = 2
//Returns 1 if test succeeded, 0 if failed
int toStringTwoTest() {
	Card test(2, 'C'); //test card

	if (test.toString() != "Two of Clubs") {
		cout << "toStringTwoTest failed: toString was not equivalent to \"Two of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method done by Rachel Franklin
//Test method for Card toString for face = 3
//Returns 1 if test succeeded, 0 if failed
int toStringThreeTest() {
	Card test(3, 'C'); //test card

	if (test.toString() != "Three of Clubs") {
		cout << "toStringThreeTest failed: toString was not equivalent to \"Three of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = 4
//Returns 1 if test succeeded, 0 if failed
int toStringFourTest() {
	Card test(4, 'C'); //test card

	if (test.toString() != "Four of Clubs") {
		cout << "toStringFourTest failed: toString was not equivalent to \"Four of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = 5
//Returns 1 if test succeeded, 0 if failed
int toStringFiveTest() {
	Card test(5, 'C'); //test card

	if (test.toString() != "Five of Clubs") {
		cout << "toStringFiveTest failed: toString was not equivalent to \"Five of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = 6
//Returns 1 if test succeeded, 0 if failed
int toStringSixTest() {
	Card test(6, 'C'); //test card

	if (test.toString() != "Six of Clubs") {
		cout << "toStringSixTest failed: toString was not equivalent to \"Six of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = 7
//Returns 1 if test succeeded, 0 if failed
int toStringSevenTest() {
	Card test(7, 'C'); //test card

	if (test.toString() != "Seven of Clubs") {
		cout << "toStringSevenTest failed: toString was not equivalent to \"Seven of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = 8
//Returns 1 if test succeeded, 0 if failed
int toStringEightTest() {
	Card test(8, 'C'); //test card

	if (test.toString() != "Eight of Clubs") {
		cout << "toStringEightTest failed: toString was not equivalent to \"Eight of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = 9
//Returns 1 if test succeeded, 0 if failed
int toStringNineTest() {
	Card test(9, 'C'); //test card

	if (test.toString() != "Nine of Clubs") {
		cout << "toStringNineTest failed: toString was not equivalent to \"Nine of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = 10
//Returns 1 if test succeeded, 0 if failed
int toStringTenTest() {
	Card test(10, 'C'); //test card

	if (test.toString() != "Ten of Clubs") {
		cout << "toStringTenTest failed: toString was not equivalent to \"Ten of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = Jack/11
//Returns 1 if test succeeded, 0 if failed
int toStringJackTest() {
	Card test(11, 'C'); //test card

	if (test.toString() != "Jack of Clubs") {
		cout << "toStringJackTest failed: toString was not equivalent to \"Jack of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = Queen/12
//Returns 1 if test succeeded, 0 if failed
int toStringQueenTest() {
	Card test(12, 'C'); //test card

	if (test.toString() != "Queen of Clubs") {
		cout << "toStringQueenTest failed: toString was not equivalent to \"Queen of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Rachel Franklin
//Test method for Card toString for face = King/13
//Returns 1 if test succeeded, 0 if failed
int toStringKingTest() {
	Card test(13, 'C'); //test card

	if (test.toString() != "King of Clubs") {
		cout << "toStringKingTest failed: toString was not equivalent to \"King of Clubs\"." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card compareTo with smaller calling card face
//Returns 1 if test succeeded, 0 if failed
int compareToSmallTest() {
	int compareVal; //value returned by compareTo
	Card callCard(3, 'S'); //test calling card
	const Card paramCard(5, 'C'); //test parameter card

	compareVal = callCard.compareTo(paramCard);

	if (compareVal >= 0) {
		cout << "compareToSmallTest failed: call card with smaller face does not produce neg. int." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card compareTo with same calling card face
//Returns 1 if test succeeded, 0 if failed
int compareToSameTest() {
	int compareVal;  //value returned by compareTo
	Card callCard(5, 'D'); //test calling card
	const Card paramCard(5, 'C'); //test parameter card

	compareVal = callCard.compareTo(paramCard);

	if (compareVal != 0) {
		cout << "compareToSameTest failed: same face does not produce 0." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card compareTo with larger calling card face
//Returns 1 if test succeeded, 0 if failed
int compareToBigTest() {
	int compareVal; //value returned by compareTo
	Card callCard(10, 'H'); //test calling card
	const Card paramCard(5, 'C'); //test parameter card

	compareVal = callCard.compareTo(paramCard);

	if (compareVal <= 0) {
		cout << "compareToBigTest failed: call card with larger face does not produce pos. int." << endl;
		return 0;
	}

	return 1;
}

//Method done Isabella Patnode
//Test method for Card compareTo when calling card face is ace and ace is low
//Returns 1 if test succeeded, 0 if failed
int compareToAceLowTest() {
	int compareVal; //value returned by compareTo
	Card callCard(1, 'S'); //test calling card
	const Card paramCard(5, 'C'); //test parameter card

	compareVal = callCard.compareTo(paramCard);

	if (compareVal >= 0) {
		cout << "compareToAceLowTest failed: call card with smaller face does not produce neg. int." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Card compareTo when calling card face is ace and ace is high
//Returns 1 if test succeeded, 0 if failed
int compareToAceHighTest() {
	int compareVal; //value returned by compareTo
	Card callCard(1, 'S'); //test calling card
	const Card paramCard(5, 'C'); //test parameter card

	compareVal = callCard.compareTo(paramCard, true);

	if (compareVal <= 0) {
		cout << "compareToAceHighTest failed: call card with larger face does not produce pos. int." << endl;
		return 0;
	}

	return 1;
}

//Method by Isabella Patnode
//Test method for Deck default constructor
//Returns 1 if test succeeded, 0 if failed
int defaultDeckTest() {
	Deck deckOCards; //test deck
	Card topCard; //first card in deck
	Card bottomCard; //last card in deck

	//Checking size of deck
	if (deckOCards.getNumCards() != 52) {
		cout << "defaultDeckTest failed: size of deck is not 52." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	//Checking capacity of deck
	if (deckOCards.getCapacity() != 52) {
		cout << "defaultDeckTest failed: capacity of deck is not 52." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	//Checking first card in deck
	topCard = deckOCards.peekCard(0);

	if (topCard.getFace() != 1 && topCard.getSuit() != 'S') {
		cout << "defaultDeckTest failed: deck of cards is not in order." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	//Checking last card in deck
	bottomCard = deckOCards.peekCard(51);

	if (bottomCard.getFace() != 13 && bottomCard.getSuit() != 'H') {
		cout << "defaultDeckTest failed: deck of cards is not in order." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	deckOCards.~Deck(); //garbage collection
	return 1;
}

//Method by Rachel Franklin
//Test method for Deck parameterized constructor with negative input
//Returns 1 if test succeeded, 0 if failed
int paramConstructorNegInputTest() {
	try {
		Deck test(-1); //test deck
		cout << "paramConstructorNegInputTest failed: Deck class "
			<< "parameterized constructor allowed negative capacity." << endl;

		test.~Deck(); //garbage collection
		return 0;
	}
	catch (runtime_error) {
		return 1;
	}
}

//Method by Rachel Franklin
//Test method for Deck parameterized constructor with capacity over 416
//Returns 1 if test succeeded, 0 if failed
int paramConstructorLargeInputTest() {
	try {
		Deck test(417); //test deck
		cout << "paramConstructorLargeInputTest failed: Deck class "
			<< "parameterized constructor allowed capacity over 416." << endl;
		test.~Deck(); //garbage collection
		return 0;
	}
	catch (runtime_error) {
		return 1;
	}
}

//Method by Rachel Franklin
//Test method for Deck parameterized constructor with input of 52
//Returns 1 if test succeeded, 0 if failed
int paramConstructorDefInputTest() {
	try {
		Deck test(52); //test deck

		if (test.getNumCards() == 0) {
			cout << "paramConstructorDefInputTest failed: Deck class "
				<< "parameterized constructor did not call default constructor "
				<< "on capacity of 52." << endl;

			test.~Deck(); //garbage collection
			return 0;
		}

		if (test.peekCard(0).toString() != "Ace of Spades") {
			cout << "paramConstructorDefInputTest failed: card at position 0 is "
				<< "not Ace of Spades." << endl;
			test.~Deck(); //garbage collection
			return 0;
		}

		if (test.peekCard(51).toString() != "King of Hearts") {
			cout << "paramConstructorDefInputTest failed: card at last position is "
				<< "not King of Hearts." << endl;
			test.~Deck(); //garbage collection
			return 0;
		}

		test.~Deck();
		return 1;
	}
	catch (runtime_error) {
		cout << "paramConstructorDefInputTest failed: Deck class "
			<< "parameterized constructor should have allowed capacity of 52." << endl;

		return 0;
	}
}

//Method by Rachel Franklin
//Test method for Deck parameterized constructor with input of 52
//Returns 1 if test succeeded, 0 if failed
int paramConstructorValInputTest() {
	try {
		Deck test(100); //test deck

		if (test.getNumCards() != 0) {
			cout << "paramConstructorValInputTest failed: Deck class "
				<< "parameterized constructor did not make deck full of 0s." << endl;
			test.~Deck(); //garbage collection
			return 0;
		}

		test.~Deck(); //garbage collection
		return 1;
	}
	catch (runtime_error) {
		cout << "paramConstructorValInputTest failed: Deck class "
			<< "parameterized constructor should have allowed capacity of 52." << endl;

		return 0;
	}
}

//Method by Isabella Patnode
//Test method for emptyDeck when deck is empty
//Returns 1 if test succeeded, 0 if failed
int isEmptyEmptyTest() {
	Deck deckOCards(104); //test deck

	if (deckOCards.isEmpty() != true) {
		cout << "isEmptyEmptyTest: returns not empty for empty deck of cards." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	deckOCards.~Deck(); //garbage collection
	return 1;
}

//Method by Isabella Patnode
//Test method for emptyDeck when deck is not empty
//Returns 1 if test succeeded, 0 if failed
int isEmptyNonEmpTest() {
	Deck deckOCards; //test deck

	if (deckOCards.isEmpty() != false) {
		cout << "isEmptyNonEmpTest failed: returns empty for non-empty deck of cards." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	deckOCards.~Deck(); //garbage collection
	return 1;
}

//Method by Rachel Franklin
//Test method for isFull when deck is full
//Returns 1 if test succeeded, 0 if failed
int isFullFullTest() {
	Deck test; //test deck

	if (test.isFull() == false) {
		cout << "isFullFullTest failed: isFull called on a full deck returned false." << endl;
		test.~Deck(); //garbage collection
		return 0;
	}

	test.~Deck(); //garbage collection
	return 1;
}

//Method by Rachel Franklin
//Test method for isFull when deck is empty
//Returns 1 if test succeeded, 0 if failed
int isFullEmptyTest() {
	Deck test(34); //test deck

	if (test.isFull() == true) {
		cout << "isFullEmptyTest failed: isFull called on an empty deck returned true." << endl;
		test.~Deck(); //garbage collection
		return 0;
	}

	test.~Deck(); //garbage collection
	return 1;
}

//Method by Isabella Patnode
//Test method for getNumCards when deck is empty
//Returns 1 if test succeeded, 0 if failed
int getNumCardsEmptyTest() {
	Deck deckOCards(104); //test deck

	if (deckOCards.getNumCards() != 0) {
		cout << "getNumCardsEmptyTest failed: returns a nonzero number of cards for an empty deck of cards." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	deckOCards.~Deck(); //garbage collection
	return 1;
}

//Method by Isabella Patnode
//Test method for getNumCards when deck is not empty
//Returns 1 if test succeeded, 0 if failed
int getNumCardsNonEmpTest() {
	Deck deckOCards; //test deck

	if (deckOCards.getNumCards() != 52) {
		cout << "getNumCardsNonEmpTest failed: does not return 52 for a deck of 52 cards." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	deckOCards.~Deck(); //garbage collection

	return 1;
}

//Method by Rachel Franklin
//Test method for dealCard when deck contains cards
//Returns 1 if test succeeded, 0 if failed
int dealCardFullTest() {
	try {
		Deck test; //test deck
		int size = test.getNumCards(); //initial size
		Card first = test.peekCard(0); //card on top of deck
		Card top = test.dealCard(); //dealt card

		//dealt card is not equal to card on top of deck
		if (first.toString() != top.toString()) {
			cout << "dealCardFullTest failed: did not deal top card." << endl;
			test.~Deck(); //garbage collection
			return 0;
		}

		//top card not updated after card dealt
		Card newTop = test.peekCard(0);
		if ((newTop.getFace() != 2) || (newTop.getSuit() != 'S')) {
			cout << "dealCardFullTest failed: did not update top card after dealt." << endl;
			test.~Deck(); //garbage collection
			return 0;
		}

		//deck size not updated after card dealt
		if (size != test.getNumCards() + 1) {
			cout << "dealCardFullTest failed: deck size was not updated after card was dealt." << endl;
			test.~Deck(); //garbage collection
			return 0;
		}

		test.~Deck(); //garbage collection
		return 1;
	}
	catch (runtime_error) {
		cout << "dealCardFullTest failed: believes deck is empty when "
			<< "it has cards." << endl;

		return 0;
	}
}

//Method by Rachel Franklin
//Test method for dealCard when deck is empty
//Returns 1 if test succeeded, 0 if failed
int dealCardEmptyTest() {
	try {
		Deck test(0); //test deck
		Card deal = test.dealCard(); //dealt card

		cout << "dealCardEmptyTest failed: attempting to deal a card from "
			<< "an empty deck should throw an error." << endl;

		test.~Deck(); //garbage collection
		return 0;
	}
	catch (runtime_error) {
		return 1;
	}
}

//Method by Rachel Franklin
//Test method for dealCard when deck contains one card
//Returns 1 if test succeeded, 0 if failed
int dealCardOneCardTest() {
	try {
		Deck test(1); //test deck
		int size; //initial size
		Card deal; //dealt card

		test.addCard(Card());
		size = test.getNumCards();
		deal = test.dealCard();

		if ((size - 1) != test.getNumCards()) {
			cout << "dealCardOneCardTest failed: size did not update when card was dealt." << endl;
			test.~Deck(); //garbage collection
			return 0;
		}

		if (deal.toString() != "Ace of Clubs") {
			cout << "dealCardOneCardTest failed: method did not return top card." << endl;
			test.~Deck(); //garbage collection
			return 0;
		}

		return 1;
	}
	catch (runtime_error) {
		cout << "dealCardOneCardTest failed: card should have been dealt without "
			<< "throwing an error." << endl;

		return 0;
	}
}

//Method by Isabella Patnode
//Test method for addCard when deck is full
//Returns 1 if test succeeded, 0 if failed
int addCardFullTest() {
	try {
		Deck deckOCards; //test deck
		Card newCard(3, 'H'); //test add card
		Card addedCard; //last card in the deck

		deckOCards.addCard(newCard);

		//Checking size after adding card
		if (deckOCards.getNumCards() > deckOCards.getCapacity()) {
			cout << "addCardFullTest Failed: cards in deck exceeds deck capacity." << endl;
			deckOCards.~Deck(); //garbage collection
			return 0;
		}

		addedCard = deckOCards.peekCard(deckOCards.getNumCards() - 1);

		//Checking if card was added
		if (addedCard.getFace() == '3' && addedCard.getSuit() == 'H') {
			cout << "addCardFullTest failed: card added to already full deck." << endl;
			deckOCards.~Deck(); //garbage collection
			return 0;
		}
	}
	catch (runtime_error) {
		return 1;
	}
}

//Method by Isabella Patnode
//Test method for addCard when deck is not full
//Returns 1 if test succeeded, 0 if failed
int addCardPartialTest() {
	try {
		Deck deckOCards(5); //test deck
		Card firstCard(3, 'H'); //test card added first
		Card secondCard(5, 'S'); //test card added second
		Card checkCard; //card added to deck

		deckOCards.addCard(firstCard);

		//Checks size after card is added
		if (deckOCards.getNumCards() != 1) {
			cout << "addCardPartialTest failed: card not added to deck." << endl;
			deckOCards.~Deck(); //garbage collection
			return 0;
		}

		checkCard = deckOCards.peekCard(0);

		//Checks if card was added to deck
		if (checkCard.getFace() != '3' && checkCard.getSuit() != 'H') {
			cout << "addCardPartialTest failed: card not added to deck." << endl;
			deckOCards.~Deck(); //garbage collection
			return 0;
		}

		deckOCards.addCard(secondCard);

		//Checks size after card is added
		if (deckOCards.getNumCards() != 2) {
			cout << "addCardPartialTest failed: card not added to deck." << endl;
			deckOCards.~Deck(); //garbage collection
			return 0;
		}

		checkCard = deckOCards.peekCard(1);

		//Checks if card was added to deck
		if (checkCard.getFace() != '5' && checkCard.getSuit() != 'S') {
			cout << "addCardPartialTest failed: card not added to deck." << endl;
			deckOCards.~Deck(); //garbage collection
			return 0;
		}

		deckOCards.~Deck(); //garbage collection
		return 1;
	}
	catch (runtime_error) {
		cout << "addCardPartialTest failed: caught an error when it shouldn't." << endl;
		return 0;
	}
}

//Method by Rachel Franklin
//Test method for peekCard when deck is empty
//Returns 1 if test succeeded, 0 if failed
int peekCardEmptyTest() {
	try {
		Deck test(20); //test deck
		test.peekCard(0);

		cout << "peekCardEmptyTest failed: peekCard invoked on empty "
			<< "deck should have thrown an error.";

		test.~Deck(); //garbage collection

		return 0;
	}
	catch (runtime_error) {
		//test succeeded, return 1;
		return 1;
	}
}

//Method by Rachel Franklin
//Test method for peekCard when deck is full
//Returns 1 if test succeeded, 0 if failed
int peekCardDefaultTest() {
	try {
		Deck test; //test deck

		//top card should be Ace of Spades
		if (test.peekCard(0).toString() != "Ace of Spades") {
			cout << "peekCardDefaultTest failed: top card should be "
				<< "Ace of Spades and peekCard(0) did not return that.";
			test.~Deck(); //garbage collection
			return 0;
		}

		test.~Deck(); //garbage collection
		return 1;
	}
	catch (runtime_error) {
		cout << "peekCardDefaultTest: thought deck was empty.";
		return 0;
	}
}

//Method by Rachel Franklin
//Test method for peekCard when peeking in an invalid position
//Returns 1 if test succeeded, 0 if failed
int peekCardInvPosTest() {
	try {
		Deck test; //test deck

		//Remove a couple cards from the deck
		test.dealCard();
		test.dealCard();

		//peek card in position 50; deck indices are only 0-49 now
		test.peekCard(50);

		cout << "peekCardInvPosTest failed: method allowed to peek an "
			<< "invalid position.";

		test.~Deck(); //garbage collection
		return 0;
	}
	catch (runtime_error) {
		return 1;
	}
}

//Method by Rachel Franklin
//Test method for peekCard when deck is parameterized
//Returns 1 if test succeeded, 0 if failed
int peekCardParamTest() {
	try {
		Deck test(5); //test deck

		//add Cards to test deck
		Card qd = Card(12, 'D');
		Card ts = Card(3, 'S');
		test.addCard(qd);
		test.addCard(ts);

		if (test.peekCard(0).toString() != qd.toString()) {
			cout << "peekCardParamTest failed: peek card at position 0 "
				<< "did not return first card added to deck (12, 'D').";
			test.~Deck(); //garbage collection
			return 0;
		}

		test.~Deck(); //garbage collection
		return 1;
	}
	catch (runtime_error) {
		cout << "peekCardParamTest failed: threw exception when should "
			<< "have allowed peekCard(0).";

		return 0;
	}
}

//Method by Isabella Patnode
//Test method for shuffleDeck for ordering of cards
//Returns 1 if test succeeded, 0 if failed
int shuffleDeckOrderTest() {
	Deck deckOCards; //test deck
	Card topCard, nextCard, bottomCard, prevCard; //cards in deck
	int topFace, bottomFace; //face values of top and bottom cards
	char topSuit, bottomSuit; //suits of top and bottom cards

	deckOCards.shuffleDeck();

	//Checks if top two cards are in order
	topCard = deckOCards.peekCard(0);
	nextCard = deckOCards.peekCard(1);

	topFace = topCard.getFace();
	topSuit = topCard.getSuit();

	if ((nextCard.getFace() == topFace + 1) && (nextCard.getSuit() == topSuit)) {
		cout << "shuffleDeckOrderTest failed: deck not shuffled properly." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	//Checks if bottom two cards are in order
	bottomCard = deckOCards.peekCard(51);
	prevCard = deckOCards.peekCard(50);

	bottomFace = bottomCard.getFace();
	bottomSuit = bottomCard.getSuit();

	if ((prevCard.getFace() == bottomFace - 1) && (prevCard.getSuit() == bottomSuit)) {
		cout << "shuffleDeckOrderTest failed: deck not shuffled properly." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	deckOCards.~Deck(); //garbage collection
	return 1;
}

//Method by Isabella Patnode
//Test method for shuffleDeck for missing cards
//Returns 1 if test succeeded, 0 if failed
int shuffleDeckContainTest() {
	Deck deckOCards; //test deck
	int checkIndex, cardIndex, checkFace, cardFace; //indexes of cards
	char checkSuit, cardSuit; //suits of cards being checked

	//Checks each card in the deck with those that come after for duplicates
	for (checkIndex = 0; checkIndex < 52; checkIndex++) {
		checkFace = deckOCards.peekCard(checkIndex).getFace();
		checkSuit = deckOCards.peekCard(checkIndex).getSuit();

		for (cardIndex = checkIndex + 1; cardIndex < 52; cardIndex++) {
			cardFace = deckOCards.peekCard(cardIndex).getFace();
			cardSuit = deckOCards.peekCard(cardIndex).getSuit();

			if (checkFace == cardFace && checkSuit == cardSuit) {
				cout << "shuffleDeckContainTest failed: duplicate and missing cards in deck." << endl;
				deckOCards.~Deck(); //garbage collection
				return 0;
			}
		}
	}

	deckOCards.~Deck(); //garbage collection
	return 1;
}

//Method by Rachel Franklin
//Test method for cutDeck with default deck
//Returns 1 if test succeeded, 0 if failed
int cutDeckFullTest() {
	try {
		Deck test; //test deck

		test.cutDeck();

		//check if cut happened (first card not Ace of Spades)
		if (test.peekCard(0).toString() == "Ace of Spades") {
			cout << "cutDeckFullTest failed: deck did not cut." << endl;
			test.~Deck(); //garbage collection
			return 0;
		}

		//boolean to track if ace of spades is next card
		bool AoS = false;
		//index keeps track of current position in deck
		int index = 0;
		while (AoS == false) {
			//current card
			Card check = test.peekCard(index);
			//next card
			Card next = test.peekCard(index + 1);

			//check if a card is a king and next card is an ace,
			//then check if the next suit is correct
			if (check.getFace() == 13 && next.getFace() == 1) {
				if (check.getSuit() == 'S' && next.getSuit() != 'D') {
					cout << "cutDeckFullTest failed: cards did not stay in order." << endl;
					test.~Deck(); //garbage collection
					return 0;
				}
				if (check.getSuit() == 'D' && next.getSuit() != 'C') {
					cout << "cutDeckFullTest failed: cards did not stay in order." << endl;
					test.~Deck(); //garbage collection
					return 0;
				}
				if (check.getSuit() == 'C' && next.getSuit() != 'H') {
					cout << "cutDeckFullTest failed: cards did not stay in order." << endl;
					test.~Deck(); //garbage collection
					return 0;
				}
				if (check.getSuit() == 'H' && next.getSuit() != 'S') {
					cout << "cutDeckFullTest failed: cards did not stay in order." << endl;
					test.~Deck(); //garbage collection
					return 0;
				}
				//checks passed, these cards are fine
			}
			else {
				if ((check.getFace() + 1) != next.getFace()) {
					cout << "cutDeckFullTest failed: cards did not stay in order." << endl;
					test.~Deck(); //garbage collection
					return 0;
				}
			}

			//if next card is Ace of Spades, break out of the loop
			if (next.toString() == "Ace of Spades") {
				AoS = true;
			}

			//go to the next cards
			index++;
		}

		test.~Deck(); //garbage collection
		return 1;
	}
	catch (runtime_error) {
		cout << "cutDeckFullTest failed: cutDeck caught an invalid error." << endl;
		return 0;
	}
}

//Method by Isabella Patnode
//Test method for cutDeck for empty deck
//Returns 1 if test succeeded, 0 if failed
int cutDeckEmptyTest() {
	try {
		Deck deckOCards(5);

		deckOCards.cutDeck();

		cout << "cutDeckEmptyTest failed: cut an empty deck." << endl;
		deckOCards.~Deck();
		return 0;
	}
	catch (runtime_error) {
		return 1;
	}
}

//Method by Isabella Patnode
//Test method for cutDeck with a deck of 6 cards
//Returns 1 if test succeeded, 0 if failed
int cutDeckSixOrLessTest() {
	Card cardOne, cardTwo, cardThree, cardFour, cardFive, cardSix; //cards added to deck
	int topCardFace; //face of first card in deck after cut
	char topCardSuit; //suit of first card in deck after cut
	try {
		Deck deckOCards(6);

		cardOne = Card();
		cardTwo = Card(3, 'H');
		cardThree = Card(5, 'C');
		cardFour = Card(2, 'D');
		cardFive = Card(11, 'S');
		cardSix = Card(2, 'D');

		deckOCards.addCard(cardOne);
		deckOCards.addCard(cardTwo);
		deckOCards.addCard(cardThree);
		deckOCards.addCard(cardFour);
		deckOCards.addCard(cardFive);
		deckOCards.addCard(cardSix);

		deckOCards.cutDeck();

		topCardFace = deckOCards.peekCard(0).getFace();
		topCardSuit = deckOCards.peekCard(0).getSuit();

		if (topCardFace != cardOne.getFace()) {
			cout << "cutDeckSixOrLessTest failed: deck was cut." << endl;
			return 0;
		}

		if (topCardSuit != cardOne.getSuit()) {
			cout << "cutDeckSixOrLessTest failed: deck was cut." << endl;
			return 0;
		}

		return 1;
	}
	catch (runtime_error) {
		cout << "cutDeckSixOrLessTest failed: cutDeck caught an invalid error." << endl;
		return 0;
	}
}

//Method by Isabella Patnode
//Test method for resetDeck with default deck
//Returns 1 if test succeeded, 0 if failed
int resetDeckDefaultTest() {
	Deck deckOCards; //test deck
	Card topCard; //first card in reset deck
	Card bottomCard; //last card in reset deck

	deckOCards.resetDeck();

	//Checks size of reset deck
	if (deckOCards.getNumCards() != 52) {
		cout << "resetDeckDefaultTest failed: deck of cards not reset properly." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	//Checks capacity of reset deck
	if (deckOCards.getCapacity() != 52) {
		cout << "resetDeckDefaultTest failed: deck of cards not reset properly." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	//Checks first card in deck
	topCard = deckOCards.peekCard(0);

	if (topCard.getFace() != 1 || topCard.getSuit() != 'S') {
		cout << "resetDeckDefaultTest failed: deck of cards not reset properly." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	//Checks last card in deck
	bottomCard = deckOCards.peekCard(51);

	if (bottomCard.getFace() != 13 || bottomCard.getSuit() != 'H') {
		cout << "resetDeckDefaultTest failed: deck of cards not reset properly." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	deckOCards.~Deck(); //garbage collection
	return 1;
}

//Method by Isabella Patnode
//Test method for resetDeck with parameterized deck
//Returns 1 if test succeeded, 0 if failed
int resetDeckParamTest() {
	Deck deckOCards(104); //test deck

	deckOCards.resetDeck();

	//Checks size of reset deck
	if (deckOCards.getNumCards() != 0) {
		cout << "resetDeckParamTest failed: deck of cards not reset properly." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	//Checks capacity of reset deck
	if (deckOCards.getCapacity() != 104) {
		cout << "resetDeckParamTest: deck of cards not reset properly." << endl;
		deckOCards.~Deck(); //garbage collection
		return 0;
	}

	deckOCards.~Deck(); //garbage collection
	return 1;
}

//Method by Rachel Franklin
//Test method for copyConstructor with default deck
//Returns 1 if test succeeded, 0 if failed
int copyConstructorDefTest() {
	Deck test; //test deck

	Deck copy(test);

	if (test.getNumCards() != copy.getNumCards()) {
		cout << "copyConstructorDefTest failed: original and copy "
			<< "decks are not of same size.";
		//Garbage collection
		test.~Deck();
		copy.~Deck();
		return 0;
	}

	if (test.getCapacity() != copy.getCapacity()) {
		cout << "copyConstructorDefTest failed: original and copy "
			<< "decks are not of same capacity.";
		//Garbage collection
		test.~Deck();
		copy.~Deck();
		return 0;
	}

	if ((test.peekCard(0).toString() != copy.peekCard(0).toString()) ||
		(test.peekCard(51).toString() != copy.peekCard(51).toString())) {
		cout << "copyConstructorDefTest failed: original and copy "
			<< "deck cards do not match up.";
		//Garbage collection
		test.~Deck();
		copy.~Deck();
		return 0;
	}

	//Garbage collection
	test.~Deck();
	copy.~Deck();
	return 1;
}

//Method by Rachel Franklin
//Test method for copyConstructor with partial deck
//Returns 1 if test succeeded, 0 if failed
int copyConstructorParTest() {
	Deck test(5); //test deck
	//Add cards
	test.addCard(Card(3, 'H'));
	test.addCard(Card(2, 'S'));
	test.addCard(Card(13, 'C'));
	test.addCard(Card());
	test.addCard(Card(11, 'D'));

	Deck copy(test);

	if (test.getNumCards() != copy.getNumCards()) {
		cout << "copyConstructorParTest failed: original and copy "
			<< "decks are not of same size.";
		//Garbage collection
		test.~Deck();
		copy.~Deck();
		return 0;
	}

	if (test.getCapacity() != copy.getCapacity()) {
		cout << "copyConstructorParTest failed: original and copy "
			<< "decks are not of same capacity.";
		//Garbage collection
		test.~Deck();
		copy.~Deck();
		return 0;
	}

	if ((test.peekCard(0).toString() != copy.peekCard(0).toString()) ||
		(test.peekCard(4).toString() != copy.peekCard(4).toString())) {
		cout << "copyConstructorParTest failed: original and copy "
			<< "deck cards do not match up.";
		//Garbage collection
		test.~Deck();
		copy.~Deck();
		return 0;
	}

	//Garbage collection
	test.~Deck();
	copy.~Deck();
	return 1;
}

//Method by Rachel Franklin
//Test method for copyConstructor with empty deck
//Returns 1 if test succeeded, 0 if failed
int copyConstructorEmptyTest() {
	Deck test(2); //test deck
	Deck copy(test);

	if (test.getNumCards() != copy.getNumCards()) {
		cout << "copyConstructorEmptyTest failed: original and copy "
			<< "decks are not of same size.";
		//Garbage collection
		test.~Deck();
		copy.~Deck();
		return 0;
	}

	if (test.getCapacity() != copy.getCapacity()) {
		cout << "copyConstructorEmptyTest failed: original and copy "
			<< "decks are not of same capacity.";
		//Garbage collection
		test.~Deck();
		copy.~Deck();
		return 0;
	}

	//Garbage collection
	test.~Deck();
	copy.~Deck();
	return 1;
}

//Method by Isabella Patnode
//Test method for operator=
//Returns 1 if test succeeded, 0 if failed
int assignmentOpTest() {
	Deck deckOCards; //test deck
	Card topCard; //first card in copyDeck
	Card bottomCard; //last card in copyDeck

	Deck copyDeck = deckOCards;

	//Checking size of copyDeck
	if (copyDeck.getNumCards() != deckOCards.getNumCards()) {
		cout << "assignmentOpTest failed: copyDeck not properly assigned." << endl;
		return 0;
	}

	//Checking capacity of copyDeck
	if (copyDeck.getCapacity() != deckOCards.getCapacity()) {
		cout << "assignmentOpTest failed: copyDeck not properly assigned." << endl;
		//Garbage collection
		deckOCards.~Deck();
		copyDeck.~Deck();
		return 0;
	}

	//Checking first card in copyDeck
	topCard = copyDeck.peekCard(0);

	if (topCard.toString() != deckOCards.peekCard(0).toString()) {
		cout << "assignmentOpTest failed: copyDeck not properly assigned." << endl;
		//Garbage collection
		deckOCards.~Deck();
		copyDeck.~Deck();
		return 0;
	}

	//Checking last card in copyDeck
	bottomCard = copyDeck.peekCard(51);

	if (bottomCard.toString() != deckOCards.peekCard(51).toString()) {
		cout << "assignmentOpTest failed: copyDeck not properly assigned." << endl;
		//Garbage collection
		deckOCards.~Deck();
		copyDeck.~Deck();
		return 0;
	}

	//Garbage collection
	deckOCards.~Deck();
	copyDeck.~Deck();
	return 1;
}

//Method by Rachel Franklin
//Test method for deep destructor
//Returns 1 if test succeeded, 0 if failed
int destructorTest() {
	Deck test; //test deck

	test.~Deck();

	if (test.getNumCards() != 0) {
		cout << "destructorTest failed - size is not 0.";

		return 0;
	}

	if (test.getCapacity() != 0) {
		cout << "destructorTest failed - size is not 0.";

		return 0;
	}


	return 1;
} */