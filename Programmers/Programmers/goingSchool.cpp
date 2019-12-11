#include <string>
#include <vector>
#include <cstring>

using namespace std;

int cache[101][101];
int MOD = 1000000007;

int solve(int x, int y, int m, int n, const vector<vector<int>>& puddles) {
	if (x == m && y == n) return 1;
	if (x > m || y > n) return 0;

	int& res = cache[x][y];
	if (res != -1) return res;

	res = 0;
	for (int i = 0; i < puddles.size(); i++) {
		if (puddles[i][0] == x && puddles[i][1] == y) return res;
	}

	return res = (solve(x + 1, y, m, n, puddles) + solve(x, y + 1, m, n, puddles)) % MOD;
}

int solution(int m, int n, vector<vector<int>> puddles) {
	memset(cache, -1, sizeof(cache));
	return solve(1, 1, m, n, puddles);
}