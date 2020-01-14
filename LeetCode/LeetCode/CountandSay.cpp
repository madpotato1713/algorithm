class Solution {
public:
	string countAndSay(int n) {
		return solve("1", n);
	}

	string solve(const string& str, int n) {
		if (n == 1) return str;

		char ch = ' ';
		int cnt = 0;
		string res;

		for (int i = 0; i < str.size(); i++) {
			if (ch == ' ' || ch == str[i]) {
				cnt++;
			}
			else {
				res += (to_string(cnt) + str[i - 1]);
				cnt = 1;
			}
			ch = str[i];

			if (i == str.size() - 1) {
				res += (to_string(cnt) + ch);
			}
		}

		return solve(res, n - 1);
	}
};