#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int map[100][100];
int cache[100][100];
int cache2[100][100];

int triPath(int y, int x) {
	int& res = cache[y][x];
	if (res != -1) return res;

	if (y == N - 1) {
		return res = map[y][x];
	}

	res = max(map[y][x] + triPath(y + 1, x), map[y][x] + triPath(y + 1, x + 1));

	return res;
}

int triPathCnt(int y, int x) {
	int& res = cache2[y][x];
	if (res != -1) return res;

	if (y == N - 1) {
		return 1;
	}

	int pre = cache[y + 1][x];
	int next = cache[y + 1][x + 1];
	int n1 = triPathCnt(y + 1, x);
	int n2 = triPathCnt(y + 1, x + 1);
	if (pre == next) {
		res = n1 + n2;
	}
	else if (pre > next) {
		res = n1;
	}
	else {
		res = n2;
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));
		
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> map[i][j];
			}
		}

		triPath(0, 0);
		cout << triPathCnt(0, 0) << endl;
	}

	return 0;
}