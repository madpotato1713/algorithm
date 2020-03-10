#include<iostream>

using namespace std;

int N;
int map[20][20];

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	return 0;
}