#include<iostream>
#include<vector>

using namespace std;

int R, C, T;
int map[50][50];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };	//상, 하, 좌, 우
vector<int> air;

//먼지의 순환
void spreadDust() {
	int spread[50][50] = { 0 };

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			//먼지가 있는 지점
			if (map[r][c] > 0) {
				int transDust = map[r][c] / 5;
				//네 방향으로 확산
				for (int i = 0; i < 4; i++) {
					int dr = r + dir[i][0];
					int dc = c + dir[i][1];
					//공기청정기가 없거나 맵 안에 있는 경우만
					if (dr >= 0 && dr < R && dc >= 0 && dc < C && map[dr][dc] != -1) {
						spread[dr][dc] += transDust;
						spread[r][c] -= transDust;
						//map[dr][dc] += transDust;
						//map[r][c] -= transDust;
					}
				}
			}
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			map[r][c] += spread[r][c];
		}
	}
}

//공기 청정
void circling() {
	int ar;
	vector<pair<int, int>> pts;

	//상
	ar = air[0];
	for (int r = ar - 1; r >= 0; r--) {
		pts.push_back(make_pair(r, 0));
	}
	for (int c = 0; c < C; c++) {
		pts.push_back(make_pair(0, c));
	}
	for (int r = 0; r <= ar; r++) {
		pts.push_back(make_pair(r, C - 1));
	}
	for (int c = C - 1; c > 0; c--) {
		pts.push_back(make_pair(ar, c));
	}

	for (int i = 0; i < pts.size() - 1; i++) {
		map[pts[i].first][pts[i].second] = map[pts[i + 1].first][pts[i + 1].second];
	}
	map[pts[pts.size() - 1].first][pts[pts.size() - 1].second] = 0;
	pts.clear();

	//하
	ar = air[1];
	for (int r = ar + 1; r < R; r++) {
		pts.push_back(make_pair(r, 0));
	}
	for (int c = 0; c < C; c++) {
		pts.push_back(make_pair(R - 1, c));
	}
	for (int r = R - 1; r >= ar; r--) {
		pts.push_back(make_pair(r, C - 1));
	}
	for (int c = C - 1; c >= 1; c--) {
		pts.push_back(make_pair(ar, c));
	}
	for (int i = 0; i < pts.size() - 1; i++) {
		map[pts[i].first][pts[i].second] = map[pts[i + 1].first][pts[i + 1].second];
	}
	map[pts[pts.size() - 1].first][pts[pts.size() - 1].second] = 0;
}

int resDust() {
	for (int i = 0; i < T; i++) {
		spreadDust();	//먼지의 순환
		circling();	//공기 청정
	}

	int res = 0;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (map[r][c] > 0)
				res += map[r][c];
		}
	}

	return res;
}

int main() {

	cin >> R >> C >> T;
	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			cin >> map[r][c];
			if (map[r][c] == -1)
				air.push_back(r);
		}
	}

	cout << resDust() << endl;

	return 0;
}