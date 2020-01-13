#include<iostream>
#include<cstring>

using namespace std;

const int MOD = 1000000007;
int cache[101];

int tiling(int n) {
	if (n <= 1) return 1;

	int& res = cache[n];
	if (res != -1) return res;

	return res = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int asymtiling(int n) {
	if (n % 2 == 1) {
		return (tiling(n) - tiling(n / 2) + MOD) % MOD;
	}
	else {
		return ((tiling(n) - tiling(n / 2) + MOD) % MOD - tiling(n / 2 - 1) + MOD) % MOD;
	}
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;

		cout << asymtiling(n) << endl;
	}

	return 0;
}