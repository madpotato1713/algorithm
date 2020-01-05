#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int seq[500];
int cache[501];

int lis(int idx) {
	
	int& res = cache[idx + 1];
	if (res != -1) return res;

	res = 1;
	for (int i = idx + 1; i < N; i++) {
		if (idx == -1 || seq[i] > seq[idx]) {
			res = max(res, lis(i) + 1);
		}
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(cache, -1, sizeof(cache));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> seq[i];
		}

		cout << lis(-1) - 1 << endl;
	}

	return 0;
}