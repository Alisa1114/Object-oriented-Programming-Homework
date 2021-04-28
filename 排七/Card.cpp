#include <string>
#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(){
	_face = 0;
	_suit = 0;

	for (int i = 0; i < N; i++){
		for (int j = 0; j < L; j++){
			for (int k = 0; k < W; k++){
				picture[i][j][k] = ' ';
			}
		}
	}
}

void Card::face(int face){

	_face = face;
}

void Card::suit(int suit){

	_suit = suit;
}

void Card::drawCard(int i){

	for (int j = 0; j < L; j++){
		for (int k = 0; k < W; k++){
			picture[i][j][k] = ' ';
		}
	}

	for (int a = 0; a < W; a++){
		picture[i][0][a] = picture[i][L - 1][a] = '*';
	}

	for (int a = 1; a < L - 1; a++){
		picture[i][a][0] = picture[i][a][W - 1] = '*';
	}

	switch (_face){
	case 1:
		picture[i][1][2] = picture[i][8][8] = 'A';
		break;

	case 10:
		picture[i][1][1] = '1';
		picture[i][1][2] = '0';
		picture[i][8][8] = '1';
		picture[i][8][9] = '0';
		break;

	case 11:
		picture[i][1][2] = 'J';
		picture[i][8][8] = 'J';
		break;

	case 12:
		picture[i][1][2] = 'Q';
		picture[i][8][8] = 'Q';
		break;

	case 13:
		picture[i][1][2] = 'K';
		picture[i][8][8] = 'K';
		break;

	default:
		picture[i][1][2] = _face + '0';
		picture[i][8][9] = _face + '0';
		break;
	}

	switch (_suit){

	case 1:
		drawHeart(i);
		break;

	case 4:
		drawTile(i);
		break;

	case 3:
		drawClover(i);
		break;

	case 2:
		drawPike(i);
		break;
	}
}

void Card::drawHeart(int i){
	picture[i][3][4] = picture[i][3][6] = picture[i][4][3] = picture[i][4][5] = picture[i][4][7] = picture[i][5][4] = picture[i][5][6] = picture[i][6][5] = '*';
}

void Card::drawClover(int i){
	picture[i][3][5] = picture[i][4][4] = picture[i][4][6] = picture[i][5][3] = picture[i][5][7] = picture[i][6][4] = picture[i][6][6] = picture[i][7][5] = '*';
}

void Card::drawPike(int i){
	picture[i][2][5] = picture[i][3][4] = picture[i][3][6] = picture[i][4][3] = picture[i][4][7] = picture[i][5][3] = picture[i][5][5] = picture[i][5][7] = picture[i][6][4] = picture[i][6][5] = picture[i][6][6] = picture[i][7][5] = picture[i][8][4] = picture[i][8][5] = picture[i][8][6] = '*';
}

void Card::drawTile(int i){
	picture[i][2][4] = picture[i][2][5] = picture[i][2][6] = picture[i][3][4] = picture[i][3][5] = picture[i][3][6] = picture[i][4][2] = picture[i][4][3] = picture[i][4][5] = picture[i][4][7] = picture[i][4][8]
		= picture[i][5][2] = picture[i][5][3] = picture[i][5][5] = picture[i][5][7] = picture[i][5][8] = picture[i][6][5] = picture[i][7][4] = picture[i][7][5] = picture[i][7][6] = '*';
}

void Card::printCard(){
	for (int j = 0; j < L; j++){
		for (int i = 0; i < 4; i++){
			for (int k = 0; k < W; k++){
				cout << picture[i][j][k];
			}
			cout << "  ";
		}
		cout << endl;
	}

	for (int j = 0; j < L; j++){
		for (int i = 4; i < 8; i++){
			for (int k = 0; k < W; k++){
				cout << picture[i][j][k];
			}
			cout << "  ";
		}
		cout << endl;
	}

	for (int j = 0; j < L; j++){
		for (int i = 8; i < 12; i++){
			for (int k = 0; k < W; k++){
				cout << picture[i][j][k];
			}
			cout << "  ";
		}
		cout << endl;
	}
}