#include<iostream>
#include<cstring>

using namespace std;

int N, D, P, T;
int Map[50][50];
int Q[50];
int conNum[50];
double cache[50][101];

void init() {
	for (int i = 0; i < 50; i++) {
		for (int j = 0; j < 101; j++) {
			cache[i][j] = -1;
		}
	}
}

double solve(int day, int town, int dst) {
	if (day == D) return (town == dst ? 1 : 0);

	double& res = cache[town][day];
	if (res != -1) return res;

	res = 0;
	for (int next = 0; next < N; next++) {
		if (Map[town][next]) {
			res += (solve(day + 1, next, dst) / conNum[town]);
		}
	}

	return res;
}

double solve2(int day, int town) {
	if (day == 0) return (town == P ? 1 : 0);

	double& res = cache[town][day];
	if (res != -1) return res;

	res = 0;
	for (int pre = 0; pre < N; pre++) {
		if (Map[town][pre]) {
			res += (solve2(day - 1, pre) / conNum[pre]);
		}
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		memset(conNum, 0, sizeof(conNum));

		//입력부 시작
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
		//입력부 끝

		/*for (int i = 0; i < T; i++) {
			init();
			cout << fixed;
			cout.precision(8);
			cout << solve(0, P, Q[i]) << " ";
		}
		cout << endl;*/

		for (int i = 0; i < T; i++) {
			init();
			cout << fixed;
			cout.precision(8);
			cout << solve2(D, Q[i]) << " ";
		}
		cout << endl;
	}

	return 0;
}