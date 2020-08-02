///************************************************
//** Joe College ~ COMP233 ~ Testing Card Class
//** Unit Test for our Card class
//**
//** Base form of a Unit Test is:
//**	1) create your data - do NOT rely on "old" data
//**	2) do the test
//**	3) if the test succeeds, just incr. testPassCnt
//**		else print msg to cerr & incr. testFailCnt
//************************************************/
//
//
//#pragma once
//#include "Card.h"
//#include <iostream>
//using namespace std;
///*************************************************
//******************************** M A I N ********/
//
//
//int main() {
//	int testPassCnt, testFailCnt;	//test unit scores
//	Card cardA, cardB;				//practice Cards
//	char legalSuits[] = "CDHS";		//legal Suit char's
//
//	//init
//	cout << "***** Testing the Card Class *****\n";
//	testPassCnt = testFailCnt = 0;
//
//	//Test Default Contructor *******************
//	cardA = Card();	//make fresh Card- ace of clubs
//	if ((cardA.getFace() != 1) || (cardA.getSuit() != 'C')) {
//		cerr << "Default Constructor did not make Ace of Clubs\n";
//		testFailCnt++;
//	}
//	else
//		testPassCnt++;
//
//
//	//Parmeterized Construcor *******************
//	cardB = Card(5, 'H');
//	if ((cardB.getFace() != 5) || (cardB.getSuit() != 'H')) {
//		cerr << "Parameterized Constructor did not make Five of Hearts\n";
//		testFailCnt++;
//	}
//	else
//		testPassCnt++;
//
//	//Setters
//	cardA = Card();	//ace of clubs
//	cardA.setFace(5);	//set 5 of Clubs
//	if (cardA.getFace() != 5) {
//		cerr << "Card setFace failed with value 5" << endl;
//		testFailCnt++;
//	}
//	else
//		testPassCnt++;
//
//
//	//try all legal suits
//	for (int i = 0; i < 4; i++) {
//		cardA = Card();	//make fresh ace of clubs
//		cardA.setSuit(legalSuits[i]);
//		if (cardA.getSuit() != legalSuits[i]) {
//			cerr << "setSuit failed to set suit: " << legalSuits[i] << endl;
//			testFailCnt++;
//		}
//		else
//			testPassCnt++;
//	}//next suit
//
//	//try illegal face value ********************
//	try {
//		cardB.setFace(99);
//		cerr << "setFace failed to throw exception for 99 Face value";
//		testFailCnt++;
//	}
//	catch (runtime_error& e) {
//		//cerr << e.what() << endl;
//		testPassCnt++;
//	}
//
//	//try negative face value ********************
//	try {
//		cardB = Card();	//fresh ace of clubs
//		cardB.setFace(-99);
//		cerr << "setFace failed to throw exception for negative Face value";
//		testFailCnt++;
//	}
//	catch (runtime_error& e) {
//		//cerr << e.what() << endl;
//		testPassCnt++;
//	}
//
//	//try illegal suit **************************
//	try {
//		cardB = Card();	//ace of clubs
//		cardB.setSuit('x');
//		cerr << "setSuit failed to throw exception for bad suit value: x" << endl;
//		testFailCnt++;
//	}
//	catch (runtime_error& e) {//setSuit threw error
//		testPassCnt++;
//	}
//
//
//	//Test Getters ******************************
//	//getFace
//	cardA = Card();	//ace clubs
//	if (cardA.getFace() == 1) {
//		testPassCnt++;
//	}
//	else {
//		cerr << "getFace failed to find Ace in Ace of Clubs\n";
//		testFailCnt++;
//	}
//
//
//	//getSuit
//	cardA = Card();  //ace clubs
//	if (cardA.getSuit() == 'C')
//		testPassCnt++;
//	else {
//		cerr << "getSuit failed to find Clubs in ace clubs\n";
//		testFailCnt++;
//	}
//
//	//test toString *****************************
//	cardA = Card();
//	if (cardA.toString().compare("Ace of Clubs") != 0) {
//		cerr << "Card toString failed to return 'Ace of Clubs' : "
//			<< cardA.toString() << endl;
//		testFailCnt++;
//	}
//	else
//		testPassCnt++;
//
//	//Test compareTo WITH optional parameter
//	cardA = Card();	//ace of clubs
//	cardB = Card(2, 'H');	//2 of hearts
//	if (cardA.compareTo(cardB, false) < 0) {  //ace is NOT high
//		testPassCnt++;
//	}
//	else {
//		cerr << "compareTo failed to find 1C less than 2H" << endl;
//		testFailCnt++;
//	}
//
//	//Now test with aceHigh true ****************
//	cardA = Card();
//	cardB = Card(2, 'H');
//	if (cardA.compareTo(cardB, true) > 0) //ace IS high
//		testPassCnt++;
//	else {
//		cerr << "compareTo failed to find 1C greater than 2H with true param\n";
//		testFailCnt++;
//	}
//
//	//Now test for equal ************************
//	cardA = Card();
//	cardB = Card(1, 'D');
//	if (cardB.compareTo(cardA, true) == 0)
//		testPassCnt++;
//	else {
//		cerr << "compareTo failed to find 1C == 1D\n";
//		testFailCnt++;
//	}
//
//	//test for equal with false param
//	cardA = Card(4, 'D');
//	cardB = Card(4, 'H');
//	if (cardB.compareTo(cardA) == 0)
//		testPassCnt++;
//	else {
//		cerr << "compareTo failed to fine 4H==4D\n";
//		testFailCnt++;
//	}
//
//	//Test compareTo without parameter
//	cardA = Card();	//ace of clubs
//	cardB = Card(8, 'D');
//	if (cardA.compareTo(cardB) < 0)
//		testPassCnt++;
//	else {
//		cerr << "compareTo faile to find 1C < 8D\n";
//		testFailCnt++;
//	}
//
//	//Test compareTo without parameter
//	cardA = Card();	//ace of clubs
//	cardB = Card(1, 'D');
//	if (cardA.compareTo(cardB) == 0)
//		testPassCnt++;
//	else {
//		cerr << "compareTo faile to find 1C == 1D\n";
//		testFailCnt++;
//	}
//
//	//Test compareTo without parameter
//	cardA = Card(9, 'D');
//	cardB = Card(8, 'D');
//	if (cardA.compareTo(cardB) > 0)
//		testPassCnt++;
//	else {
//		cerr << "compareTo failed to find 9D > 8D\n";
//		testFailCnt++;
//	}
//
//	//Finish Up
//	cout << "\nPassed " << testPassCnt << " of " << (testPassCnt + testFailCnt) << " total tests\n";
//	cout << "\n\n\t< normal termination >\n";
//
//	return 0;
//}  //main 