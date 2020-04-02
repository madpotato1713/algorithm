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
int L;	//뱀의 변환 정보
//vector<point> apples;	//사과 위치 저장
vector<point> snake;	//뱀 위치 정보 저장
//char snakedir;
queue<pair<int, char>> moveinfo;	//변환정보 저장(L, D)
int direction[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };	//상, 하, 좌, 우

int play() {
	int cnt = 0;

	while (!moveinfo.empty()) {
		pair<int, char> front = moveinfo.front();
		moveinfo.pop();

		//저장된 sec만큼 이동
		for (int i = 0; i < front.first; i++) {
			//int snakeLen = snake.size() - 1;
			//int headY = snake[0].y, headX = snake[0].x;
			//int tailY = snake[snakeLen].y, tailX = snake[snakeLen].x;

			//int nextY = headY + direction[snakedir][0], nextX = headX + direction[snakedir][1];

			//이동하는 경로에 사과(-1)가 있는 경우

			//이동하는 경우에 끝(벽 또는 자기 자신과 마주쳤을 때)

			//일반 이동
			//바로 다음 몸통의 위치정보를 이어받음

			//map[tailY][tailX] = 0;	//꼬리 위치 갱신
			//map[headY][headX] = 1;	//머리 위치 갱신
			//for (auto s : snake) {	//뱀 위치 갱신
			//	s.y += direction[snakedir][0];
			//	s.x += direction[snakedir][1];
			//}
		}

		//다음 방향 정보 변경
		/*if (snakedir == 0) {
			if (front.second == 'L') snakedir = 2;
			else if (front.second == 'D') snakedir = 3;
		}
		else if (snakedir == 1) {
			if (front.second == 'L') snakedir = 3;
			else if (front.second == 'D') snakedir = 2;
		}
		else if (snakedir == 2) {
			if (front.second == 'L') snakedir = 1;
			else if (front.second == 'D') snakedir = 0;
		}
		else if (snakedir == 3) {
			if (front.second == 'L') snakedir = 0;
			else if (front.second == 'D') snakedir = 1;
		}*/
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
	for (int i = 0; i < L; i++) {
		int sec;
		char dir;
		cin >> sec >> dir;
		moveinfo.push(make_pair(sec, dir));
	}
	//뱀의 초기 위치와 방향 저장 : (1, 1)부터 시작, 처음에 오른쪽을 향함
	snake.push_back(point(1, 1, 3));
	map[1][1] = 1;	//뱀의 초기 위치 표시
	//snakedir = 3;	//뱀의 초기 방향은 오른쪽

	cout << play() << endl;

	return 0;
}