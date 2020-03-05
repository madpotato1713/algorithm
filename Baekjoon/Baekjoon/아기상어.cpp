#include<iostream>
#include<queue>
#include<cstring>

using namespace std;

struct info {
	int size;
	int y;
	int x;
	int eat;
	info(int size, int y, int x, int eat) : size(size), y(y), x(x), eat(eat) {};
	info() {};
};

struct point {
	int y;
	int x;
	int dist;
	point(int y, int x, int dist) :y(y), x(x), dist(dist) {};
	point() {};
	bool operator()(point p1, point p2) {
		if (p1.dist > p2.dist) {
			return true;
		}
		else if (p1.dist == p2.dist) {
			if (p1.y > p2.y) {
				return true;
			}
			else if (p1.y == p2.y) {
				if (p1.x > p2.x) {
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
	}

};
int N;
int map[20][20];
info shark;
int dir[4][2] = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };	//상, 좌, 하, 우

int eatingTime() {
	int res = 0;
	int visited[20][20];

	while (true) {
		memset(visited, 0, sizeof(visited));

		priority_queue<point, vector<point>, point> pq;
		pq.push(point(shark.y, shark.x, 0));
		visited[shark.y][shark.x] = 1;

		int distance = 0;
		while (!pq.empty()) {
			int y = pq.top().y;
			int x = pq.top().x;
			int dist = pq.top().dist;
			pq.pop();

			//상어보다 작은 물고기가 있을 경우
			if (map[y][x] != 0 && shark.size > map[y][x]) {
				map[y][x] = 0;	//물고기 삭제
				shark.y = y; shark.x = x;	//상어 이동
				shark.eat++;	//상어 먹은 개수 count
				if (shark.size == shark.eat) {
					shark.size++;
					shark.eat = 0;
				}

				distance = dist;
				break;
			}

			for (int i = 0; i < 4; i++) {
				int dy = y + dir[i][0];
				int dx = x + dir[i][1];

				//map 내 && 방문 안함 && 상어보다 작거나 같은 사이즈
				if (dy >= 0 && dy < N && dx >= 0 && dx < N && !visited[dy][dx] && shark.size >= map[dy][dx]) {
					pq.push(point(dy, dx, dist + 1));
					visited[dy][dx] = 1;
				}
			}
		}

		if (!distance)
			break;

		res += distance;
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
				shark = info(2, y, x, 0);
			}
		}
	}

	cout << eatingTime() << endl;

	return 0;
}


/* CASE2 */
//#include<iostream>
//#include<vector>
//#include<queue>
//#include<algorithm>
//
//using namespace std;
//
//struct info {
//	int size;
//	int eatOrDist;
//	int y;
//	int x;
//	info(int size, int eatOrDist, int y, int x) : size(size), eatOrDist(eatOrDist), y(y), x(x) {};
//	info() {};
//};
//
//const int INF = 987654321;
//int N;
//int map[20][20];
//info shark;
//vector<info> fishes;
//
//bool comp(info f1, info f2) {
//	if (f1.eatOrDist > f2.eatOrDist) {
//		return true;
//	}
//	else if (f1.eatOrDist == f2.eatOrDist) {
//		if (f1.y > f2.y) {
//			return true;
//		}
//		else if (f1.y == f2.y) {
//			return f1.x > f2.x;
//		}
//		return false;
//	}
//	return false;
//}
//
//int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
//
//int calcDist(int fy, int fx) {
//	int visited[20][20] = { 0 };
//	int distance[20][20] = { 0 };
//
//	queue<pair<int, int>> q;
//	q.push(make_pair(shark.y, shark.x));
//
//	visited[shark.y][shark.x] = 1;
//
//	while (!q.empty()) {
//		int y = q.front().first;
//		int x = q.front().second;
//		q.pop();
//
//		if (fy == y && fx == x)
//			break;
//
//		for (int i = 0; i < 4; i++) {
//			int dy = y + dir[i][0];
//			int dx = x + dir[i][1];
//
//			if (dy >= 0 && dy < N && dx >= 0 && dx < N) {
//				if (!visited[dy][dx] && map[dy][dx] <= shark.size) {
//					visited[dy][dx] = 1;
//					distance[dy][dx] = distance[y][x] + 1;
//					q.push(make_pair(dy, dx));
//				}
//			}
//		}
//	}
//
//	return distance[fy][fx]? distance[fy][fx] : INF;
//}
//
//int eatingTime() {
//	int res = 0;
//	int len = fishes.size();
//
//	while (len) {
//		for (int i = 0; i < len; i++) {
//			if (fishes[i].size >= shark.size)
//				fishes[i].eatOrDist = INF;
//			else
//				fishes[i].eatOrDist = calcDist(fishes[i].y, fishes[i].x);
//		}
//		sort(fishes.begin(), fishes.end(), comp);
//		
//		if (fishes[len - 1].eatOrDist == INF)
//			break;
//		
//		shark.eatOrDist++;
//		if (shark.size == shark.eatOrDist) {
//			shark.size++;
//			shark.eatOrDist = 0;
//		}
//		shark.y = fishes[len - 1].y;
//		shark.x = fishes[len - 1].x;
//
//		res += fishes[len - 1].eatOrDist;
//		fishes[len - 1].eatOrDist = 0;
//
//		len--;
//	}
//
//
//	return res;
//}
//
//int main() {
//
//	cin >> N;
//	for (int y = 0; y < N; y++) {
//		for (int x = 0; x < N; x++) {
//			cin >> map[y][x];
//			if (map[y][x] == 9) {
//				map[y][x] = 0;
//				shark = info(2, 0, y, x);
//			}
//			else if (map[y][x] > 0 && map[y][x] < 9) {
//				fishes.push_back(info(map[y][x], 0, y, x));
//			}
//		}
//	}
//
//	cout << eatingTime() << endl;
//
//	return 0;
//}