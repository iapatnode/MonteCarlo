/**************************************************************************
**Rachel Franklin & Isabella Patnode ~ COMP233.A ~ Deck Implementation File
**************************************************************************/


#include<iostream>
#include "Card.h"
#include "Deck.h"


//Method by Rachel Franklin
//Deck default constructor
//Sets standard 52 card deck
Deck::Deck() {
	int c; //loop variable
	int cardNum; //face value of card

	cardDeck = new Card[52];
	size = 52;
	capacity = 52;

	//Ace to King of Spades
	cardNum = 0;
	for (c = 0; c < 13; c++) {
		cardDeck[c] = Card(cardNum + 1, 'S');
		cardNum++;
	}

	//Ace to King of Diamonds
	cardNum = 0;
	for (c = 13; c < 26; c++) {
		cardDeck[c] = Card(cardNum + 1, 'D');
		cardNum++;
	}

	//Ace to King of Clubs
	cardNum = 0;
	for (c = 26; c < 39; c++) {
		cardDeck[c] = Card(cardNum + 1, 'C');
		cardNum++;
	}

	//Ace to King of Hearts
	cardNum = 0;
	for (c = 39; c < 52; c++) {
		cardDeck[c] = Card(cardNum + 1, 'H');
		cardNum++;
	}
}

//Method by Isabella Patnode
//Deck parameterized constructor - receives specified capacity of deck
//Sets deck of capacity 52 to default deck
//and any other valid capacity to an empty deck of that capacity
//Throws an exception if capacity is illegal (< 0 or > 416)
Deck::Deck(int new_capacity) throw(runtime_error) {
	int c; //loop variable
	int cardNum; //face value of card

	if (new_capacity < 0 || new_capacity > MAX_SIZE) {
		throw runtime_error("Capacity is an illegal value.\n");
	}
	else {
		if (new_capacity == 52) {
			//Creates standard default deck
			cardDeck = new Card[52];
			size = 52;
			capacity = 52;


			//Ace to King of Spades
			cardNum = 0;
			for (c = 0; c < 13; c++) {
				cardDeck[c] = Card(cardNum + 1, 'S');
				cardNum++;
			}

			//Ace to King of Diamonds
			cardNum = 0;
			for (c = 13; c < 26; c++) {
				cardDeck[c] = Card(cardNum + 1, 'D');
				cardNum++;
			}

			//Ace to King of Clubs
			cardNum = 0;
			for (c = 26; c < 39; c++) {
				cardDeck[c] = Card(cardNum + 1, 'C');
				cardNum++;
			}

			//Ace to King of Hearts
			cardNum = 0;
			for (c = 39; c < 52; c++) {
				cardDeck[c] = Card(cardNum + 1, 'H');
				cardNum++;
			}
		}
		else {
			//Creates empty deck with size new_capacity
			cardDeck = new Card[new_capacity];
			size = 0;
			capacity = new_capacity;
		}
	}
}

//Method by Rachel Franklin
//Returns true if deck is empty, false otherwise
bool Deck::isEmpty() {
	if (size == 0) {
		return true;
	}

	return false;
}

//Method by Isabella Patnode
//Returns true if the deck is full, false otherwise
bool Deck::isFull() {
	if (size == capacity) {
		return true;
	}

	return false;
}

//Method by Rachel Franklin
//Returns the number of cards in the deck
int Deck::getNumCards() {
	return size;
}

//Method by Isabella Patnode
//Returns the capacity of the deck
int Deck::getCapacity() {
	return capacity;
}

//Method by Isabella Patnode
//Deals the top card on the deck - returns first card in deck
//Throws exception if deck is empty
Card Deck::dealCard() throw (runtime_error) {
	Card cardDealt; //dealing card
	int c; //loop variable

	if (isEmpty() == true) {
		throw runtime_error("Deck dealCard is using an empty deck.\n");
	}
	else {
		cardDealt = cardDeck[0];

		//update card locations in deck - move each card up a position
		for (c = 0; c < size - 1; c++) {
			cardDeck[c] = cardDeck[c + 1];
		}

		size--;

		return cardDealt;
	}
}

//Method by Rachel Franklin
//Adds received card to the bottom of the deck
//Throws exception if deck is full
void Deck::addCard(Card c) throw (runtime_error) {
	if (size >= capacity) {
		throw runtime_error("Deck addCard is using a full deck.\n");
	}
	else {
		//add card to the bottom of the deck
		cardDeck[size] = c;
		size++;
	}
}

//Method by Isabella Patnode
//Returns a copy of the card at the position given by the parameter
Card Deck::peekCard(int position) throw (runtime_error) {
	Card cardPeek; //copy of card at specified position
	int cardFace; //face of specified card
	char cardSuit; //face of specified suit

	if (position < 0 || position >= size) {
		throw runtime_error("Deck peekCard is using an illegal value\n.");
	}
	else {
		//return a copy of the card at specified position
		cardFace = cardDeck[position].getFace();
		cardSuit = cardDeck[position].getSuit();
		cardPeek = Card(cardFace, cardSuit);

		return cardPeek;
	}
}

