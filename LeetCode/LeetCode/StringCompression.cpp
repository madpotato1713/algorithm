/* CASE1 */
class Solution {
public:
	int compress(vector<char>& chars) {

		char ch = NULL;
		int cnt = 0;
		vector<char> res;

		for (auto c : chars) {
			if (ch == NULL) {
				ch = c;
				res.push_back(c);
				cnt = 1;
			}
			else if (ch != c) {
				ch = c;

				if (cnt > 1) {
					string str = to_string(cnt);
					for (int i = 0; i < str.size(); i++) {
						res.push_back(str[i]);
					}
				}

				res.push_back(c);
				cnt = 1;
			}
			else {
				cnt++;
			}
		}

		if (cnt > 1) {
			string str = to_string(cnt);
			for (int i = 0; i < str.size(); i++) {
				res.push_back(str[i]);
			}
		}

		for (int i = 0; i < res.size(); i++) {
			chars[i] = res[i];
		}

		return res.size();
	}
};

/* CASE2 */
class Solution {
public:
	int compress(vector<char>& chars) {
		if (chars.size() == 0) return 0;

		char ch = chars[0];
		int len = 1, cnt = 1;
		int idx = 1;

		for (int i = 1; i < chars.size(); i++) {
			if (ch != chars[i]) {
				ch = chars[i];

				if (cnt > 1) {
					string str = to_string(cnt);
					for (int j = 0; j < str.size(); j++) {
						chars[idx] = str[j];
						idx++;
						len++;
					}
				}

				chars[idx] = ch;
				idx++;
				len++;

				cnt = 1;
			}
			else {
				cnt++;
			}
		}

		if (cnt > 1) {
			string str = to_string(cnt);
			for (int j = 0; j < str.size(); j++) {
				chars[idx] = str[j];
				idx++;
				len++;
			}
		}

		return len;
	}
};