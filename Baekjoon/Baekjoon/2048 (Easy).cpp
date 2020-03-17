#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int map[20][20];

void moveMap(int dir) {
	//두개씩만 합쳐짐

	//상
	if (dir == 0) {
		for (int x = 0; x < N; x++) {
			vector<int> v;
			for (int y = 0; y < N - 1; y++) {
				if (map[y][x] != 0) {
					v.push_back(map[y][x]);
					if (map[y][x] == map[y + 1][x]) {
						v[v.size() - 1] *= 2;
						y++;
						map[y + 1][x] = 0;
					}
					map[y][x] = 0;
				}
			}
			if (map[N - 1][x] != 0)
				v.push_back(map[N - 1][x]);
			for (int y = 0; y < v.size(); y++) {
				map[y][x] = v[y];
			}
		}
	}
	//하
	else if (dir == 1) {

	}
	//좌
	else if (dir == 2) {

	}
	//우
	else if (dir == 3) {

	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	return 0;
}