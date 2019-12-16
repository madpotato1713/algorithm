#include<iostream>
#include<string>

using namespace std;

int n, p, l;
char words[6] = { 'F', 'X', '+', 'Y', 'F', '-' };

string solve() {

	string res = "";

	int cnt = 0;
	while (cnt < l) {
		res += (words[(p + cnt - 1) % 6]);
		cnt++;
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> n >> p >> l;

		cout << solve() << endl;
	}
}