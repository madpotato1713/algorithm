#include<iostream>
#include<cstring>

using namespace std;

const int MOD = 10000000;
int N;
int cache[101][101];

int poly(int n, int first) {
	if (n == first) return 1;

	int& res = cache[n][first];
	if (res != -1) return res;

	res = 0;
	for (int second = 1; second <= n - first; second++) {

		res += ((first + second - 1) * poly(n - first, second)) % MOD;
		res %= MOD;
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));

		cin >> N;

		int sum = 0;
		for (int i = 1; i <= N; i++) {
			sum += poly(N, i);
			sum %= MOD;
		}

		cout << sum << endl;
	}

	return 0;
}