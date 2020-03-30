/* CASE1 */
class Solution {
public:
	void reverseString(vector<char>& s) {
		reverse(s.begin(), s.end());
	}
};

/* CASE2 */
class Solution {
public:
	void reverseString(vector<char>& s) {
		for (int i = 0; i < s.size() / 2; i++) {
			char tmp;
			swap(s[i], s[s.size() - 1 - i]);
		}
	}
};

/* CASE3 */
class Solution {
public:
	void reverseString(vector<char>& s) {
		int start = 0, end = s.size() - 1;

		while (start < end) {
			swap(s[start++], s[end--]);
		}
	}
};