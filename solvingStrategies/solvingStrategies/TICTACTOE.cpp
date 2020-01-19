#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

char board[3][3];
int cache[19683];

int map2num() {
	int res = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			int mul = (board[y][x] == '.' ? 0 : board[y][x] == 'x' ? 1 : 2);
			res += pow(3, 3 * y + x) * mul;
		}
	}

	return res;
}

int checkBoard() {
	//비기면 0
	//x가 이기면 1
	//o가 이기면 2

	//row
	for (int y = 0; y < 3; y++) {
		if (board[y][0] != '.' && board[y][0] == board[y][1] && board[y][1] == board[y][2]) {
			if (board[y][0] == 'x') return 1;
			else return 2;
		}
	}

	//col
	for (int x = 0; x < 3; x++) {
		if (board[0][x] != '.' && board[0][x] == board[1][x] && board[1][x] == board[2][x]) {
			if (board[0][x] == 'x') return 1;
			else return 2;
		}
	}

	//diagonal
	if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
		if (board[0][0] == 'x') return 1;
		else return 2;
	}
	if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
		if (board[0][2] == 'x') return 1;
		else return 2;
	}

	return 0;
}

int isWin(int turn) {
	int& res = cache[map2num()];
	if (res != -1) return res;

	res = checkBoard();
	if (res != 0) return res;

	int check = 3;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (board[y][x] == '.') {
				if (turn == 1) {
					board[y][x] = 'x';
					check = min(check, isWin(2));
					board[y][x] = '.';
				}
				else {
					board[y][x] = 'o';
					check = min(check, isWin(1));
					board[y][x] = '.';
				}
			}
			if (check != 0 && check != 3) return check;
		}
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));

		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				cin >> board[y][x];
			}
		}

		cout << isWin(1) << endl;
	}

	return 0;
}