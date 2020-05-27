class Solution {
public:
	string licenseKeyFormatting(string S, int K) {
		string res = "", s = "";

		for (char x : S) {
			if (x != '-')
				s += x;
		}

		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '-')
				continue;

			if (s[i] >= 'a' && s[i] <= 'z') {
				res += (s[i] - 'a' + 'A');
			}
			else {
				res += s[i];
			}

			if (i == s.size() - 1)
				break;
			if (i + 1 == (s.size() % K))
				res += '-';
			else if (i + 1 > (s.size() % K) && (i + 1 - (s.size() % K)) % K == 0)
				res += '-';
		}

		return res;
	}
};