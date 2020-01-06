class Solution {
public:
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

	int strStr(string haystack, string needle) {
		int n = needle.size();
		if (n == 0) return 0;
		vector<int> pi = setPartialMatch(needle);
		int m = haystack.size();

		int begin = 0, matched = 0;

		while (begin + matched < m) {
			if (haystack[begin + matched] == needle[matched]) {
				matched++;
				if (matched == n) {
					return begin;
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
		return -1;
	}
};