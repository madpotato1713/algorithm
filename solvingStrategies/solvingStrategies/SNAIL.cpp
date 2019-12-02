#include<iostream>
#include<cmath>

using namespace std;

long double cache[1000][1000];
int LEN, DAY;	

long double snail(int day, int len) {
	if (day >= DAY) {
		if (len >= LEN) return 1;
		else return 0;
	}

	long double& res = cache[day][len];
	if (res != -1) return res;

	double a = 0.25 * snail(day + 1, len + 1);
	double b = 0.75 * snail(day + 1, len + 2);
	return res = a + b;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				cache[i][j] = -1;
			}
		}
		cin >> LEN >> DAY;
		
		cout << fixed;
		cout.precision(10);
		cout << snail(0, 0) << endl;
	}

	return 0;
}