#include<iostream>
#include<list>

using namespace std;

int N, K;

void solve() {
	
	list<int> mem;
	for (int i = 1; i <= N; i++) {
		mem.push_back(i);
	}
	list<int>::iterator itr = mem.begin();

	while (N > 2) {
		itr = mem.erase(itr);
		N--;
		if (itr == mem.end()) {
			itr = mem.begin();
		}

		for (int i = 1; i < K; i++) {
			itr++;
			if (itr == mem.end()) {
				itr = mem.begin();
			}
		}
	}

	for (auto x : mem) {
		cout << x << " ";
	}
	cout << endl;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> N >> K;

		solve();
	}

	return 0;
}