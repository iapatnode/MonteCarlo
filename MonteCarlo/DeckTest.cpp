/************************************************
** Joe College ~ COMP233 ~ Unit Test Deck Class
**
** Basic form of Unit Test:
**	1) make fresh data (do not rely on old data)
**	2) perform the test
**	3) if test passed, just incr. testPassCnt
**		else print msg to cerr & incr testFailCnt
************************************************/
#include "Deck.h"
#include <iostream>
using namespace std;

//#define DEBUG_DECK_TEST

int main() {
	Deck myDeck, aDeck;		//working Deck's
	Card aCard;				//working Card	
	int testsFailedCnt = 0, testsPassedCnt = 0;	//test counts

	cout << "* * * * * Testing our Deck Class * * * * * " << endl;

	//Default Constructor  ***********************************
	//Test capacity, numCards, first Card, lastCard
	myDeck = Deck();	//std 52 cards
	if ((myDeck.getCapacity() != 52) ||
		(myDeck.getNumCards() != 52) ||
		(myDeck.peekCard(0).compareTo(Card(1, 'S')) != 0) ||
		(myDeck.peekCard(51).compareTo(Card(13, 'H')))) {
		cerr << "Error in default constructor of deck\n";
		testsFailedCnt++;
	}
	else {
		testsPassedCnt++;
#ifdef DEBUG_DECK_TEST
		for (int i = 0; i < myDeck.getNumCards(); i++) {//show Deck
			Card c = myDeck.peekCard(i);
			cout << c.toString() << endl;
		}
		cout << endl;
#endif
	}

	//Parameterized Constructor ******************************
	myDeck = Deck(104);	//double Canasta 
	bool flag = myDeck.getCapacity() == 104;	//test capacity
	flag = flag && (myDeck.getNumCards() == 0); //test numCards
	if (flag)
		testsPassedCnt++;
	else {
		cerr << "Making a Deck of 104 Cards failed\n";
		testsFailedCnt++;
	}

	//Parameterized Constructor w/ illegal size **************
	try {
		myDeck = Deck(9999);
		cerr << "Deck Constructor did not catch illegal size\n";
		testsFailedCnt++;
	}
	catch (runtime_error& e) {
		testsPassedCnt++;	//constructor threw runtime_error
	}

	try {	//test negative Deck size **************************
		myDeck = Deck(-9999);
		cerr << "Deck Constructor did not catch illegal size\n";
		testsFailedCnt++;
	}
	catch (runtime_error& e) {
		testsPassedCnt++;	//constructor threw runtime_error
	}

	//Test resetDeck *****************************************
	myDeck = Deck();	//standard Deck
	myDeck.resetDeck();
	if ((myDeck.getCapacity() != 52) ||
		(myDeck.getNumCards() != 52) ||
		(myDeck.peekCard(0).compareTo(Card(1, 'S')) != 0)) {
		cerr << "Error in Deck restore()\n";
		testsFailedCnt++;
	}
	else {
		testsPassedCnt++;
		cout << endl;
	}

	//resetDeck with non52 Card Deck *************************
	myDeck = Deck(10);
	if ((myDeck.getCapacity() != 10) ||
		(myDeck.getNumCards() != 0)) {
		cerr << "Error in Deck restore() not 52 Cards\n";
		testsFailedCnt++;
	}
	else {
		testsPassedCnt++;
	}

	//Test predicate methods: isEmpty ************************
	myDeck = Deck(10);	//makes empty Deck of capacity 10
	if (myDeck.isEmpty())
		testsPassedCnt++;
	else {
		cerr << "Deck.isEmpty() failed to detect empty Deck(10)\n";
		testsFailedCnt++;
	}

	//Test isEmpty with non empty Deck ***********************
	myDeck = Deck();	//makes standard Deck
	if (!myDeck.isEmpty())
		testsPassedCnt++;
	else {
		cerr << "Deck.isEmpty() failed to detect non-empty Deck\n";
		testsFailedCnt++;
	}

	//Test predicate methods: getNumCards *****************
	myDeck = Deck();	//52 Cards
	if (myDeck.getNumCards() == 52)
		testsPassedCnt++;
	else {
		cerr << "getNumCards failed with std Deck\n";
		testsFailedCnt++;
	}

	//getNumCards with Empty Deck ****************************
	myDeck = Deck(5);
	if (myDeck.getNumCards() == 0)
		testsPassedCnt++;
	else {
		cerr << "getNumCards failed with empty Deck\n";
		testsFailedCnt++;
	}

	//Test predicate methods: isFull *****************
	myDeck = Deck();	//52 Cards
	if (myDeck.isFull())
		testsPassedCnt++;
	else {
		cerr << "Deck isFull failed with std Deck\n";
		testsFailedCnt++;
	}

	//isFull with Empty Deck ****************************
	myDeck = Deck(5);
	if (!myDeck.isFull())
		testsPassedCnt++;
	else {
		cerr << "Deck isFull failed with empty Deck\n";
		testsFailedCnt++;
	}


	//Test getCapacity on full deck ***********************
	myDeck = Deck();	//std 52 cards
	if (myDeck.getCapacity() == 52)
		testsPassedCnt++;
	else {
		cerr << "getCapacity failed on full deck\n";
		testsFailedCnt++;
	}

	//Test getCapacity on empty deck **********************
	myDeck = Deck(104);
	if (myDeck.getCapacity() == 104)
		testsPassedCnt++;
	else {
		cerr << "getCapacity failed on empty deck\n";
		testsFailedCnt++;
	}


	//Test dealCard ******************************************
	myDeck = Deck();	//std Deck
	try {
		aCard = myDeck.dealCard();
		//card s/b 1C and deck has 51 cards
		if ((aCard.getFace() == 1) && (aCard.getSuit() == 'S')
			&& (myDeck.getNumCards() == 51))
			testsPassedCnt++;
		else {
			cerr << "dealCard failed to deal Ace of Clubs from new Deck\n";
			testsFailedCnt++;
		}
	}
	catch (exception e) {
		cerr << "Deck dealCard threw exception on dealCard from new Deck\n";
		testsFailedCnt++;
	}

	//dealCard with empty Deck *******************************
	myDeck = Deck(99);
	try {
		aCard = myDeck.dealCard();
		cerr << "Deck dealCard did not detect emtpy Deck\n";
		testsFailedCnt++;
	}
	catch (runtime_error& e) {
		testsPassedCnt++;	//Deal from empty deck threw error
	}

	//deal down a full Deck
	myDeck = Deck();
	int numCards = 0;
	while (!myDeck.isEmpty()) {
		aCard = myDeck.dealCard();
		numCards++;
	}
	if (numCards == 52)
		testsPassedCnt++;
	else {
		cerr << "Deck.dealCard() did not deliver 52 Cards from new Deck";
		testsFailedCnt++;
	}

	//addCard to full Deck ********************************
	myDeck = Deck();	//new std Deck
	aCard = Card();		//ace of clubs
	try {
		myDeck.addCard(aCard);
		cerr << "\nDeck.addCard() failed to detect FULL Deck";
		testsFailedCnt++;
	}
	catch (runtime_error e) {
		testsPassedCnt++;
	}

	//addCard to nonFull Deck *****************************
	myDeck = Deck(10);	//empty Deck
	aCard = Card();		//ace of clubs
	try {
		myDeck.addCard(aCard);
		Card newCard = myDeck.peekCard(0);
		if ((newCard.compareTo(aCard) != 0) ||
			(myDeck.getNumCards() != 1)) {
			cerr << "\nDeck.addCard to Empty Deck failed\n";
			testsFailedCnt++;
		}
		else
			testsPassedCnt++;
	}
	catch (runtime_error e) {
		cerr << "\nDeck.addCard did not add Card to empty Deck" << endl;
		testsFailedCnt++;
	}

	//peekCard with a full Deck ***************************
	myDeck = Deck();	//full Deck
	try {
		aCard = myDeck.peekCard(51); //should be King Hearts
		if ((aCard.getFace() == 13) &&
			(aCard.getSuit() == 'H'))
			testsPassedCnt++;
		else {
			cerr << "Deck peekCard failed - expected King of Hearts "
				<< "but got " << aCard.toString() << endl;
			testsFailedCnt++;
		}
	}
	catch (runtime_error e) {
		cerr << "\nDeck.peekCard incorrectly threw runtime error\n";
		testsFailedCnt++;
	}


	//peekCard with illegal position **********************
	myDeck = Deck();
	try {
		aCard = myDeck.peekCard(9999);
		cerr << "\nDeck.peekCard failed to recognize position > numCards\n";
		testsFailedCnt++;
	}
	catch (runtime_error e) {
		testsPassedCnt++;
	}


	// peekCard with illegal (negative) position **********************
	myDeck = Deck();
	try {
		aCard = myDeck.peekCard(-9999);
		cerr << "\nDeck.peekCard failed to recognize negative position \n";
		testsFailedCnt++;
	}
	catch (runtime_error e) {
		testsPassedCnt++;
	}


	//Test Shuffle ****************************************
	//Test that all 52 Cards still in Deck (no duplicates, etc).
	{//scope this test (and its variables} off
		myDeck = Deck();		//std 52 Cards
		myDeck.shuffleDeck();	//go shuffle

		//now deal each card: 
		//		count #cards, faceValues & suitValues
		int cardCnt = 0;
		int suitCnt[4] = { 0,0,0,0 };
		int faceCnt[13] = { 0 };
		bool faceOK, suitOK;

		while (!myDeck.isEmpty()) { //deal out the whole Deck
			aCard = myDeck.dealCard();	//get a Card
			cardCnt++;					//count it

			//count faces: #Aces, #Jacks, etc
			faceCnt[aCard.getFace() - 1]++;

			//count suits: #Clubs, #Diamonds, etc
			char s = aCard.getSuit();
			if (s == 'C')
				suitCnt[0]++;
			else if (s == 'D')
				suitCnt[1]++;
			else if (s == 'H')
				suitCnt[2]++;
			else if (s == 'S')
				suitCnt[3]++;
			else
				cerr << "Error in testing Deck.shuffleDeck= we got an illegal Card\n";
		}//while deck not empty

		//now look at results
		faceOK = suitOK = true;
		for (int i = 0; i < 4; i++)	//should have 13 of each suit
			if (suitCnt[i] != 13) suitOK = false;

		for (int i = 0; i < 13; i++)	//should have 4 of each face
			if (faceCnt[i] != 4) faceOK = false;

		//We should have 52 Cards, 13 of each suit, and 4 of each face
		if ((cardCnt != 52) || !suitOK || !faceOK) {
			cerr << "Deck.shuffleDeck did not return a std Deck\n";
			testsFailedCnt++;
		}
		else
			testsPassedCnt++;

	}//test shuffleDeck

	//Test shuffle on empty Deck ****************
	myDeck = Deck(10);	//empty Deck
	myDeck.shuffleDeck();
	if (myDeck.getNumCards() == 0)
		testsPassedCnt++;	//nothing blew up
	else {
		testsFailedCnt++;
		cerr << "Deck.shuffleDeck on empty Deck failed\n";
	}


	//Test cutDeck ****************************************
	{//cut caused lots of problems: we scoped the test off
		myDeck = Deck(); //new 52 deck
		myDeck.cutDeck();

		//now deal each card: 
	//		count #cards, faceValues & suitValues
		int cardCnt = 0;
		int suitCnt[4] = { 0,0,0,0 };
		int faceCnt[13] = { 0 };
		bool faceOK, suitOK, inOrder;
		Card hand[5];
		int numCard = 0;

		Card firstCard, lastCard;
		firstCard = myDeck.peekCard(0);
		lastCard = myDeck.peekCard(myDeck.getNumCards() - 1);
		int f = lastCard.getFace();
		char s = lastCard.getSuit();

		//the last card should be successor of first card 
		inOrder = (f == firstCard.getFace() - 1) || ((f == 13) && firstCard.getFace() == 1);

		while (!myDeck.isEmpty()) { //deal out the whole Deck
			aCard = myDeck.dealCard();	//get a Card
			//cout << aCard.toString() << endl;
			cardCnt++;					//count it
			if (cardCnt < 5)
				hand[cardCnt - 1] = aCard; //save 1st five cards

			//count faces: #Aces, #Jacks, etc
			faceCnt[aCard.getFace() - 1]++;

			//count suits: #Clubs, #Diamonds, etc
			char s = aCard.getSuit();
			if (s == 'C')
				suitCnt[0]++;
			else if (s == 'D')
				suitCnt[1]++;
			else if (s == 'H')
				suitCnt[2]++;
			else if (s == 'S')
				suitCnt[3]++;
			else
				cerr << "Error in testing Deck.shuffleDeck= we got an illegal Card\n";
		}//while deck not empty



		faceOK = suitOK = true;
		for (int i = 0; i < 4; i++)	//should have 13 of each suit
			if (suitCnt[i] != 13) suitOK = false;

		for (int i = 0; i < 13; i++)	//should have 4 of each face
			if (faceCnt[i] != 4) faceOK = false;

		//We should have 52 Cards, 13 of each suit, and 4 of each face
		if ((cardCnt != 52) || !suitOK || !faceOK) {
			cerr << "Deck.shuffleDeck did not return a std Deck\n";
			testsFailedCnt++;
		}
		else {
			testsPassedCnt++;
		}
	}//scope for test of cut full deck


	//test cutDeck with empty Deck
	//Program Spec's left intentionally vague...
	// MY solution was to throw error if 
	//		numCards < 10 (Hoyle wants 5+ cards per 'half' in cut)
	myDeck = Deck(13);
	try {
		myDeck.cutDeck();
		cerr << "Tried to Cut an empty Deck\n";
		testsFailedCnt++;
	}
	catch (runtime_error e) {
		testsPassedCnt++;
	}


	/******************************************************
	**********Testing the BIG Three **********************/
	//Copy Constructor
	myDeck = Deck();	//std Deck
	aDeck = Deck(myDeck);	//copy constructor
	aCard = aDeck.peekCard(0);	//get 1st Card

	if ((aDeck.getCapacity() == 52) &&
		(aDeck.getNumCards() == 52) &&
		(aCard.getFace() == 1) && (aCard.getSuit() == 'S'))
		testsPassedCnt++;
	else {
		cerr << "Copy Constructor failed on std Deck\n";
		testsFailedCnt++;
	}

	//test copy constr with empty deck **********
	myDeck = Deck(9);	//empty Deck
	aDeck = Deck(myDeck);	//copy constructor
	if ((aDeck.getCapacity() == 9) &&
		(aDeck.getNumCards() == 0))
		testsPassedCnt++;
	else {
		cerr << "Copy Constructor failed on Empty Deck\n";
		testsFailedCnt++;
	}

	//Test Assignment Operator overload
	//  (we've been relying on this all over the place!)
	myDeck = Deck();	//std Deck
	aDeck = myDeck;
	aCard = aDeck.peekCard(0);
	if ((aDeck.getCapacity() == myDeck.getCapacity()) &&
		(aDeck.getNumCards() == myDeck.getNumCards()) &&
		(aCard.getFace() == myDeck.peekCard(0).getFace()) &&
		(aCard.getSuit() == myDeck.peekCard(0).getSuit()))

		testsPassedCnt++;
	else {
		cerr << "Copy constructor failed on std Deck\n";
		testsFailedCnt++;
	}

	//Test Destructor
	myDeck = Deck();
	aDeck = Deck(myDeck);
	myDeck.~Deck();	//try deleting one deck: is the other OK?

	if ((aDeck.getCapacity() == 52) &&
		(aDeck.getNumCards() == 52) &&
		(myDeck.getCapacity() == 0) &&
		(aDeck.peekCard(0).getFace() == 1) &&
		(aDeck.peekCard(0).getSuit() == 'S'))	//we still have a std aDeck
		testsPassedCnt++;
	else {
		cerr << "Copy constructor failed to do deep copy\n";
		testsFailedCnt++;
	}




	/******************************************************
	********************** Final Results *****************/
	cout << "\nPassed " << testsPassedCnt << " of " << (testsPassedCnt + testsFailedCnt) << " total tests\n";

	cout << "\n\n\t < Normal Termination >\n";
	return(0);
}