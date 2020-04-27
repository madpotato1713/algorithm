#include<iostream>

using namespace std;

int N, M;	//가로, 세로 (4 <= N, M <= 500)
int map[500][500];

int main() {

	cin >> N >> M;

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> map[y][x];
		}
	}

	return 0;
}