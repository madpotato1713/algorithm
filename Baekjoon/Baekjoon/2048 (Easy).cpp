#include<iostream>
#include<algorithm>

using namespace std;

int N;
int map[20][20];

int findMax() {
	int res = 0;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			res = max(res, map[y][x]);
		}
	}
	return res;
}

void moveMap(int dir) {
	switch (dir)
	{
	case 0:

		break;
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	default:
		break;
	}
}

int move(int cnt) {
	if (cnt == 5) {
		return findMax();
	}

	int res = findMax();
	for (int i = 0; i < 4; i++) {
		//¸Ê º¹»ç
		int copyMap[20][20];
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				copyMap[y][x] = map[y][x];
			}
		}

		//¸Ê ¿òÁ÷ÀÌ´Â ·ÎÁ÷


		res = max(res, move(cnt + 1));

		//¸Ê ¿øº¹ ·ÎÁ÷
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				map[y][x] = copyMap[y][x];
			}
		}
	}

	return res;
}

int main() {
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	return 0;
}