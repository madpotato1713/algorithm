#include<iostream>
#include<cstring>

using namespace std;

int N;
int cache[100];
int cache2[50];
int mod = 1000000007;

int tilingCnt(int idx) {
	if (idx >= N) {
		if (idx == N) return 1;
		else return 0;
	}

	int& res = cache[idx];
	if (res != -1) return res;

	return res = (tilingCnt(idx + 1) % mod + tilingCnt(idx + 2) % mod) % mod;
}

int halfTlingCnt(int idx) {
	if (idx >= N / 2) return 1;

	int& res2 = cache2[idx];
	if (res2 != -1) return res2;

	return res2 = (halfTlingCnt(idx + 1) % mod + halfTlingCnt(idx + 2) % mod) % mod;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));
		memset(cache2, -1, sizeof(cache2));

		cin >> N;

		int a = tilingCnt(0);
		int b = halfTlingCnt(0);
		cout << (a - b >= 0 ? a - b : a - b + mod) << endl;
	}

	return 0;
}


//서적 풀이
//#include<iostream>
//#include<cstring>
//
//using namespace std;
//
//int N;
//int cache[101];
//int mod = 1000000007;
//
//int tilingCnt(int width) {
//	if (width <= 1) return 1;
//
//	int& res = cache[width];
//	if (res != -1) return res;
//
//	return res = (tilingCnt(width - 2) + tilingCnt(width - 1)) % mod;
//}
//
//int halfTlingCnt(int width) {
//	if (width % 2 == 1)
//		return (tilingCnt(width) - tilingCnt(width / 2) + mod) % mod;
//	int res = tilingCnt(width);
//	res = (res - tilingCnt(width / 2) + mod) % mod;
//	res = (res - tilingCnt(width / 2 - 1) + mod) % mod;
//
//	return res;
//}
//
//int main() {
//
//	int testCase;
//	cin >> testCase;
//
//	for (int tc = 0; tc < testCase; tc++) {
//		memset(cache, -1, sizeof(cache));
//
//		cin >> N;
//
//		cout << halfTlingCnt(N) << endl;
//	}
//
//	return 0;
//}