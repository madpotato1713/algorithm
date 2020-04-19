#include<iostream>
#include<vector>

using namespace std;

struct DICE {
	int x;
	int y;
	int up;		//북
	int down;	//남
	int left;	//서
	int right;	//동
	int front;	//윗면
	int bottom;	//바닥
	DICE() {};
	DICE(int x, int y)	//주사위는 처음에 모든 면이 0이다.
		:x(x), y(y), up(0), down(0), left(0), right(0), front(0), bottom(0) {};
};

int N, M;	//지도의 세로, 가로크기(1<=N, M<=20)
int x, y;	//주사위의 좌표(0<=x<=N-1, 0<=y<=M-1)
int K; //명령의 개수
int map[20][20];	//지도
vector<int> moving;	//이동명령
DICE dice;	//주사위
int direction[4][2] = { {0, 1}, {0, -1}, {-1, 0}, {1, 0} };

int moveDice(int dir) {	//1, 2, 3, 4 : 동, 서, 북, 남

	//주사위 좌표 이동
	int nx = dice.x, ny = dice.y;
	nx += direction[dir - 1][0]; ny += direction[dir - 1][1];
	//바깥으로 이동시 종료
	if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
		return -1;
	}
	dice.x = nx; dice.y = ny;	//좌표이동

	int up = dice.up;
	int down = dice.down;
	int front = dice.front;
	int right = dice.right;
	int bottom = dice.bottom;
	int left = dice.left;

	switch (dir)
	{
	case 1:	//동(up->up, down->down, front->right, right->bottom, bottom->left, left->front)
		dice.right = front;
		dice.left = bottom;
		dice.front = left;
		if (map[nx][ny] == 0) {	//주사위 바닥면이 0일 경우
			dice.bottom = right;
			map[nx][ny] = right;
		}
		else {	//주사위 바닥면이 숫자일 경우
			dice.bottom = map[nx][ny];
			map[nx][ny] = 0;
		}
		break;
	case 2:	//서(up->up, down->down, front->left, left->bottom, bottom->right, right->front)
		dice.left = front;
		dice.right = bottom;
		dice.front = right;
		if (map[nx][ny] == 0) {	//주사위 바닥면이 0일 경우
			dice.bottom = left;
			map[nx][ny] = left;
		}
		else {	//주사위 바닥면이 숫자일 경우
			dice.bottom = map[nx][ny];
			map[nx][ny] = 0;
		}
		break;
	case 3:	//북(up->bottom, bottom->down, down->front, front->up, left->left, right->right)
		dice.down = bottom;
		dice.front = down;
		dice.up = front;
		if (map[nx][ny] == 0) {	//주사위 바닥면이 0일 경우
			dice.bottom = up;
			map[nx][ny] = up;
		}
		else {	//주사위 바닥면이 숫자일 경우
			dice.bottom = map[nx][ny];
			map[nx][ny] = 0;
		}
		break;
	case 4:	//남(up->front, front->down, down->bottom, bottom->up, left->left, right->right)
		dice.front = up;
		dice.down = front;
		dice.up = bottom;
		if (map[nx][ny] == 0) {	//주사위 바닥면이 0일 경우
			dice.bottom = down;
			map[nx][ny] = down;
		}
		else {	//주사위 바닥면이 숫자일 경우
			dice.bottom = map[nx][ny];
			map[nx][ny] = 0;
		}
		break;
	default:
		break;
	}

	return dice.front;
}

int main() {
	
	cin >> N >> M >> x >> y >> K;
	//주사위
	dice = DICE(x, y);

	//지도에 쓰여있는 수
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
	//이동하는 명령(1, 2, 3, 4 : 동, 서, 남, 북)
	moving = vector<int>(K, 0);
	for (int i = 0; i < K; i++) {
		cin >> moving[i];
	}

	for (auto m : moving) {
		int res = moveDice(m);
		if(res >= 0)
			cout << res << endl;
	}

	return 0;
}