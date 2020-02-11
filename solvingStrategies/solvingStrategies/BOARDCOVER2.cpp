#include<iostream>
#include<cstring>

using namespace std;

int H, W, R, C;
char board[10][10], block[10][10];

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> H >> W >> R >> C;

		for (int y = 0; y < H; y++) {
			for (int x = 0; x < W; x++) {
				cin >> board[y][x];
			}
		}

		for (int y = 0; y < R; y++) {
			for (int x = 0; x < C; x++) {
				cin >> block[y][x];
			}
		}


	}

	return 0;
}