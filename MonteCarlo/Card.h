/******************************************************************
**Rachel Franklin & Isabella Patnode ~ COMP233.A ~ Card Header File
******************************************************************/

#pragma once
#include<string>
#include<stdexcept>
using namespace std;

class Card {

private: 
	int cardNum;

public:
	Card();
	Card(int f, char s) throw (runtime_error);

	const int getFace();
	const char getSuit();

	void setFace(int f) throw (runtime_error);
	void setSuit(char s) throw(runtime_error);

	string toString();

	int compareTo(const Card other, bool aceIsHigh = false);
};
