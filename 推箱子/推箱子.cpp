#include <iostream>
#include <stdlib.h>
#include <fstream>

#define MAX 200

using namespace std;

int printMap1(fstream &map, char(&mapArray)[MAX][MAX]);
void clearMapArray(char(&mapArray)[MAX][MAX]);
void move(char(&mapArray)[MAX][MAX], char(&copy)[MAX][MAX], int max);
bool check(char(&mapArray)[MAX][MAX], char(&copy)[MAX][MAX]);
void printMap2(char(&mapArray)[MAX][MAX], int max);
void copyMap(char(&mapArray)[MAX][MAX], char(&copy)[MAX][MAX], int max);

int total = 0;

int main(int argc, char *argv[]){

	system("CLS");

	char mapArray[MAX][MAX], copy[MAX][MAX];
	int max;
	fstream map;

	map.open(argv[1], ios::in);

	if (!map.is_open()){
		cout << "Open " << argv[1] << " fail...\n";
	}
	else{
		clearMapArray(mapArray);
		max = printMap1(map, mapArray);
		map.close();
		copyMap(mapArray, copy, max);

		while (check(mapArray, copy)){
			move(mapArray, copy, max);
			printMap2(mapArray, max);
		}

		cout << "\nGame completed\n\n" << "Total foot steps are " << total << endl;
	}

	return 0;
}

int printMap1(fstream &map, char(&mapArray)[MAX][MAX]){
	char array[MAX];

	for (int i = 0; i < MAX; i++){
		array[i] = ' ';
	}

	int i = 0;

	do{
		map.getline(array, MAX);

		for (int j = 0; j < MAX; j++){
			mapArray[i][j] = array[j];
		}

		i++;

	} while (!map.eof());

	int max = i + 1;

	for (int i = 0; i < max; i++){
		for (int j = 0; j < MAX; j++){
			if (mapArray[i][j] == ' '){
				break;
			}
			cout << mapArray[i][j];
		}
		cout << endl;
	}

	return max;
}

void clearMapArray(char(&mapArray)[MAX][MAX]){
	for (int i = 0; i < MAX; i++){
		for (int j = 0; j < MAX; j++){
			mapArray[i][j] = ' ';
		}
	}
}

bool check(char(&mapArray)[MAX][MAX], char(&copy)[MAX][MAX]){
	int sum1 = 0, sum2 = 0;

	for (int i = 0; i<MAX; i++){
		for (int j = 0; j<MAX; j++){
			if (copy[i][j] == 'E')
				sum1++;

			if (mapArray[i][j] == 'B'&&copy[i][j] == 'E')
				sum2++;
		}
	}

	if (sum1 == sum2)
		return false;
	else
		return true;

}

void printMap2(char(&mapArray)[MAX][MAX], int max){
	system("CLS");

	for (int i = 0; i < max; i++){
		for (int j = 0; j < MAX; j++){
			if (mapArray[i][j] == ' '){
				break;
			}
			cout << mapArray[i][j];
		}
		cout << endl;
	}
}

void move(char(&mapArray)[MAX][MAX], char(&copy)[MAX][MAX], int max){
	cout << "\n\nUp : w	Down : s	Left : a	Right : d\n\n";
	cout << "Please enter the direction : ";

	int x = 0, y = 0, flag = 0;

	for (y = 0; y<max; y++){
		for (x = 0; x<MAX; x++){
			if (mapArray[y][x] == 'A'){
				flag = 1;
				break;
			}
		}
		if (flag == 1){
			break;
		}

	}

	char dir;
	cin >> dir;

	if (dir == 's'){
		if (mapArray[y + 1][x] == '*' || mapArray[y + 1][x] == 'E'){

			mapArray[y + 1][x] = 'A';
			mapArray[y][x] = copy[y][x];
			total++;
		}
		else if (mapArray[y + 1][x] == 'B'){
			if (mapArray[y + 2][x] == '*' || mapArray[y + 2][x] == 'E'){

				mapArray[y + 2][x] = 'B';
				mapArray[y + 1][x] = 'A';
				mapArray[y][x] = copy[y][x];
				total++;
			}
		}
	}

	else if (dir == 'w'){
		if (mapArray[y - 1][x] == '*' || mapArray[y - 1][x] == 'E'){

			mapArray[y - 1][x] = 'A';
			mapArray[y][x] = copy[y][x];
			total++;
		}
		else if (mapArray[y - 1][x] == 'B'){
			if (mapArray[y - 2][x] == '*' || mapArray[y - 2][x] == 'E'){

				mapArray[y - 2][x] = 'B';
				mapArray[y - 1][x] = 'A';
				mapArray[y][x] = copy[y][x];
				total++;
			}
		}
	}

	else if (dir == 'a'){
		if (mapArray[y][x - 1] == '*' || mapArray[y][x - 1] == 'E'){

			mapArray[y][x - 1] = 'A';
			mapArray[y][x] = copy[y][x];
			total++;
		}
		else if (mapArray[y][x - 1] == 'B'){
			if (mapArray[y][x - 2] == '*' || mapArray[y][x - 2] == 'E'){

				mapArray[y][x - 2] = 'B';
				mapArray[y][x - 1] = 'A';
				mapArray[y][x] = copy[y][x];
				total++;
			}
		}
	}

	else if (dir == 'd'){
		if (mapArray[y][x + 1] == '*' || mapArray[y][x + 1] == 'E'){

			mapArray[y][x + 1] = 'A';
			mapArray[y][x] = copy[y][x];
			total++;
		}
		else if (mapArray[y][x + 1] == 'B'){
			if (mapArray[y][x + 2] == '*' || mapArray[y][x + 2] == 'E'){

				mapArray[y][x + 2] = 'B';
				mapArray[y][x + 1] = 'A';
				mapArray[y][x] = copy[y][x];
				total++;
			}
		}
	}
}

void copyMap(char(&mapArray)[MAX][MAX], char(&copy)[MAX][MAX], int max){
	for (int i = 0; i<MAX; i++){
		for (int j = 0; j<MAX; j++){
			copy[i][j] = ' ';
		}
	}

	for (int i = 0; i<max; i++){
		for (int j = 0; j<MAX; j++){
			if (mapArray[i][j] == 'A' || mapArray[i][j] == 'B'){
				copy[i][j] = '*';
				continue;
			}
			copy[i][j] = mapArray[i][j];
		}
	}
}