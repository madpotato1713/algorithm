#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n;
int tri[100][100];
int cache[100][100];

int biggestSum(int y, int x) {
	//기저 : 삼각형 끝에 다다랐을 때
	if (y == n - 1) return tri[y][x];

	int& res = cache[y][x];
	if (res != -1) return res;

	res = tri[y][x] + max(biggestSum(y + 1, x), biggestSum(y + 1, x + 1));

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j <= i; j++) {
				cin >> tri[i][j];
			}
		}

		cout << biggestSum(0, 0) << endl;
	}

	return 0;
}