class Solution {
public:
	int hour[4] = { 1, 2, 4, 8 };
	int min[6] = { 1, 2, 4, 8, 16, 32 };

	vector<string> readBinaryWatch(int num) {
		vector<string> result;

		vector<string> str1;
		vector<string> str2;

		vector<int> v1;
		vector<int> v2;

		for (int n1 = 0; n1 <= num; n1++) {
			int n2 = num - n1;
			solve(str1, v1, n1);
			solve2(str2, v2, n2);

			for (auto s1 : str1) {
				for (auto s2 : str2) {
					result.push_back(s1 + ":" + s2);
				}
			}

			str1.clear();
			str2.clear();
		}

		return result;
	}

	void solve(vector<string>& str1, vector<int>& v1, int cnt) {
		if (cnt == 0) {
			int res = 0;
			for (auto v : v1) {
				res += hour[v];
			}
			if (res < 12)
				str1.push_back(to_string(res));
		}

		int idx = v1.empty() ? 0 : v1.back() + 1;

		for (int i = idx; i < 4; i++) {
			v1.push_back(i);
			solve(str1, v1, cnt - 1);
			v1.pop_back();
		}
	}

	void solve2(vector<string>& str2, vector<int>& v2, int cnt) {
		if (cnt == 0) {
			int res = 0;
			for (auto v : v2) {
				res += min[v];
			}
			if (res < 60) {
				string sres = to_string(res);
				if (sres.size() == 1)
					sres = "0" + sres;
				str2.push_back(sres);
			}
		}

		int idx = v2.empty() ? 0 : v2.back() + 1;

		for (int i = idx; i < 6; i++) {
			v2.push_back(i);
			solve2(str2, v2, cnt - 1);
			v2.pop_back();
		}
	}
};