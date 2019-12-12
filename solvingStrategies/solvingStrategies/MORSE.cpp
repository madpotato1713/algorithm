#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int skip;
const int M = 1000000000;
int bino[201][201];

void calcBino() {
	for (int i = 0; i <= 200; i++) {
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++) {
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
		}
	}
}
void solve(int n, int m, string s) {
	if (skip < 0) return;

	if (n == 0 && m == 0) {
		if (skip == 0) cout << s << endl;
		skip--;
		return;
	}

	if (bino[n + m][n] <= skip) {
		skip -= bino[n + m][n];
		return;
	}

	if (n > 0) solve(n - 1, m, s + "-");
	if (m > 0) solve(n, m - 1, s + "o");

}

int main() {

	int testCase;
	cin >> testCase;

	calcBino();
	for (int tc = 0; tc < testCase; tc++) {
		int n, m, k;
		cin >> n >> m >> k;
		skip = k - 1;

		solve(n, m, "");
	}
}