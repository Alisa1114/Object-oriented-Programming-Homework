#include <iostream>
#include <string>
#include <stdlib.h>
#include "Player.h"

#define FACE 13
#define SUIT 4

using namespace std;

int main(){

	int choice = 1;

	while (choice == 1){
		Player pl;

		pl.cardorder();

		int order = pl.Pike7();

		if (order == 1){
			while (pl.check()){
				cout << "Your turn\n\n";
				pl.hand();
				pl.playCard1();

				cout << "The comperter's turn\n\n";
				pl.playCard2();
				pl.printCard();
			}
		}
		else{
			while (pl.check()){
				cout << "The comperter's turn\n\n";
				pl.playCard2();
				pl.printCard();
				cout << "Your turn\n\n";
				pl.hand();
				pl.playCard1();
				pl.printCard();
			}
		}

		pl.endGame();

		cout << "Would you want to play the game again?\n" << "1.Yes  2.No\n";

		cin >> choice;

		while (choice < 1 || choice>2){
			cout << "Please enter again\n";
			cin >> choice;
		}
	}

	return 0;
}
