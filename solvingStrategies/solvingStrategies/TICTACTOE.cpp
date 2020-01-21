#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

char board[3][3];
int cache[19683];

//board 확인해서 승부가 났는지 리턴하는 함수
//x가 이기면 1, o가 이기면 2, 아니면 0을 리턴한다.
int isGameEnd() {
	
	//가로
	bool gameEnd;
	for (int y = 0; y < 3; y++) {
		gameEnd = true;
		for (int x = 0; x < 2; x++) {
			if (board[y][x] == '.' || board[y][x] != board[y][x + 1]) {
				gameEnd = false;
				break;
			}
		}
		if (gameEnd) {
			return board[y][0] == 'x' ? 1 : 2;
		}
	}

	//세로
	gameEnd = true;
	for (int x = 0; x < 3; x++) {
		gameEnd = true;
		for (int y = 0; y < 2; y++) {
			if (board[y][x] == '.' || board[y][x] != board[y + 1][x]) {
				gameEnd = false;
				break;
			}
		}
		if (gameEnd) {
			return board[0][x] == 'x' ? 1 : 2;
		}
	}

	//대각선
	if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) return board[0][0] == 'x' ? 1 : 2;
	if (board[0][2] != '.' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) return board[0][2] == 'x' ? 1 : 2;

	return 0;
}

//cache에 맵핑할 인덱스를 생성하는 함수.
int toIndex() {
	int idx = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			idx += pow(3, 3 * y + x) * (board[y][x] == 'x' ? 1 : board[y][x] == 'o' ? 2 : 0);
		}
	}
	return idx;
}

bool isFinished(char turn) {
	//가로
	for (int i = 0; i < 3; i++)	{
		for (int j = 0; j < 3; j++)	{
			if (board[i][j] != turn)
				break;
			if (j == 2)
				return true;
		}
	}

	//세로
	for (int i = 0; i < 3; i++)	{
		for (int j = 0; j < 3; j++)	{
			if (board[j][i] != turn)
				break;
			if (j == 2)
				return true;
		}
	}

	//대각선
	for (int i = 0; i < 3; i++)	{
		if (board[i][i] != turn)
			break;
		if (i == 2)
			return true;
	}
	for (int i = 0; i < 3; i++)	{
		if (board[i][2 - i] != turn)
			break;
		if (i == 2)
			return true;
	}
	return false;
}

int bijection() {
	int ret = 0;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			ret = ret * 3;
			if (board[y][x] == 'o') ret++;
			else if (board[y][x] == 'x') ret += 2;
		}
	}
	return ret;
}

int canWin(char turn) {
	if (isFinished('o' + 'x' - turn)) return -1;
	int& ret = cache[bijection()];
	if (ret != -2) return ret;

	int minValue = 2;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (board[y][x] == '.') {
				board[y][x] = turn;
				minValue = min(minValue, canWin('o' + 'x' - turn));
				board[y][x] = '.';
			}
		}
	}

	if (minValue == 2 || minValue == 0) return ret = 0;
	return ret = -minValue;
}

int isWin(char turn) {
	if (isGameEnd()) return isGameEnd();

	int& res = cache[toIndex()];
	if (res != -1) return res;

	res = 3;
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 3; x++) {
			if (board[y][x] == '.') {
				board[y][x] = turn;
				int result = isWin('x' + 'o' - turn);
				if (turn == 'x') {
					if (result == 1) res = 1;
					else if(res != 1) res = min(res, result);
				}
				else if (turn == 'o') {
					if (result == 2) res = 2;
					else if (res != 2) res = min(res, result);
				}
				board[y][x] = '.';
			}
		}
	}

	if (res == 3) return res = 0;
	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		//memset(cache, -1, sizeof(cache));
		for (int i = 0; i < 19683; i++) cache[i] = -2;

		int xc = 0, oc = 0;
		for (int y = 0; y < 3; y++) {
			for (int x = 0; x < 3; x++) {
				cin >> board[y][x];
				if (board[y][x] == 'x') xc++;
				if (board[y][x] == 'o') oc++;
			}
		}

		//int res = isWin(xc <= oc ? 'x' : 'o');
		//cout << (res == 0 ? "TIE" : res == 1 ? "x" : "o") << endl;

		char turn = xc <= oc ? 'x' : 'o';
		int res = canWin(turn);
		if (res == 0) cout << "TIE" << endl;
		else cout << (res == 1 ? turn : (char)('x' + 'o' - turn)) << endl;
	}

	return 0;
}