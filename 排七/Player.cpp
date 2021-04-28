#include <iostream>
#include <string>
#include "Player.h"
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

Player::Player(){
	int f = 0, s = 0;

	for (int i = 0; i < 4; i++){
		max[i] = mini[i] = 0;
	}

	for (int i = 0; i < MAX; i++){
		if (f == 13)
			f = 0;
		if (s == 4)
			s = 0;

		cardFace[i] = f;
		cardSuit[i] = s;

		f++;
		s++;
	}

	cover1 = cover2 = 0;

	for (int i = 0; i < F; i++){
		for (int j = 0; j < S; j++){
			card1[i][j] = 0;
			card2[i][j] = 0;
		}
	}
}

void Player::cardorder(){
	srand(time(NULL));

	for (int i = 0; i < MAX; i++){
		int num1 = rand() % MAX;
		int num2 = rand() % MAX;
		int tmp1 = cardFace[num1], tmp2 = cardSuit[num1];

		cardFace[num1] = cardFace[num2];
		cardSuit[num1] = cardSuit[num2];
		cardFace[num2] = tmp1;
		cardSuit[num2] = tmp2;
	}

	for (int i = 0; i < 26; i++){
		card1[cardFace[i]][cardSuit[i]] = 1;
	}

	for (int i = 26; i < 52; i++){
		card2[cardFace[i]][cardSuit[i]] = 1;
	}
}

void Player::hand(){
	for (int i = 0; i < F; i++){
		int a = 0;

		for (int j = 0; j < S; j++){
			if (card1[i][j] == 1){
				a = 1;

				if (j == 0){
					cout << "Heart ";
				}
				else if (j == 1){
					cout << "Pike ";
				}
				else if (j == 2){
					cout << "Tile ";
				}
				else if(j==3){
					cout << "Clover ";
				}
				if (i == 0){
					cout << "A   ";
				}
				else if (i == 10){
					cout << "J   ";
				}
				else if (i == 11){
					cout << "Q   ";
				}
				else if (i == 12){
					cout << "K   ";
				}
				else {
					cout << i + 1 << "   ";
				}
			}
		}

		if (a != 0)
			cout << endl;
	}
}

int Player::Pike7(){
	if (card1[6][1] == 1)
		return 1;
	else
		return 2;
}

void Player::playCard1(){

	if (card1[6][1] == 1){
		cout << "You have Pike 7, please play it\n\n" << "1.Heart  2.Pike  3.Tile  4.Clover\n\n" << "Please enter the suit(flower), and then enter the face(number)\n";
		int i, j;
		cin >> j >> i;

		while (i!=7||j!=2){
			cout << "Please enter again\n";
			cin >> j >> i;
		}

		face(i);
		suit(j);
		drawCard(5);

		max[1] = mini[1] = 7;

		card1[6][1] = 0;
	}

	else if (card1[6][0] == 1 || card1[6][2] == 1 || card1[6][3] == 1){
		
		cout << "You have 7, please play it\n\n" << "1.Heart  2.Pike  3.Tile  4.Clover\n\n" << "Please enter the suit(flower), and then enter the face(number)\n";
		int i, j;
		cin >> j >> i;

		while (i!=7||j<1||j>4){
			cout << "Please enter again\n";
			cin >> j >> i;
		}

		face(i);
		suit(j);
		drawCard(j + 3);

		max[j - 1] = mini[j - 1] = 7;

		card1[6][j - 1] = 0;
	}

	else if (card1[max[0]][0] == 1 || card1[max[1]][1] == 1 || card1[max[2]][2] == 1 || card1[max[3]][3] == 1 || card1[mini[0] - 2][0] == 1 || card1[mini[1] - 2][1] == 1 || card1[mini[2] - 2][2] == 1 || card1[mini[3] - 2][3] == 1){
		cout << "Which card would you want to play?\n\n" << "1.Heart  2.Pike  3.Tile  4.Clover\n\n" << "Please enter the suit(flower), and then enter the face(number)\n";
		int i, j;
		cin >> j >> i;

		while (i < 1 || i>13 || j < 1 || j>4){
			cout << "Please enter again\n";
			cin >> j >> i;
		}

		while (card1[i - 1][j - 1] == 0){
			cout << "Please enter again\n";
			cin >> j >> i;
		}

		face(i);
		suit(j);
		if (i > 7){
			max[j - 1] = i;
			drawCard(j - 1);
		}
			
		else{
			mini[j - 1] = i;
			drawCard(j + 7);
		}

		card1[i - 1][j - 1] = 0;
	}

	else {
		cout << "You don't have card to play, please cover a card\n\n" << "1.Heart  2.Pike  3.Tile  4.Clover\n\n" << "Please enter the suit(flower), and then enter the face(number)\n";
		int i, j;
		cin >> j >> i;

		while (i < 1 || i>13 || j < 1 || j>4){
			cout << "Please enter again\n";
			cin >> j >> i;
		}

		while (card1[i - 1][j - 1] == 0){
			cout << "Please enter again\n";
			cin >> j >> i;
		}

		cover1 += i;

		card1[i - 1][j - 1] = 0;
	}
}

