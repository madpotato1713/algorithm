#include<iostream>
#include<algorithm>

using namespace std;

int N;
int map[20][20];

void moveMap(int dir) {
	//두개씩만 합쳐짐
	if (dir == 0) {
		for (int x = 0; x < N; x++) {
			for (int y = 0; y < N; y++) {

			}
		}
	}
	else if (dir == 1) {

	}
	else if (dir == 2) {

	}
	else if (dir == 3) {

	}
}

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	return 0;
}