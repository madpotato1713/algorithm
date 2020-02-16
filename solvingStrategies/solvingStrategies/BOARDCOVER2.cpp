#include<iostream>
#include<cstring>

using namespace std;

int H, W, R, C;
int board[10][10], block[10][10];

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> H >> W >> R >> C;

		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				char ch;
				cin >> ch;
				board[y][x] = (ch == '#' ? -1 : 0);
			}
		}

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				char ch;
				cin >> ch;
				block[y][x] = (ch == '#' ? -1 : 0);
			}
		}


	}

	return 0;
}