#include<iostream>
#include<vector>
#include<cstring>
#include<queue>

using namespace std;

const int MAXIMUM = 101;
struct point {
	int y;
	int x;
	int dir;	//상, 하, 좌, 우 : 해당 몸통의 앞으로 이동 방향
	point() {};
	point(int y, int x) :y(y), x(x) {};
	point(int y, int x, int dir) :y(y), x(x), dir(dir) {};
};

int map[MAXIMUM][MAXIMUM];
int N;	//보드의 크기
int K;	//사과의 개수
int L;	//위치 변환 정보
//vector<point> apples;	//사과 위치 저장
vector<point> snake;	//뱀 위치 정보 저장
//char snakedir;
queue<pair<int, char>> moveinfo;	//변환정보 저장(L, D)
int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };	//상, 하, 좌, 우

int dirInfo(int snakedir, char lr) {
	//다음 방향 정보 변경
	if (snakedir == 0) {
		if (lr == 'L') snakedir = 2;
		else if (lr == 'D') snakedir = 3;
	}
	else if (snakedir == 1) {
		if (lr == 'L') snakedir = 3;
		else if (lr == 'D') snakedir = 2;
	}
	else if (snakedir == 2) {
		if (lr == 'L') snakedir = 1;
		else if (lr == 'D') snakedir = 0;
	}
	else if (snakedir == 3) {
		if (lr == 'L') snakedir = 0;
		else if (lr == 'D') snakedir = 1;
	}

	return snakedir;
}

int play() {
	int cnt = 0;

	pair<int, char> front;
	while (1) {
		//이동 정보가 없을 때는 마지막 정보로 계속이동
		if (!moveinfo.empty()) {
			front = moveinfo.front();
			moveinfo.pop();
		}
		else {
			front.second = ' ';
		}

		//저장된 sec만큼 이동
		for (int i = 0; i < front.first; i++) {
			cnt++;
			int nextDir = snake[snake.size() - 1].dir;
			for (int s = snake.size() - 1; s >= 0; s--) {
				int nextY = snake[s].y + direction[snake[s].dir][0];
				int nextX = snake[s].x + direction[snake[s].dir][1];

				//벽에 부딪히는 경우(끝) 수정 필요(맨 머리만 검사하면 될 것 같다)
				if (nextY < 1 || nextY > N || nextX < 1 || nextX > N) {
					return cnt;
				}

				//자기 자신한테 부딪히는 경우(끝): 머리만 해당
				if (s == snake.size() - 1) {
					for (int x = snake.size() - 2; x >= 0; x--) {
						if (nextY == snake[x].y && nextX == snake[x].x) {
							return cnt;
						}
					}
				}

				//사과 있는 경우
				if (map[nextY][nextX] == -1) {
					snake.push_back(point(nextY, nextX, snake[s].dir));
					map[nextY][nextX] = 0;
					break;
				}
				//사과 없는 경우
				else {
					snake[s].y = nextY;
					snake[s].x = nextX;
				}
				int tmpDir = snake[s].dir;
				snake[s].dir = nextDir;
				nextDir = tmpDir;
			}
		}

		////자기 자신한테 부딪히는 경우(끝)
		//for (int s = snake.size() - 2; s >= 0; s--) {
		//	if (snake[snake.size() - 1].y == snake[s].y && snake[snake.size() - 1].x == snake[s].x) {
		//		return cnt;
		//	}
		//}

		//다음 위치정보로 변경
		if (front.second != ' ') {
			snake[snake.size() - 1].dir = dirInfo(snake[snake.size() - 1].dir, front.second);
		}
	}

	return cnt;
}

int main() {
	memset(map, 0, sizeof(map));	//맵 초기화

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int y, x;
		cin >> y >> x;
		//apples.push_back(point(y, x));
		map[y][x] = -1;	//-1: 사과의 위치
	}
	cin >> L;

	int acc = 0;
	for (int i = 0; i < L; i++) {
		int sec;
		char dir;
		cin >> sec >> dir;
		moveinfo.push(make_pair(sec - acc, dir));
		acc = sec;
	}
	//뱀의 초기 위치와 방향 저장 : (1, 1)부터 시작, 처음에 오른쪽을 향함
	snake.push_back(point(1, 1, 3));
	//map[1][1] = 1;	//뱀의 초기 위치 표시
	//snakedir = 3;	//뱀의 초기 방향은 오른쪽

	cout << play() << endl;

	return 0;
}