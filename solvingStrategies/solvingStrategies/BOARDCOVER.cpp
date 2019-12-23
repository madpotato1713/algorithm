#include<iostream>

using namespace std;

int H, W;
int map[20][20];

int dir[4][2][2] = {
	{{0, 1}, {1, 0}},
	{{0, 1}, {1, 1}},
	{{1, 0}, {1, 1}},
	{{1, -1}, {1, 0}},
};

int board() {
	int y, x;
	y = x = -1;
	bool flag = false;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 0) {
				y = i;
				x = j;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (y == -1)
		return 1;

	int res = 0;
	bool isChanged = false;
	for (int i = 0; i < 4; i++) {
		if (y + dir[i][0][0] >= 0 && x + dir[i][0][1] >= 0
			&& y + dir[i][1][0] >= 0 && x + dir[i][1][1] >= 0
			&& y + dir[i][0][0] < H && x + dir[i][0][1] < W
			&& y + dir[i][1][0] < H && x + dir[i][1][1] < W
			&& map[y + dir[i][0][0]][x + dir[i][0][1]] == 0
			&& map[y + dir[i][1][0]][x + dir[i][1][1]] == 0) {
			map[y][x] = 1;
			map[y + dir[i][0][0]][x + dir[i][0][1]] = 1;
			map[y + dir[i][1][0]][x + dir[i][1][1]] = 1;
			res += board();
			map[y][x] = 0;
			map[y + dir[i][0][0]][x + dir[i][0][1]] = 0;
			map[y + dir[i][1][0]][x + dir[i][1][1]] = 0;
			isChanged = true;
		}
	}

	if (!isChanged) return 0;

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> H >> W;

		int blank = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				char ch;
				cin >> ch;
				// -1 : 벽, 0 : 빈공간, 1: 채워진거
				if (ch == '#') map[i][j] = -1;
				else if (ch == '.') {
					map[i][j] = 0;
					blank++;
				}
				else {
					cerr << "입력이 잘못되었습니다." << endl;
					return -1;
				}
			}
		}

		if (blank % 3 != 0) cout << 0 << endl;
		else cout << board() << endl;

	}

	return 0;
}