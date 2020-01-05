#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;
int A[100], B[100];
int cache[101][101];

int jlis(int aidx, int bidx, int num) {
	int& res = cache[aidx + 1][bidx + 1];
	if (res != -1) return res;

	res = 2;
	for (int i = aidx + 1; i < n; i++) {
		if ((aidx == -1 && bidx == -1) || num < A[i]) {
			res = max(res, jlis(i, bidx, A[i]) + 1);
		}
	}
	for (int i = bidx + 1; i < m; i++) {
		if ((aidx == -1 && bidx == -1) || num < B[i]) {
			res = max(res, jlis(aidx, i, B[i]) + 1);
		}
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> A[i];
		}
		for (int i = 0; i < m; i++) {
			cin >> B[i];
		}

		cout << jlis(-1, -1, 0) - 2 << endl;
	}

	return 0;
}