//Method by Rachel Franklin
//Shuffles the deck
void Deck::shuffleDeck() {
	int flip, flop; //designate which cards to switch
	int swaps; //loop variable
	Card temp; //copy card

	//don't shuffle deck if deck is empty or has one card
	if (size < 2) {
		return;
	}

	for (swaps = 0; swaps < 500; swaps++) {
		//Reassign random numbers for flip and flop until they are not equal
		do {
			flip = rand() % size;
			flop = rand() % size;
		} while (flip == flop);

		//copy Card at index flip
		temp = cardDeck[flip];

		//assign the card's values at index flop to those at index flip
		cardDeck[flip] = cardDeck[flop];

		//assign the original values of the card at index flip 
		//to those at index flop
		cardDeck[flop] = temp;
	}
}

//Method by Isabella Patnode
//Cuts deck
//Throws exception if an empty deck is being cut
void Deck::cutDeck() throw (runtime_error) {
	int c; //loop variable
	int cutPosition; //index of card being cut
	Card* copyDeck; //copy of the original deck
	int newIndex; // original index of a card

	if (getNumCards() <= 0) {
		throw runtime_error("Deck cutDeck is using an empty deck.\n");
	}
	else {
		//if there are less than 6 cards in the deck, the deck is not cut
		if (getNumCards() <= 10) {
			throw runtime_error("Deck cutDeck has less than 10 cards and can't be cut.\n");
		}
		else {
			do {
				cutPosition = rand() % size;
			} while (cutPosition <= 6);

			copyDeck = new Card[capacity];
			for (int c = 0; c < size; c++) {
				copyDeck[c] = Card(cardDeck[c].getFace(), cardDeck[c].getSuit());
			}

			//second part of original deck starting with the cut card 
			//becomes the first part of the cut deck
			newIndex = 0;
			for (c = cutPosition; c < size; c++) {
				cardDeck[newIndex] = Card(copyDeck[c].getFace(), copyDeck[c].getSuit());
			}

			//first part of original deck up to cut card 
			//becomes second part of the cut deck
			for (c = 0; c < cutPosition; c++) {
				cardDeck[newIndex] = Card(copyDeck[c].getFace(), copyDeck[c].getSuit());
				newIndex++;
			}

			delete[] copyDeck; //garbage collection
		}
	}
}

//Method by Rachel Franklin
//Resets the deck to how it was initialized
void Deck::resetDeck() {
	int c; //loop variable
	int cardNum; //face value of card

	delete[] cardDeck;

	if (capacity == 52) {
		//Creates standard default deck
		cardDeck = new Card[52];
		size = 52;


		//Ace to King of Spades
		cardNum = 0;
		for (c = 0; c < 13; c++) {
			cardDeck[c] = Card(cardNum + 1, 'S');
			cardNum++;
		}

		//Ace to King of Diamonds
		cardNum = 0;
		for (c = 13; c < 26; c++) {
			cardDeck[c] = Card(cardNum + 1, 'D');
			cardNum++;
		}

		//Ace to King of Clubs
		cardNum = 0;
		for (c = 26; c < 39; c++) {
			cardDeck[c] = Card(cardNum + 1, 'C');
			cardNum++;
		}

		//Ace to King of Hearts
		cardNum = 0;
		for (c = 39; c < 52; c++) {
			cardDeck[c] = Card(cardNum + 1, 'H');
			cardNum++;
		}
	}
	else {
		//creates empty deck of given capacity
		cardDeck = new Card[capacity];
		size = 0;
	}
}

//Method by Isabella Patnode
//Deck deep copy constructor
Deck::Deck(const Deck& original) {
	int c; //loop variable

	capacity = original.capacity;
	size = original.size;
	cardDeck = new Card[capacity];

	//copy cards over
	for (c = 0; c < capacity; c++) {
		cardDeck[c] = Card(original.cardDeck[c]);
	}
}

//Method by Rachel Franklin
//Deck assignment operator overload
Deck& Deck::operator=(const Deck& rhs) {
	int c; //loop variable

	if (this != &rhs) {
		capacity = rhs.capacity;
		size = rhs.size;
		delete[] cardDeck;
		cardDeck = new Card[capacity];
		for (c = 0; c < capacity; c++) {
			cardDeck[c] = Card(rhs.cardDeck[c]);
		}
	}

	return *this;
}

//Method by Isabella Patnode
//Deck deep destructor
Deck::~Deck() {
	delete[] cardDeck;
	cardDeck = NULL;
	size = 0;
	capacity = 0;
}