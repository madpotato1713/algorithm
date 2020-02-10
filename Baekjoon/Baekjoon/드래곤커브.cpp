#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>

using namespace std;

int map[101][101];
int direction[4][2] = { {0, 1}, {-1, 0}, {0, -1}, {1, 0} };	//우, 상, 좌, 하
vector<int> path;
int yMax, xMax;

void setPath(int d, int g) {
	path.push_back(d);

	while (g > 0) {
		for (int i = path.size() - 1; i >= 0; i--) {
			path.push_back((path[i] + 1) % 4);
		}

		g--;
	}
}

void drawMap(int y, int x) {
	yMax = max(yMax, y);
	xMax = max(xMax, x);
	map[y][x]++;

	for (int i = 0; i < path.size(); i++) {
		y += direction[path[i]][0];
		x += direction[path[i]][1];

		if (y >= 0 && y < 101 && x >= 0 && x < 101)
		{
			map[y][x]++;
			yMax = max(yMax, y);
			xMax = max(xMax, x);
		}
	}
}

int countSquare() {
	int res = 0;

	for (int y = 0; y < yMax; y++) {
		for (int x = 0; x < xMax; x++) {
			if (map[y][x] && map[y][x + 1] && map[y + 1][x] && map[y + 1][x + 1]) {
				res++;
			}
		}
	}

	return res;
}

int main() {

	int N;
	cin >> N;
	memset(map, 0, sizeof(map));
	yMax = xMax = 0;

	for (int i = 0; i < N; i++) {
		int x, y, d, g;	//x, y: 시작 좌표, d: 시작 방향, g: 세대
		cin >> x >> y >> d >> g;
		
		path.clear();

		setPath(d, g);
		drawMap(y, x);
	}
	cout << countSquare() << endl;

	return 0;
}