#include<iostream>
#include<cstring>

using namespace std;

const int d = 1000000007;
int map[101];

int n;

int solve(int x) {
	int& res = map[x];
	if (res != -1) return res;

	if (x == 1) return res = 1;
	if (x == 2) return res = 2;

	res = ((solve(x - 1) % d) + (solve(x - 2) % d)) % d;
	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(map, -1, sizeof(map));
		cin >> n;

		cout << solve(n) << endl;
	}

	return 0;
}