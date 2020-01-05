#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> setPartialMatch(const string& rev) {
	int m = rev.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;
	while(begin + matched < m) {
		if (rev[begin + matched] == rev[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) {
				begin++;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return pi;
}

int palindromize(const string& word, const string& rev) {

	vector<int> pi = setPartialMatch(rev);
	int m = word.size();

	int begin = 0, matched = 0;

	while (begin + matched < m) {
		if (word[begin + matched] == rev[matched]) {
			matched++;
			if (begin + matched == m) {
				break;
			}
		}
		else {
			if (matched == 0) {
				begin++;
			}
			else {
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}

	return begin + m;
}

int main() {

	int testCase;
	cin >> testCase;

	for (int tc = 0; tc < testCase; tc++) {
		string word, rev;
		cin >> word;
		rev = word;
		reverse(rev.begin(), rev.end());

		cout << palindromize(word, rev) << endl;
	}

	return 0;
}