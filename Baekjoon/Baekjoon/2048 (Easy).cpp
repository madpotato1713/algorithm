#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int N;
int map[20][20];
int res = 0;

void moveMap(int dir) {
	queue<int> q;

	if (dir == 0) {	//상
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {
				if (map[y][x]) {
					q.push(map[y][x]);
					map[y][x] = 0;
				}
			}

			int y = 0, i = 0;
			while (!q.empty()) {
				int front = q.front();
				q.pop();

				if (i % 2 == 0) {	//처음 넣을 때
					map[y][x] = front;
					i = 1;
				}
				else {	//두번째 넣을 때
					if (map[y][x] == front) {	//첫번째하고 같은 경우
						map[y][x] *= 2;
						y++;	//다음 인덱스
						i = 0;	//처음 넣을 차례로 돌아감
					}
					else {	//첫번째하고 다른 경우
						map[++y][x] = front;
						i = 1;
					}
				}
			}
		}
	}
	else if (dir == 1) {	//하
		for (int x = 0; x < N; x++) {
			for (int y = N - 1; y >= 0; y--) {
				if (map[y][x]) {
					q.push(map[y][x]);
					map[y][x] = 0;
				}
			}

			int y = N - 1, i = 0;
			while (!q.empty()) {
				int front = q.front();
				q.pop();

				if (i % 2 == 0) {	//처음 넣을 때
					map[y][x] = front;
					i = 1;
				}
				else {	//두번째 넣을 때
					if (map[y][x] == front) {	//첫번째하고 같은 경우
						map[y][x] *= 2;
						y--;	//다음 인덱스
						i = 0;	//처음 넣을 차례로 돌아감
					}
					else {	//첫번째하고 다른 경우
						map[--y][x] = front;
						i = 1;
					}
				}
			}
		}
	}
	else if (dir == 2) {	//좌
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (map[y][x]) {
					q.push(map[y][x]);
					map[y][x] = 0;
				}
			}

			int x = 0, i = 0;
			while (!q.empty()) {
				int front = q.front();
				q.pop();

				if (i % 2 == 0) {	//처음 넣을 때
					map[y][x] = front;
					i = 1;
				}
				else {	//두번째 넣을 때
					if (map[y][x] == front) {	//첫번째하고 같은 경우
						map[y][x] *= 2;
						x++;	//다음 인덱스
						i = 0;	//처음 넣을 차례로 돌아감
					}
					else {	//첫번째하고 다른 경우
						map[y][++x] = front;
						i = 1;
					}
				}
			}
		}
	}
	else {	//우
		for (int y = 0; y < N; y++) {
			for (int x = N - 1; x >= 0; x--) {
				if (map[y][x]) {
					q.push(map[y][x]);
					map[y][x] = 0;
				}
			}

			int x = N - 1, i = 0;
			while (!q.empty()) {
				int front = q.front();
				q.pop();

				if (i % 2 == 0) {	//처음 넣을 때
					map[y][x] = front;
					i = 1;
				}
				else {	//두번째 넣을 때
					if (map[y][x] == front) {	//첫번째하고 같은 경우
						map[y][x] *= 2;
						x--;	//다음 인덱스
						i = 0;	//처음 넣을 차례로 돌아감
					}
					else {	//첫번째하고 다른 경우
						map[y][--x] = front;
						i = 1;
					}
				}
			}
		}
	}
}

void solve(int cnt) {
	if (cnt == 5) {	//5번 이동하면 끝
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				res = max(res, map[y][x]);
			}
		}
		return;
	}

	//현 보드상태 저장
	int copy[20][20];
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			copy[y][x] = map[y][x];
		}
	}

	for (int i = 0; i < 4; i++) {

		moveMap(i);
		solve(cnt + 1);

		//현 보드상태 복원
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				map[y][x] = copy[y][x];
			}
		}
	}
}

int main() {

	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> map[y][x];
		}
	}

	solve(0);
	cout << res << endl;

	return 0;
}