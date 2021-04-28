#include "Card.h"
#include <iostream>

using namespace std;

#define F 13
#define S 4
#define M 26

class Player : public Card{
	int cover1, cover2, cardFace[MAX], cardSuit[MAX], card1[F][S],card2[F][S], order, max[4], mini[4];
	
public:
	Player();//
	void hand();//
	void playCard1();//
	void playCard2();//
	int Pike7();//
	void cardorder();//
	bool check();//
	void endGame();//
};