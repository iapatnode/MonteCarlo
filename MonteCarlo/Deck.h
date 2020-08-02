/******************************************************************
**Rachel Franklin & Isabella Patnode ~ COMP233.A ~ Deck Header File
******************************************************************/

#pragma once
#include "Card.h"
using namespace std;

class Deck {
private:
	Card* cardDeck;
	int size;
	int capacity;
	const int MAX_SIZE = 416;

public:
	Deck();
	Deck(int new_capacity) throw (runtime_error);

	bool isEmpty();
	bool isFull();
	int getNumCards();
	int getCapacity();

	Card dealCard() throw (runtime_error);
	void addCard(Card c) throw (runtime_error);
	Card peekCard(int position) throw (runtime_error);
	void shuffleDeck();
	void cutDeck() throw (runtime_error);
	void resetDeck();

	Deck(const Deck& original);
	Deck& operator=(const Deck& rhs);
	~Deck();
};
