#include <iostream>
#include <string>

#define L 10
#define W 11
#define MAX 52
#define N 12

using namespace std;

class Card{

	int _face, _suit;
	char picture[N][L][W];

public:
	Card();
	void face(int);
	void suit(int);
	void drawHeart(int);
	void drawTile(int);
	void drawClover(int);
	void drawPike(int);
	void drawCard(int);
	void printCard();

};
