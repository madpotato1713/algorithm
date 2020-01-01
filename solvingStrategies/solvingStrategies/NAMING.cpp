#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<int> setPartialMatch(const string& word) {
	int m = word.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;

	while (begin + matched < m) {
		if (word[begin + matched] == word[matched]) {
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0) begin++;
			else {
				begin += (matched - pi[matched - 1]);
				matched = pi[matched - 1];
			}
		}
	}

	return pi;
}

vector<int> namingCnt(const string& word) {
	
	vector<int> res, pi;
	pi = setPartialMatch(word);

	int k = pi.size();

	while (k > 0) {
		res.push_back(k);
		k = pi[k - 1];
	}

	return res;
}

int main() {

	string dad, mom;
	cin >> dad >> mom;

	vector<int> res = namingCnt(dad + mom);

	for (int i = res.size() - 1; i >= 0; i--) {
		cout << res[i] << " ";
	}
	cout << endl;

	return 0;
}