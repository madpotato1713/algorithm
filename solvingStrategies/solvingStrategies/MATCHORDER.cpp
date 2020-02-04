#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int N;
vector<int> korean, russian;

int matchOrder() {
	sort(korean.begin(), korean.end());

	int res = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (korean[j] >= russian[i]) {
				res++;
				korean[j] = 0;
				break;
			}
		}
	}

	return res;
}

int matchOrder2() {
	multiset<int> ratings(korean.begin(), korean.end());
	int res = 0;

	for (int i = 0; i < N; i++) {
		if (*ratings.rbegin() < russian[i]) {
			ratings.erase(ratings.begin());
		}
		else {
			ratings.erase(ratings.lower_bound(russian[i]));
			res++;
		}
	}

	return res;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		cin >> N;
		
		//init
		korean = russian = vector<int>(N);

		for (int i = 0; i < N; i++) {
			cin >> russian[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> korean[i];
		}

		//cout << matchOrder() << endl;
		cout << matchOrder2() << endl;
	}

	return 0;
}