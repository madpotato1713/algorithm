#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;
int cache[500][500];

int solve(int y, int x, int cnt, const vector<vector<int>>& tri, int depth) {
	int& res = cache[y][x];
	if (res != -1) return res;

	if (cnt == depth) {
		return tri[y][x];
	}

	return 0;
}

int solution(vector<vector<int>> triangle) {
	memset(cache, -1, sizeof(cache));

	return solve(0, 0, 0, triangle, triangle.size());
}