void Player::playCard2(){
	if (card2[6][1] == 1){
		cout << "The computer has Pike 7\n" << "The computer plays Pike 7\n\n";

		face(7);
		suit(2);

		drawCard(5);

		max[1] = mini[1] = 7;

		card2[6][1] = 0;
	}
	else if (card2[6][0] == 1 || card2[6][2] == 1 || card2[6][3] == 1){
		cout << "The computer plays ";

		if (card2[6][0] == 1){
			cout << "Heart 7\n\n";
			face(7);
			suit(1);

			drawCard(4);

			max[0] = mini[0] = 7;
			card2[6][0] = 0;
		}
		else if (card2[6][2] == 1){
			cout << "Tile 7\n\n";
			face(7);
			suit(3);

			drawCard(6);

			max[2] = mini[2] = 7;
			card2[6][2] = 0;
		}
		else if (card2[6][3] == 1){
			cout << "Clover 7\n\n";
			face(7);
			suit(4);

			drawCard(7);

			max[3] = mini[3] = 7;
			card2[6][3] = 0;
		}
	}
	else if (card2[max[0]][0] == 1 || card2[max[1]][1] == 1 || card2[max[2]][2] == 1 || card2[max[3]][3] == 1 || card2[mini[0] - 2][0] == 1 || card2[mini[1] - 2][1] == 1 || card2[mini[2] - 2][2] == 1 || card2[mini[3] - 2][3] == 1){
		cout << "The computer plays ";
		for (int i = 0; i < S; i++){

			if (card2[mini[i] - 2][i] == 1){
				if (i == 0){
					cout << "Heart ";	
				}
				else if (i == 1){
					cout << "Pike ";
				}
				else if (i == 2){
					cout << "Tile ";
				}
				else{
					cout << "Clover ";
				}

				if (mini[i] - 1 == 1) {
					cout << "A\n\n";
				}
				else{
					cout << mini[i] - 1 << endl << endl;
				}

				face(mini[i] - 1);
				suit(i + 1);
				drawCard(i + 8);
				card2[mini[i] - 2][i] = 0;

				mini[i]--;

				if (mini[i] <= 0)
					mini[i] = 1;

				break;
			}
			else if (card2[max[i]][i] == 1) {
				if (i == 0){
					cout << "Heart ";
				}
				else if (i == 1){
					cout << "Pike ";
				}
				else if (i == 2){
					cout << "Tile ";
				}
				else{
					cout << "Clover ";
				}

				if (max[i] + 1 == 11){
					cout << "J\n\n";
				}

				else if (max[i] + 1 == 12){
					cout << "Q\n\n";
				}
				else if (max[i] + 1 == 13){
					cout << "K\n\n";
				}
				else {
					cout << max[i] + 1 << endl << endl;
				}

				face(max[i] + 1);
				suit(i + 1);

				drawCard(i);
				card2[max[i]][i] = 0;

				max[i]++;

				if (max[i] > 13)
					max[i] = 13;

				break;

			}
		}
	}
	else{
		cout << "The computer covers a card\n\n";

		int flag = 0;

		for (int i = 0; i < 13; i++){
			for (int j = 0; j < 4; j++){
				if (card2[i][j] == 1){
					cover2 += (i + 1);
					card2[i][j] = 0;
					flag = 1;
					break;
				}
			}
			if (flag != 0)
				break;
		}
	}
}

bool Player::check(){

	for (int i = 0; i < S; i++){
		if (max[i] == 13 && mini[i] == 1)
			return false;
	}
	return true;
}

void Player::endGame(){
	cout << "You covered " << cover1 << " points\n\n" << "The computer covered " << cover2 << " points\n\n";

	if (cover1 < cover2)cout << "You win!! :)\n";
	else if (cover1>cover2)cout << "You lose :(\n";
	else cout << "The game resulted in  a tie :|\n";
}
