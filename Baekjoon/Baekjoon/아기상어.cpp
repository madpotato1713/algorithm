#include<iostream>
#include<vector>
#include<queue>

using namespace std;

struct sharkInfo {
	int size;
	int eat;
	int y;
	int x;
	sharkInfo(int size, int eat, int y, int x) :size(size), eat(eat), y(y), x(x) {};
	sharkInfo() {};
};

struct fishInfo {
	int size;
	int dist;
	int y;
	int x;
	fishInfo(int size, int dist, int y, int x) :size(size), dist(dist), y(y), x(x) {};
	fishInfo() {};
	bool operator()(fishInfo f1, fishInfo f2) {
		if (f1.dist > f2.dist) {
			return true;
		}
		else if (f1.dist == f2.dist) {
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
};

const int INF = 987654321;
int N;
int map[20][20];
sharkInfo shark;
vector<fishInfo> fishes;
vector<int> visited;
int dir[4][2] = {	//상, 하, 좌, 우
	{-1, 0}, {1, 0}, {0, -1}, {0, 1}
};

int calcDist(int fy, int fx) {
	int check[20][20] = { 0 };
	int dist[20][20] = { 0 };
	queue<pair<int, int>> q;
	q.push(make_pair(shark.y, shark.x));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		//물고기 위치에 다다르면 중단
		if (y == fy && x == fx)
			break;

		check[y][x] = 1;	//방문 체크

		for (int i = 0; i < 4; i++) {
			int dy = y + dir[i][0];
			int dx = x + dir[i][1];

			//방문 안했고, 상어보다 큰 고기 없고, 맵 안에 있으면
			if (!check[dy][dx] && shark.size >= map[dy][dx] && dy >= 0 && dy < N && dx >= 0 && dx < N) {
				q.push(make_pair(dy, dx));
				dist[dy][dx] = dist[y][x] + 1;
			}
		}
	}

	return dist[fy][fx];
}

int eatingTime() {
	int res = 0;

	while (true) {
		priority_queue<fishInfo, vector<fishInfo>, fishInfo> pq;

		for (int i = 0; i < fishes.size(); i++) {
			if (map[fishes[i].y][fishes[i].x] && shark.size > fishes[i].size) {	//방문 안했고 사이즈 작을때만 선택
				fishes[i].dist = calcDist(fishes[i].y, fishes[i].x);
				pq.push(fishes[i]);
			}
		}

		if (pq.empty())
			break;

		shark.eat++;
		if (shark.eat == shark.size) {
			shark.size++;
			shark.eat = 0;
		}
		shark.y = pq.top().y;
		shark.x = pq.top().x;
		res += pq.top().dist;
		map[pq.top().y][pq.top().x] = 0; //먹은 고기는 0으로 처리
		pq.pop();
	}

	return res;
}

int main() {

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
			if (map[y][x] == 9) {
				map[y][x] = 0;	//상어 위치는 map에서 제외
				shark = sharkInfo(2, 0, y, x);
			}
			else if (map[y][x]) {
				fishes.push_back(fishInfo(map[y][x], 0, y, x));
			}
		}
	}

	cout << eatingTime() << endl;

	return 0;
}
