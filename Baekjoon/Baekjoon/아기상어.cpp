#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct info {
	int size;
	int eatOrDist;
	int y;
	int x;
	info(int size, int eatOrDist, int y, int x) : size(size), eatOrDist(eatOrDist), y(y), x(x) {};
	info() {};
};

const int INF = 987654321;
int N;
int map[20][20];
info shark;
vector<info> fishes;

bool comp(info f1, info f2) {
	if (f1.eatOrDist > f2.eatOrDist) {
		return true;
	}
	else if (f1.eatOrDist == f2.eatOrDist) {
		if (f1.y > f2.y) {
			return true;
		}
		else if (f1.y == f2.y) {
			return f1.x > f2.x;
		}
		return false;
	}
	return false;
}

int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

int calcDist(int fy, int fx) {
	int visited[20][20] = { 0 };
	int distance[20][20] = { 0 };

	queue<pair<int, int>> q;
	q.push(make_pair(shark.y, shark.x));

	visited[shark.y][shark.x] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (fy == y && fx == x)
			break;

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[i][0];
			int dx = x + dir[i][1];

			if (dy >= 0 && dy < N && dx >= 0 && dx < N) {
				if (!visited[dy][dx] && map[dy][dx] <= shark.size) {
					visited[dy][dx] = 1;
					distance[dy][dx] = distance[y][x] + 1;
					q.push(make_pair(dy, dx));
				}
			}
		}
	}

	return distance[fy][fx]? distance[fy][fx] : INF;
}

int eatingTime() {
	int res = 0;
	int len = fishes.size();

	while (len) {
		for (int i = 0; i < len; i++) {
			if (fishes[i].size >= shark.size)
				fishes[i].eatOrDist = INF;
			else
				fishes[i].eatOrDist = calcDist(fishes[i].y, fishes[i].x);
		}
		sort(fishes.begin(), fishes.end(), comp);
		
		if (fishes[len - 1].eatOrDist == INF)
			break;
		
		shark.eatOrDist++;
		if (shark.size == shark.eatOrDist) {
			shark.size++;
			shark.eatOrDist = 0;
		}
		shark.y = fishes[len - 1].y;
		shark.x = fishes[len - 1].x;

		res += fishes[len - 1].eatOrDist;
		fishes[len - 1].eatOrDist = 0;

		len--;
	}


	return res;
}

int main() {

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				map[y][x] = 0;
				shark = info(2, 0, y, x);
			}
			else if (map[y][x] > 0 && map[y][x] < 9) {
				fishes.push_back(info(map[y][x], 0, y, x));
			}
		}
	}

	cout << eatingTime() << endl;

	return 0;
}