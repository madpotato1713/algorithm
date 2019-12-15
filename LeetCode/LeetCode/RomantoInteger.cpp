class Solution {
public:
	int romanToInt(string s) {
		unordered_map<char, int> m = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
		int res = 0;
		int prev = 0;
		for (int i = s.size() - 1; i >= 0; i--) {
			int num = m[s[i]];
			if (num < prev) {
				res -= num;
			}
			else {
				res += num;
			}
			prev = num;
		}

		return res;
	}
};