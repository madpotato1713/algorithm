#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int N;
int res = 0;

vector<vector<int>> moveMap(int dir, vector<vector<int>> map) {
	//두개씩만 합쳐짐

	//상
	if (dir == 0) {
		for (int x = 0; x < N; x++) {
			vector<int> v;
			for (int y = 0; y < N - 1; y++) {
				if (map[y][x] != 0) {
					v.push_back(map[y][x]);
					/* 여기가 아주 잘못됨.. */
					/* 반드시 두 칸이 붙어있다는 보장이 없음....*/
					if (map[y][x] == map[y + 1][x]) {
						v[v.size() - 1] *= 2;
						map[y][x] = 0;
						y++;
					}
					map[y][x] = 0;
				}
			}
			if (map[N - 1][x] != 0) {
				v.push_back(map[N - 1][x]);
				map[N - 1][x] = 0;
			}
			for (int y = 0; y < v.size(); y++) {
				map[y][x] = v[y];
			}
		}
	}
	//하
	else if (dir == 1) {
		for (int x = 0; x < N; x++) {
			vector<int> v;
			for (int y = N - 1; y > 0; y--) {
				if (map[y][x] != 0) {
					v.push_back(map[y][x]);
					if (map[y][x] == map[y - 1][x]) {
						v[v.size() - 1] *= 2;
						map[y][x] = 0;
						y--;
					}
					map[y][x] = 0;
				}
			}
			if (map[0][x] != 0) {
				v.push_back(map[0][x]);
				map[0][x] = 0;
			}
			for (int y = 0; y < v.size(); y++) {
				map[N - 1 - y][x] = v[y];
			}
		}
	}
	//좌
	else if (dir == 2) {
		for (int y = 0; y < N; y++) {
			vector<int> v;
			for (int x = 0; x < N - 1; x++) {
				if (map[y][x] != 0) {
					v.push_back(map[y][x]);
					if (map[y][x] == map[y][x + 1]) {
						v[v.size() - 1] *= 2;
						map[y][x] = 0;
						x++;
					}
					map[y][x] = 0;
				}
			}
			if (map[y][N - 1] != 0) {
				v.push_back(map[y][N - 1]);
				map[y][N - 1] = 0;
			}
			for (int x = 0; x < v.size(); x++) {
				map[y][x] = v[x];
			}
		}
	}
	//우
	else if (dir == 3) {
		for (int y = 0; y < N; y++) {
			vector<int> v;
			for (int x = N - 1; x > 0; x--) {
				if (map[y][x] != 0) {
					v.push_back(map[y][x]);
					if (map[y][x] == map[y][x - 1]) {
						v[v.size() - 1] *= 2;
						map[y][x] = 0;
						x--;
					}
					map[y][x] = 0;
				}
			}
			if (map[y][0] != 0) {
				v.push_back(map[y][0]);
				map[y][0] = 0;
			}
			for (int x = 0; x < v.size(); x++) {
				map[y][N - 1 - x] = v[x];
			}
		}
	}

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cout << map[y][x] << " ";
		}
		cout << endl;
	}
	cout << endl;

	return map;
}

void maxNum(int cnt, vector<vector<int>> map) {
	if (cnt == 5) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				res = max(res, map[y][x]);
			}
		}
		return;
	}

	for (int i = 0; i < 4; i++) {
		maxNum(cnt + 1, moveMap(i, map));
	}
}

int main() {

	cin >> N;
	vector<vector<int>> map(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	maxNum(0, map);
	cout << res << endl;

	return 0;
}