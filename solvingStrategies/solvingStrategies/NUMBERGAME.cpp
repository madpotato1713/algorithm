#include<iostream>
#include<algorithm>

using namespace std;

const int NEGINF = -987654321;
int n;
int board[50];
int cache[50][50];

//현재 player의 점수 최대치를 반환
int numberGame(int left, int right) {

	if (left == right) return board[left];
	if (left > right) return 0;

	int& res = cache[left][right];
	if (res != NEGINF) return res;

	//case 1
	res = board[left] - numberGame(left + 1, right);
	//case 2
	res = max(res, board[right] - numberGame(left, right - 1));
	if (right - left >= 2) {
		//case 3
		res = max(res, -numberGame(left + 2, right));
		//case 4;
		res = max(res, -numberGame(left, right - 2));
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		for (int i = 0; i < 50; i++) {
			for (int j = 0; j < 50; j++) {
				cache[i][j] = NEGINF;
			}
		}

		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> board[i];
		}

		cout << numberGame(0, n - 1) << endl;
	}

	return 0;
}