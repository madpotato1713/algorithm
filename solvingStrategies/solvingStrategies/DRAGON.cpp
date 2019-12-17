#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int n, p, l;

int cache[51];
int MAX = 1000000001;

void calc() {
	cache[0] = 1;
	for (int i = 1; i <= 50; i++) {
		cache[i] = min(MAX, cache[i - 1] * 2 + 2);
	}
}

//X -> X + YF
//Y -> FX - Y
char solve(const string& str, int gen, int skip) {
	if (gen == 0) {
		return str[skip];
	}

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'X' || str[i] == 'Y') {
			if (skip >= cache[gen]) {
				skip -= cache[gen];
			}
			else if (str[i] == 'X') {
				return solve("X+YF", gen - 1, skip);
			}
			else {
				return solve("FX-Y", gen - 1, skip);
			}
		}
		else if (skip > 0)
			skip--;
		else
			return str[i];
	}

	return ' ';
}

int main() {

	int testCase;
	cin >> testCase;
	calc();

	for (int tc = 0; tc < testCase; tc++) {
		cin >> n >> p >> l;

		for (int i = 0; i < l; i++) {
			cout << solve("FX", n, p - 1 + i);
		}

		cout << endl;
	}
}