/* CASE1 */
class Solution {
public:
	bool isSubsequence(string s, string t) {
		if (s.size() == 0)
			return true;

		int pidx = t.find(s[0]);
		if (pidx == string::npos)
			return false;
		t[pidx] = ' ';

		for (int i = 1; i < s.size(); i++) {
			int nidx;

			while (1) {
				nidx = t.find(s[i]);
				if (nidx == string::npos)
					break;
				if (nidx > pidx)
					break;
				t[nidx] = ' ';
			}

			if (nidx == string::npos || nidx < pidx)
				return false;

			pidx = nidx;
		}

		return true;
	}
};

/* CASE2 */
class Solution {
public:
	bool isSubsequence(string s, string t) {

		for (int i = 0; i < s.size(); i++) {
			int idx = t.find(s[i]);
			if (idx == string::npos)
				return false;

			t = t.substr(idx + 1);
		}

		return true;
	}
};