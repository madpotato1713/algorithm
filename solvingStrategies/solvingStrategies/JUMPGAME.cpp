#include<iostream>
#include<cstring>

using namespace std;

int n;
int map[100][100];
int cache[100][100];

int goal(int y, int x) {
	if (y >= n || x >= n) return 0;
	if (y == n - 1 && x == n - 1) return 1;
	
	int& res = cache[y][x];
	if (res != -1) return res;

	int len = map[y][x];
	return res = (goal(y + len, x) || goal(y, x + len));
}

int main() {
	
	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> n;
		memset(cache, -1, sizeof(cache));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}

		cout << (goal(0, 0) == 1 ? "YES" : "NO") << endl;
	}

	return 0;
}