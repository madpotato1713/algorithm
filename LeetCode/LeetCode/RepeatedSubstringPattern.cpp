/* CASE1 */
class Solution {
public:
	bool repeatedSubstringPattern(string s) {
		int len = s.size();
		if (len <= 1) return false;

		int idx = len / 2;
		string sub = "";

		while (idx > 0) {
			sub = s.substr(0, idx);

			bool flag = true;
			for (int i = idx; i < len; i += idx) {
				if (sub != s.substr(i, idx)) {
					flag = false;
					break;
				}
			}

			if (flag) {
				return true;
			}
			else {
				idx--;
			}
		}


		return false;
	}
};

