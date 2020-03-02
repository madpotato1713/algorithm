#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

struct sharkInfo {
	int size;
	int eat;
	int y;
	int x;
	sharkInfo(int size, int eat, int y, int x) : size(size), eat(eat), y(y), x(x) {};
	sharkInfo() {};
};

struct fishInfo {
	int size;
	int dist;
	int y;
	int x;
	fishInfo(int size, int dist, int y, int x) : size(size), dist(dist), y(y), x(x) {};
	fishInfo() {};

	bool operator()(fishInfo f1, fishInfo f2) {
		return f1.size < f2.size;
	}
};

sharkInfo shark;

const int INF = 987654321;
int N;
int map[20][20];
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };	//상, 하, 좌, 우

int calcDist(int size, int sy, int sx, int fy, int fx){
	int visited[20][20] = { 0 };
	int dist[20][20] = { 0 };

	queue<pair<int, int>> q;
	q.push(make_pair(sy, sx));

	int cnt = 1;
	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();
		int y = front.first;
		int x = front.second;

		if (y == fy && x == fx)
			break;

		visited[y][x] = 1;

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[i][0];
			int dx = x + dir[i][1];

			if (!visited[dy][dx] && size >= map[dy][dx] && dy >= 0 && dy < N && dx >= 0 && dx < N) {
				q.push(make_pair(dy, dx));
				dist[dy][dx] = dist[y][x] + 1;
			}
		}
	}

	return dist[fy][fx];
}

int eatingTime() {
	priority_queue<fishInfo, vector<fishInfo>, fishInfo> pq;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			if (map[y][x]) {
				if (map[y][x] < shark.size) {
					pq.push(fishInfo(map[y][x], calcDist(shark.size, shark.y, shark.x, y, x), y, x));
				}
				else {
					pq.push(fishInfo(map[y][x], INF, y, x));
				}
			}
		}
	}

	while (!pq.empty()) {
		cout << pq.top().size << endl;
		pq.pop();
	}

	return 0;
}

int main() {

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) shark = sharkInfo(2, 0, y, x); //상어
		}
	}

	cout << eatingTime() << endl;

	return 0;
}