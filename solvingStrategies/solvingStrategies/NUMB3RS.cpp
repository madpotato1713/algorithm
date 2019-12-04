#include<iostream>
#include<cstring>

using namespace std;

int N, D, P, T;
int Map[50][50];
int Q[50];

int conNum[50];
double cache[101][50];

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 50; j++) {
			cache[i][j] = -1;
		}
	}
	return;
}

double solve(int day, int now, int dst) {
	if (day == D) return now == dst ? 1 : 0;

	double& res = cache[day][now];
	if (res != -1) return res;

	res = 0;
	for (int next = 0; next < N; next++) {
		if (Map[now][next]) {
			res += (solve(day + 1, next, dst) / conNum[now]);
		}
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(conNum, 0, sizeof(conNum));

		cin >> N >> D >> P;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> Map[i][j];
				if (Map[i][j]) conNum[i]++;
			}
		}
		cin >> T;
		for (int i = 0; i < T; i++) {
			cin >> Q[i];
		}

		for (int i = 0; i < T; i++) {
			init();
			cout << fixed;
			cout.precision(8);
			cout << solve(0, P, Q[i]) << " ";
		}
		cout << endl;
	}

	return 0;
}