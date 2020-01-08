#include<iostream>
#include<cstring>

using namespace std;

const int MOD = 1000000007;
int n;
int cache[100];

int tiling(int idx) {
	//기저사례: 사각형 끝에 닿았을 때 성공
	if (idx >= n - 1) return 1;

	int& res = cache[idx];
	if (res != -1) return res;

	res = 0;
	for (int i = 1; i <= 2; i++) {
		res += tiling(idx + i);
		res %= MOD;
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));
		cin >> n;

		cout << tiling(0) << endl;
	}

	return 0;
}