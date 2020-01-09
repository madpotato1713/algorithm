#include<iostream>

using namespace std;

double cache[1001][1001];

double snail(int n, int m) {
	if (n <= 0) return 1;
	if (m <= 0) return 0;

	double& res = cache[n][m];
	if (res != -1) return res;

	res = 0.75 * snail(n - 2, m - 1) + 0.25 * snail(n - 1, m - 1);

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		int n, m;
		cin >> n >> m;

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cache[i][j] = -1;
			}
		}

		cout << fixed;
		cout.precision(10);
		cout << snail(n, m) << endl;
	}

	return 0;
}